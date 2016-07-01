/*
compile:
    g++ -O3 -std=c++11 training.c -o training -lfann -lm

execution:

obs:
if fann dont work, we need link the libraries
 ln -s /usr/local/lib/*fann* /usr/lib/
    
*/
#include "fann.h"

int main()
{
    const unsigned int num_input = 64;
    const unsigned int num_output = 64;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 16;
    const float desired_error = (const float) 0.001;
    const unsigned int max_epochs = 200;
    const unsigned int epochs_between_reports = 1000;

    struct fann *ann = fann_create_standard(num_layers, num_input,
        num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_train_on_file(ann, "inOutJpeg-training.data", max_epochs,
        epochs_between_reports, desired_error);

    fann_save(ann, "inOutJpeg.net");

    fann_destroy(ann);

    return 0;
}