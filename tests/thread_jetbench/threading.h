#include <inttypes.h>

typedef struct {
   int32_t nTimes;
   int32_t sum;
   double step;
} piLoopBodyArgs; 

typedef struct {
    piLoopBodyArgs * singleThreadArgs;
} multitThreadArgs; 

void createJoinThreads(uint8_t nThreads,  void *(*start_routine)(void *), void *arg);
double threadTime(void);
void* threadTimeTest(void * args);
int threadId(void);