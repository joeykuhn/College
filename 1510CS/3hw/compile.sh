#!/bin/bash

g++ ngem.cpp
cat sampleinput.txt | valgrind ./a.out
cat sampleinput.txt | ./a.out > output.txt
diff output.txt | sampleoutput.txt
