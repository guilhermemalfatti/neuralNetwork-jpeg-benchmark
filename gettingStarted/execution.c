/*
compile:
	g++ -O3 -std=c++11 execution.c -o execution -lfann -lm

execution:

*/
#include <stdio.h>
#include "floatfann.h"

int main()
{
    fann_type *calc_out;
    fann_type input[2];

    struct fann *ann = fann_create_from_file("xor_float.net");

    input[0] = -1;
    input[1] = 1;
    calc_out = fann_run(ann, input);

    printf("xor test (%f,%f) -> %f\n", input[0], input[1], calc_out[0]);

    fann_destroy(ann);
    return 0;
}