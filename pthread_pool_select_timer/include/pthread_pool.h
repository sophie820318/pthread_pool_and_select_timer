/**************************************************************************
  * @ file    : pthread_pool.h
  * @ author  : syc
  * @ version : 1.0
  * @ date    : 2020.7.11
  * @ brief   : 简单的C语言线程池的实现
***************************************************************************/
#ifndef _PTHREAD_POOT_H_
#define _PTHREAD_POOT_H_

#include <pthread.h>

#ifdef _cplusplus
extern "C"{
#endif

	/*任务链表，代表一个任务，任务的参数，和指向下一个任务的指针地址*/
	typedef struct task_s{
		void (*routine)(void *);
		void * argv;
		struct task_s *next;
	}pthread_task_t;

	/*任务队列，包括头，尾，容量和当前任务指针*/
	typedef struct queue_s{
		pthread_task_t *head;
		pthread_task_t *tail;
		unsigned int max_task_num;
		unsigned int cur_task_num;
		}pthread_queue_t;

	/*线程池，*/
	typedef struct pool_s{
		/* 线程池互斥锁*/
		pthread_mutex_t mutex;
		/* 条件变量*/
		pthread_cond_t cond;
		/*线程池队列*/
		pthread_queue_t queue;
		/*这个该不该要呢，线程的实际数量*/
		unsigned int thread_num;
		}pthread_pool_t;

		
	/**
	* @brief 初始化线程池
	* @thread_num 开启最大线程数
	* @task_max_num 线程最大任务数
	* @return 成功返回pthread_pool_t 结构体指针，失败返回null
	*/
	pthread_pool_t *pthread_pool_init(unsigned int thread_num,unsigned int task_max_num);

	
   	 /**
    	*  @brief           release线程池
    	*  @a_pool          线程池结构体指针
    	*  @return:         void
    	*/
     	void pthread_pool_release(pthread_pool_t *a_pool);

	 /**
	 *	@brief		往线程池里增加任务，任务最大为task_max_num，超过则添加任务失败
	 *	@a_pool 		线程池结构体指针
	 *	@routine		 回调函数，任务执行函数
	 *	@argv		 回调函数的参数
	 *	@return:		 成功返回0 ,  失败返回-1
	 */
	 int pthread_pool_add_task(pthread_pool_t *a_pool, void (*routine)(void *), void *argv);



#ifdef __cplusplus
}
#endif

#endif // __PTHREAD_POOL_H_



