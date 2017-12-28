#include <inttypes.h>

typedef struct {
   uint32_t nTimes;
   uint32_t sum;
   double step;
} piLoopBodyArgs; 

typedef struct {
    piLoopBodyArgs * singleThreadArgs;
} multitThreadArgs; 

void createJoinThreads(uint32_t nThreads,  void *(*start_routine)(void *), void *arg);
void* piLoopBody(void *args);
double piLoop(uint32_t nTimes, uint32_t nThreads, double step);
double threadTime(void);
void* threadTimeTest(void * args);
uint32_t threadId(void);