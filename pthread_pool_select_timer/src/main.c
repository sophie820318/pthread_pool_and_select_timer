/**************************************************************************
  * @ file    : main.c
  * @ author  : syc
  * @ version : 1.0
  * @ date    : 2020.7.11
  * @ brief   : select实现多线程定时器
***************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include "timer_select.h"
#include "pthread_pool.h"

typedef struct argv_s{
    unsigned long time;
    enum timer_type type;
} argv_t;

void func_s(void *argv) {
    if(argv == NULL) {
        return;
    }

    argv_t *sec = (argv_t *)argv;

    timer_select(sec->time, sec->type);
    printf("pthread time_type = %d, time_sec = %d\n", (int)sec->time, (int)sec->type);
    return;
}

int main()
{
    argv_t timer1 = {3, SEC};
    argv_t timer2 = {100, MSEC};
    argv_t timer3 = {10000, USEC};
    pthread_pool_t *pool = pthread_pool_init(5, 10);
    pthread_pool_add_task(pool, func_s, (void *) &timer1);
    pthread_pool_add_task(pool, func_s, (void *) &timer2);
    pthread_pool_add_task(pool, func_s, (void *) &timer3);

    sleep(10);
    pthread_pool_release(pool);
    return 0;

}
