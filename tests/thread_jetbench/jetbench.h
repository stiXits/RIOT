#include<stdio.h>

//Define the number of threads
#define NUM_THREADS 2

#define PRECISION 0.0001

typedef struct {
	FILE *file;
} parallelKernelArgs; 

int benchmark(int enginetype);
double getGama(double temp);
double getCp(double temp);
double getMach(int sub, double corair, double gama1);
double getAir(double mach, double gama2);
double getRayleighLoss(double mach1, double ttrat, double tlow);
void defaultParam(void);
void deduceInputs(void);
void getThermo(void);
void calcPerf(void);
void getGeo(void);
double deg2rad(double deg,double pi);
double sqroot(double numb1er);
double fabs(double x);
double log(double x);
double expo(double x);
double fpow(double x, double y);
double power(double x, int y);
void* parallelKernel(void *args);