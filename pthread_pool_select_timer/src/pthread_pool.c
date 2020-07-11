/**************************************************************************
  * @ file    : pthread_pool.c
  * @ author  : syc
  * @ version : 1.0
  * @ date    : 2020.7.10
  * @ brief   : 简单线程池的C语言实现
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "pthread_pool.h"

pthread_key_t key;

//为每个任务执行分发
void *pthread_pool_dispatch(void *argv){
    ushort exit_flag = 0;
    pthread_task_t *a_task;
    pthread_pool_t *a_pool = (pthread_pool_t *)argv;
    if(pthread_setspecific(key, (void *)&exit_flag) != 0) {
        return NULL;
    }
    /*动态从任务列表中获取任务执行*/
    while(!exit_flag) {
        pthread_mutex_lock(&a_pool->mutex);
        //如果此时任务链表为空，则需要等待条件变量为真
        while(a_pool->queue.head == NULL)
		{
            pthread_cond_wait(&a_pool->cond, &a_pool->mutex);
        }
        /*从任务链表中任务开始执行*/
        a_task = a_pool->queue.head;
        a_pool->queue.head = a_task->next;
        a_pool->queue.cur_task_num--;
        if(a_pool->queue.head == NULL)
		{
            a_pool->queue.tail = a_pool->queue.head;
        }
        //解锁
        pthread_mutex_unlock(&a_pool->mutex);
        //执行任务
        a_task->routine(a_task->argv);
        //core
        free(a_task);
        a_task = NULL;
    }
    pthread_exit(0);
}


// 创建线程
static int pthread_pool_create(pthread_pool_t *a_pool){
    if (a_pool == NULL) {
        printf("pthread_pool_create fail: a_pool is NULL\n");
        return -1;
    }

    int i, ret;
    pthread_t tid;
    for(i = 0; i < a_pool->thread_num; i++)
	{
        ret = pthread_create(&tid, NULL, pthread_pool_dispatch, a_pool);
        if (ret == 0) 
		{
            pthread_detach(tid);
        } 
		else 
		{
            printf("pthread_pool_create error %d\n", ret);
        }
    }
    return 0;
}


// 线程退出函数
void pthread_pool_exit_cb(void *argv){
    unsigned int *lock = argv;
    ushort *exit_flag_ptr = pthread_getspecific(key);
    *exit_flag_ptr = 1;
    pthread_setspecific(key, (void *)exit_flag_ptr);
    *lock = 0;
}



//初始化线程池
pthread_pool_t *pthread_pool_init(unsigned int thread_num, unsigned int task_max_num){ 
	pthread_pool_t *a_pool =calloc(1, sizeof(pthread_pool_t));
	 if(!a_pool){
        printf("pool_init calloc fail: %s\n", strerror(errno));
        return NULL;
    }
	 
	a_pool->thread_num = thread_num;
	 
    //初始化队列参数
    a_pool->queue.max_task_num = task_max_num;
    a_pool->queue.cur_task_num = 0;
    a_pool->queue.head = NULL;
    //a_pool->queue.tail = &a_pool->queue.head;
    a_pool->queue.tail = a_pool->queue.head;
	 //初始化tsd
    if(pthread_key_create(&key, NULL) != 0) {
        printf("pthread_key_create fail: %s\n", strerror(errno));
        goto err;
    }

	  //初始化互斥锁
    if(pthread_mutex_init(&a_pool->mutex, NULL) != 0) {
        printf("pthread_mutex_init fail: %s\n", strerror(errno));
        pthread_key_delete(key);
        goto err;
    }
	
    //初始化条件变量
    if(pthread_cond_init(&a_pool->cond, NULL) != 0) {
        printf("pthread_cond_init fail: %s\n", strerror(errno));
        pthread_mutex_destroy(&a_pool->mutex);
        goto err;
    }
    //创建线程池
    if(pthread_pool_create(a_pool) != 0) {
        printf("pthread_pool_create fail: %s\n", strerror(errno));
        pthread_mutex_unlock(&a_pool->mutex);
        pthread_cond_destroy(&a_pool->cond);
        goto err;
    }
    return a_pool;
	
	err:
		free(a_pool);
		return NULL;


}


//往线程池里增加任务，任务最多为task_max_num，超过则添加任务失败

int pthread_pool_add_task(pthread_pool_t *a_pool, void (*routine)(void *), void *argv)
{
    if (a_pool == NULL) {
        printf("pthread_pool_add_task fail: a_pool is NULL\n");
        return -1;
    }
    pthread_task_t *a_task = NULL;
    a_task = (pthread_task_t *)calloc(1, sizeof(pthread_task_t));
    if(!a_task) {
        printf("add task calloc faile: %s\n", strerror(errno));
        return -1;
    }
	
	a_task->routine = routine;
	a_task->argv = argv;
	a_task->next = NULL;
	
    /*加锁*/
    pthread_mutex_lock(&a_pool->mutex);
    if(a_pool->queue.cur_task_num >= a_pool->queue.max_task_num) {
        printf("cur_task_num >= max_task_num\n");
        goto err;
    }
	//将任务放到末尾
	// 初始化时把head的地址赋值给了a_pool->queue.tail，所以当你*的时候实际上是给head赋值
	//*(a_pool->queue.tail) = a_task;
	a_pool->queue.head = a_task;
	a_pool->queue.tail = a_task->next;
	a_pool->queue.cur_task_num++;

	//通知堵塞的线程
	 pthread_cond_signal(&a_pool->cond);    

	//解锁
    	pthread_mutex_unlock(&a_pool->mutex);
	

    return 0;
	
	err:
		pthread_mutex_unlock(&a_pool->mutex);
		free(a_task);
		return -1;


}

//release线程池
void pthread_pool_release(pthread_pool_t *a_pool){
    if (a_pool == NULL) {
        printf("pthread_pool_release fail: a_pool is NULL\n");
        return;
    }
    int n = 0;
    unsigned int lock;

    for(n = 0; n < a_pool->thread_num; n++) {
        lock = 1;
        if(pthread_pool_add_task(a_pool, pthread_pool_exit_cb, &lock) != 0){
            printf("pthread_pool_release fail: add_task fail\n");
            n--;
            sleep(1);
            continue;
        } else {
            printf("pthread_pool_release success\n");
        }
        while(lock) {
            usleep(1);
        }
    }
    pthread_mutex_destroy(&a_pool->mutex);
    pthread_cond_destroy(&a_pool->cond);
    pthread_key_delete(key);
    free(a_pool);
    return;
}

