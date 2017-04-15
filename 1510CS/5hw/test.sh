#!/bin/bash

g++ -o heist heist.cpp

if [ "$1" == "g" ];
then
cat sampleinput.txt | valgrind ./a.out;
fi
