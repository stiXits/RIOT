#include "threading.h"

#include <stdio.h>

#include <string.h>
#include <omp.h>

#include "pthread.h"
#include "xtimer.h"

void createJoinThreads(uint8_t nThreads,  void *(*start_routine)(void *), void *arg)
{
    multitThreadArgs_t *multipleArgs = (multitThreadArgs_t *) arg;

    // char rcv_thread_stack[nThreads][THREAD_STACKSIZE_MAIN];
    pthread_t tId[nThreads];

    for(uint8_t i = 0; i < nThreads; i++)
    {
        if(multipleArgs == 0) {
            pthread_create(&tId[i], 0, start_routine, 0);
        }
        else {
            pthread_create(&tId[i], 0, start_routine, (void *) &multipleArgs->singleThreadArgs[i]);
        }
    }

    for(uint8_t i = 0; i < nThreads; i++)
    {
        void* returnValue = 0;
        pthread_join(tId[i], returnValue);
    }
}

double threadTime(void)
{
    double usecs = xtimer_usec_from_ticks(xtimer_now());
    return usecs/1000000;
}

int threadId(void)
{
    return pthread_self();
}