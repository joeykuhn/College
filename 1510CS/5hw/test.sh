#!/bin/bash

g++ -o heist heist.cpp

if [ "$1" == "g" ];
then
cat sampleinput.txt | ./heist > myoutput.txt
diff myoutput.txt sampleoutput.txt;
fi
