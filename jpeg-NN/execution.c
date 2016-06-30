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
    fann_type input[64];

    struct fann *ann = fann_create_from_file("inOutJpeg.net");
    input[64] = (-0.015625, -0.015625, -0.0195312, -0.015625, -0.015625, -0.0195312, -0.0117188, -0.0234375, -0.0234375, -0.0195312, -0.015625, -0.0195312, -0.0195312, -0.015625, -0.0195312, -0.0195312, -0.0195312, -0.0195312, -0.015625, -0.0234375, -0.0234375, -0.0195312, -0.0195312, -0.0195312, -0.015625, -0.015625, -0.0195312, -0.015625, -0.0195312, -0.0234375, -0.015625, -0.0195312, -0.015625, -0.015625, -0.015625, -0.0195312, -0.0195312, -0.0234375, -0.0195312, -0.015625, -0.015625, -0.0273438, -0.0195312, -0.0195312, -0.0195312, -0.0195312, -0.0195312, -0.015625, -0.0195312, -0.0234375, -0.015625, -0.0117188, -0.0234375, -0.0195312, -0.0117188, -0.015625, -0.015625, -0.015625, -0.0234375, -0.0195312, -0.015625, -0.015625, -0.0195312, -0.0195312);
    calc_out = fann_run(ann, input);

    printf("xor test (%f,%f) -> %f\n", input[0], input[1], calc_out[0]);

    fann_destroy(ann);
    return 0;
}