#include <stdlib.h>

#include "jetbench.h"

int main(void)
{
    // run turbojet benchmark
    benchmark(1);

    // run turbojet afterburner benchmark
    benchmark(2);

    // run turbofan benchmark
    benchmark(3);

    exit(0);
}