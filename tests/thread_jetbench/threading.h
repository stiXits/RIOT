typedef struct {
   int nTimes;
   int sum;
   double step;
} piLoopBodyArgs; 

typedef struct {
    piLoopBodyArgs * singleThreadArgs;
} multitThreadArgs; 

void createJoinThreads(int nThreads,  void *(*start_routine)(void *), void *arg);
void* piLoopBody(void *args);
double piLoop(int nTimes, int nThreads, double step);
double threadTime(void);
void* threadTimeTest(void * args);
int threadId(void);