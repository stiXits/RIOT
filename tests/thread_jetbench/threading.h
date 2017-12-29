#include <inttypes.h>

typedef struct {
   int32_t nTimes;
   int32_t sum;
   double step;
} piLoopBodyArgs_t; 

typedef struct {
    piLoopBodyArgs_t * singleThreadArgs;
} multitThreadArgs_t; 

void createJoinThreads(uint8_t nThreads,  void *(*start_routine)(void *), void *arg);
double threadTime(void);
void* threadTimeTest(void * args);
int threadId(void);