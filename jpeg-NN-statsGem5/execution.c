/*
compile:
	g++ -O3 -std=c++11 execution.c -o execution -lfann -lm -static /mnt/gmalfatti/git/gem5-stable/util/m5/m5op_x86.S  -fopenmp

execution:

*/
#include <stdio.h>
#include "floatfann.h"
#include </mnt/gmalfatti/git/gem5-stable/util/m5/m5op.h>

int main()
{
    fann_type *calc_out;
    fann_type input[64];

    m5_reset_stats(1,0);
    struct fann *ann = fann_create_from_file("inOutJpeg.net");
    input[64] = (-0.015625, -0.015625, -0.0195312, -0.015625, -0.015625, -0.0195312, -0.0117188, -0.0234375, -0.0234375, -0.0195312, -0.015625, -0.0195312, -0.0195312, -0.015625, -0.0195312, -0.0195312, -0.0195312, -0.0195312, -0.015625, -0.0234375, -0.0234375, -0.0195312, -0.0195312, -0.0195312, -0.015625, -0.015625, -0.0195312, -0.015625, -0.0195312, -0.0234375, -0.015625, -0.0195312, -0.015625, -0.015625, -0.015625, -0.0195312, -0.0195312, -0.0234375, -0.0195312, -0.015625, -0.015625, -0.0273438, -0.0195312, -0.0195312, -0.0195312, -0.0195312, -0.0195312, -0.015625, -0.0195312, -0.0234375, -0.015625, -0.0117188, -0.0234375, -0.0195312, -0.0117188, -0.015625, -0.015625, -0.015625, -0.0234375, -0.0195312, -0.015625, -0.015625, -0.0195312, -0.0195312);
    calc_out = fann_run(ann, input);
    m5_dump_stats(1,0);	

    printf("xor test (%f,%f) -> %f\n", input[0], input[1], calc_out[0]);

    fann_destroy(ann);
    return 0;
}