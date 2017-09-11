#!/bin/bash
g++ -g maptester.cpp

echo "












<-----------------------TESTING AREA BEGINS---------------------->
"

./a.out > output.txt

diff output.txt mapoutput.txt
