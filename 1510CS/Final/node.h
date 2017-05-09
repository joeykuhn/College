#ifndef NODE_H
#define NODE_H

#include "edge.h"

class Node{
  public:
    Node(std::string value){ 
        pi = "";
        key = value;
        dist = -1;
    }
    int dist;
    std::string key;
    std::string pi;
    std::vector<Edge*> edges;
};

#endif