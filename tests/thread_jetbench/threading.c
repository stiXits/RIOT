#include "threading.h"

#include <stdio.h>

#include <string.h>
#include <omp.h>

#include "pthread.h"
#include "xtimer.h"

void createJoinThreads(uint32_t nThreads,  void *(*start_routine)(void *), void *arg)
{
    multitThreadArgs *multipleArgs = (multitThreadArgs *) arg;

    // char rcv_thread_stack[nThreads][THREAD_STACKSIZE_MAIN];
    pthread_t tId[nThreads];

    for(uint32_t i = 0; i < nThreads; i++)
    {
        if(multipleArgs == 0) {
            pthread_create(&tId[i], 0, start_routine, 0);
        }
        else {
            pthread_create(&tId[i], 0, start_routine, (void *) &multipleArgs->singleThreadArgs[i]);
        }
    }

    for(uint32_t i = 0; i < nThreads; i++)
    {
        void* returnValue = 0;
        pthread_join(tId[i], returnValue);
    }
}

//void piLoopBody(int nTimes, int &x, int &sum, double &x, double step)
void* piLoopBody(void *args)
{
    piLoopBodyArgs *arguments = (piLoopBodyArgs *) args;
    double x;

    for(uint32_t i = 0; i < arguments->nTimes; i++)
    {
        x = (i+0.5)*arguments->step;
        arguments->sum += 4.0/(1.0+x*x);
    }

    return NULL;
}

double piLoop(uint32_t nTimes, uint32_t nThreads, double step)
{
    uint32_t nTimesPerThread = nTimes/nThreads;

    piLoopBodyArgs allArguments[nThreads];

    for(uint32_t i = 0; i < nThreads; i++)
    {
        piLoopBodyArgs singleArgs;
        singleArgs.step = step;
        singleArgs.nTimes = nTimesPerThread;

        allArguments[i] = singleArgs;
    }

    multitThreadArgs multiArg;
    multiArg.singleThreadArgs = allArguments;

    createJoinThreads(nThreads, piLoopBody, (void *) &multiArg);

    uint32_t sumOfAllThreads = 0;
    for(uint32_t i = 0; i < nThreads; i++)
    {
        sumOfAllThreads += allArguments[i].sum;
    }

    return sumOfAllThreads * step;
}

double threadTime(void)
{
    double usecs = xtimer_usec_from_ticks(xtimer_now());
    return usecs/1000000;
}

uint32_t threadId(void)
{
    return pthread_self();
}