#include<stdio.h>
#include <inttypes.h>

//Define the number of threads
#define NUM_THREADS 2

#define PRECISION 0.0001

uint8_t benchmark(uint8_t enginetype);
double getGama(double temp);
double getCp(double temp);
double getMach(uint32_t sub, double corair, double gama1);
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
double power(double x, int32_t y);
void* parallelKernel(void *args);