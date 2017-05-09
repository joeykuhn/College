#ifndef EDGE_H
#define EDGE_H

class Node;

class Edge{
  public:
    Edge(std::string a, std::string b, int c){
        from = a;
        to = b;
        weight = c;
    }
  
    std::string to;
    std::string from;
    int weight;
};

class Comparator{
    public:
      int operator() (const Edge* e1, const Edge* e2)
      {
          return (e1->weight > e2->weight);
      }
};

#endif