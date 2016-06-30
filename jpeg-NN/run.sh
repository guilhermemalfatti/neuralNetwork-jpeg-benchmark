#!/bin/bash

green='\033[0;32m'
nc='\033[0m' # No Color

echo -ne "${green}$f\t"
echo "start training"
echo -ne "${nc}"

g++ -O3 -std=c++11 training.c -o training -lfann -lm

./training

echo -ne "${green}$f\t"
echo "start the execution"
echo -ne "${nc}"
g++ -O3 -std=c++11 execution.c -o execution -lfann -lm

./execution

