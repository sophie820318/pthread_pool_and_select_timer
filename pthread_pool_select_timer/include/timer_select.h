/**************************************************************************
  * @ file    : timer_select.h
  * @ author  : syc
  * @ version : 1.0
  * @ date    : 2020.7.11
  * @ brief   : 通过select实现精准定时器
***************************************************************************/
#ifndef __TIMER_SELECT_H_
#define __TIMER_SELECT_H_

#include <sys/select.h>

#ifdef __cplusplus
extern "C" {
#endif
    enum timer_type {
        SEC=1, MSEC, USEC
    };

    /**
    *  @brief           定时器
    *  @sec             定时的时间
    *  @type            定时的单位SEC(秒级) MSEC(毫秒级别) USEC(微妙级别)
    *  @return:         成功返回pthread_pool_t结构体指针 ,  失败返回null
    */
    void timer_select(unsigned long sec, enum timer_type type);

#ifdef __cplusplus
}
#endif

#endif // __TIMER_SELECT_H_
