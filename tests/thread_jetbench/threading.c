#include "threading.h"

#include <stdio.h>

#include <string.h>
#include <omp.h>

#include "pthread.h"
#include "xtimer.h"

void createJoinThreads(int nThreads,  void *(*start_routine)(void *), void *arg)
{
    multitThreadArgs *multipleArgs = (multitThreadArgs *) arg;

    // char rcv_thread_stack[nThreads][THREAD_STACKSIZE_MAIN];
    pthread_t tId[nThreads];

    for(int i = 0; i < nThreads; i++)
    {
        if(multipleArgs == 0) {
            pthread_create(&tId[i], 0, start_routine, 0);
        }
        else {
            pthread_create(&tId[i], 0, start_routine, (void *) &multipleArgs->singleThreadArgs[i]);
        }
    }

    for(int i = 0; i < nThreads; i++)
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

    for(int i = 0; i < arguments->nTimes; i++)
    {
        x = (i+0.5)*arguments->step;
        arguments->sum += 4.0/(1.0+x*x);
    }

    return NULL;
}

double piLoop(int nTimes, int nThreads, double step)
{
    int nTimesPerThread = nTimes/nThreads;

    piLoopBodyArgs allArguments[nThreads];

    for(int i = 0; i < nThreads; i++)
    {
        piLoopBodyArgs singleArgs;
        singleArgs.step = step;
        singleArgs.nTimes = nTimesPerThread;

        allArguments[i] = singleArgs;
    }

    multitThreadArgs multiArg;
    multiArg.singleThreadArgs = allArguments;

    createJoinThreads(nThreads, piLoopBody, (void *) &multiArg);

    int sumOfAllThreads = 0;
    for(int i = 0; i < nThreads; i++)
    {
        sumOfAllThreads += allArguments[i].sum;
    }

    return sumOfAllThreads * step;
}

void* threadTimeTest(void * args)
{
  double start = threadTime();
  printf("%p\n", args);
  for(int i = 0; i < 100; i++)
  {
    double time = threadTime();
    printf("%f\n", time);
  }

  printf("took: %f\n", threadTime() - start);

  return NULL;
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