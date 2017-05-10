#!/bin/bash

g++ dijkstra.cpp

valgrind ./a.out < "input.txt"