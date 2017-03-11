#!/bin/bash

g++ ngem.cpp
cat sampleinput.txt | valgrind ./a.out
cat output.txt
