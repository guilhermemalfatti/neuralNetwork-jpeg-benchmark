#!/bin/bash

#bash to generate data to train the neural network

#>>Utilize o > quando deseja gerar um arquivo de texto:
#Utilize o >> quando precisa gerar um arquivo pelo qual sua sobreescrita seja incremental.
./jpeg ../test.data/input/4.rgb ../test.data/output/out.jpg > /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

#quebra de linha no final do arquivo

./jpeg ../test.data/input/5.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/6.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/7.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/8.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/9.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/10.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/11.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/12.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt

./jpeg ../test.data/input/13.rgb ../test.data/output/out.jpg >> /home/guilherme/malfattiGit/neuralNetwork-jpeg-benchmark/jpeg-NN/inOutJpeg.txt
