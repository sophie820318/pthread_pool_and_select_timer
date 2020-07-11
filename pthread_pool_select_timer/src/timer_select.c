/**************************************************************************
  * @ file    : timer_select.c
  * @ author  : syc
  * @ version : 1.0
  * @ date    : 2020.7.11
  * @ brief   : 通过select实现精准定时器
***************************************************************************/
#include <stdio.h>
#include <errno.h>
#include "timer_select.h"

void timer_select(unsigned long sec, enum timer_type type) {
    struct timeval time;
    int err;
    switch (type)
        {
            case SEC:
                time.tv_sec = sec;
                time.tv_usec = 0;
                break;
            case MSEC:
                time.tv_sec = sec / 1000;
                time.tv_usec = (sec % 1000) * 1000;
                break;
            case USEC:
                time.tv_sec = sec / 1000000;
                time.tv_usec = sec % 1000000;
                break;
            default:
                printf("wrong type \n");
                return;
        }
    do {
        err = select(0, NULL, NULL, NULL, &time);
    } while (err < 0 && errno == EINTR);
    return;
}

