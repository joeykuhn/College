#!/bin/bash

g++ treetester.cpp

./a.out > testoutput.txt
diff testoutput.txt treeoutput.txt
