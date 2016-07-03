/*
compile:
	g++ -O3 -std=c++11 execution.c -o execution -lfann -lm -static /home/malfatti/Documents/git/gem5-stable/util/m5/m5op_x86.S  

execution:
    ./build/X86/gem5.fast configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/Documents/git/neuralNetwork-jpeg-benchmark/jpeg-NN-statsGem5/execution
*/
#include <stdio.h>
#include "floatfann.h"
//#include </mnt/gmalfatti/git/gem5-stable/util/m5/m5op.h>
#include </home/malfatti/Documents/git/gem5-stable/util/m5/m5op.h>

int main()
{
    fann_type *calc_out;
    fann_type input[64];

    input[0] = -0.015625; input[1] = 0.015625; input[2] = 0.0195312; input[3] = 0.015625; input[4] = 0.015625;
    input[5] = 0.0195312; input[6] = 0.0117188; input[7] = 0.0234375; input[8] = 0.0234375; input[9] = 0.0195312;
    input[10] = 0.015625; input[11] = 0.0195312; input[12] = 0.0195312; input[13] = 0.015625; input[14] = 0.0195312;
    input[15] = -0.0195312; input[16] = 0.0195312; input[17] = 0.0195312; input[18] = 0.015625;  input[19] = 0.0234375;
    input[20] = 0.0234375; input[21] = 0.0195312; input[22] = 0.0195312; input[23] =-0.0195312; input[24] = 0.015625;
    input[25] = 0.015625; input[26] = 0.0195312; input[27] = 0.015625; input[28] = 0.0195312; input[29] = 0.0234375;
    input[30] = 0.015625; input[31] = -0.0195312; input[32] = 0.015625; input[33] = 0.015625; input[34] = 0.015625;
    input[35] = 0.0195312; input[36] = 0.0195312; input[37] = 0.0234375; input[38] = 0.0195312; input[39] = -0.015625;
    input[40] = 0.015625; input[41] = 0.0273438; input[42] = 0.0195312; input[43] = 0.0195312; input[44] = 0.0195312;
    input[45] = 0.0195312; input[46] = 0.0195312; input[47] = -0.015625; input[48] = 0.0195312; input[49] = 0.0234375;
    input[50] = 0.015625; input[51] = 0.0117188; input[52] = 0.0234375; input[53] = 0.0195312; input[54] = 0.0117188;
    input[55] = -0.015625; input[56] = 0.015625; input[57] = 0.015625; input[58] = 0.0234375; input[59] = 0.0195312;
    input[60] = 0.015625; input[61] = 0.015625; input[62] = 0.0195312; input[63] = 0.0195312;

    
    struct fann *ann = fann_create_from_file("/home/malfatti/Documents/git/neuralNetwork-jpeg-benchmark/jpeg-NN-statsGem5/inOutJpeg.net");
    m5_reset_stats(1,0);
    calc_out = fann_run(ann, input);
    m5_dump_stats(1,0);	

    printf("xor test (%f,%f) -> %f\n", input[0], input[1], calc_out[0]);

    fann_destroy(ann);
    return 0;
}