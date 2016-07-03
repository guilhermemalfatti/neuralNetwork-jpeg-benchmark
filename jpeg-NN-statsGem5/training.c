/*
compile:
    g++ -O3 -std=c++11 training.c -o training -lfann -lm
    g++ -O3 -std=c++11 training.c -o training -lfann -lm -static /home/malfatti/Documents/git/gem5-stable/util/m5/m5op_x86.S

execution:

obs:
if fann dont work, we need link the libraries
 ln -s /usr/local/lib/*fann* /usr/lib/
    
*/
#include "fann.h"
//#include </mnt/gmalfatti/git/gem5-stable/util/m5/m5op.h>
#include </home/malfatti/Documents/git/gem5-stable/util/m5/m5op.h>

int main()
{
    const unsigned int num_input = 64;
    const unsigned int num_output = 64;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 16;
    const float desired_error = (const float) 0.001;
    const unsigned int max_epochs = 200;
    const unsigned int epochs_between_reports = 1000;
    
    m5_reset_stats(1,0);
    struct fann *ann = fann_create_standard(num_layers, num_input,
        num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    //fann_train_on_file(ann, "/mnt/gmalfatti/git/neuralNetwork-jpeg-benchmark/jpeg-NN-statsGem5/inOutJpeg-training.data", max_epochs,
    fann_train_on_file(ann, "/home/malfatti/Documents/git/neuralNetwork-jpeg-benchmark/jpeg-NN-statsGem5/inOutJpeg-training.data", max_epochs,
        epochs_between_reports, desired_error);

    //fann_save(ann, "/mnt/gmalfatti/git/neuralNetwork-jpeg-benchmark/jpeg-NN-statsGem5/inOutJpeg.net");
    fann_save(ann, "/home/malfatti/Documents/git/neuralNetwork-jpeg-benchmark/jpeg-NN-statsGem5/inOutJpeg.net");
    m5_dump_stats(1,0); 

    fann_destroy(ann);

    return 0;
}