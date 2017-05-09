#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

int findA(std::vector<Node*> vec, std::string val);

int dijkstra(std::vector<Node*> g, int start);

int main(){
   std::cout << "hello" << std::endl;
   std::string cityName, loc1, loc2;
   int runs, tubes, weight, air, numRuns;
   std::vector<Node*> graph;
   
   std::cin >> numRuns;
   for (int k = 0; k < numRuns; k++){
     std::cin >> cityName >> runs;
   
     for (int i = 0; i < runs; i++){
       std::cin >> loc1 >> tubes;
       std::cout << "problem?" <<std::endl;
       Node* temp = new Node(loc1);
       std::cout << "problem?" << std::endl;
       graph.push_back(temp);
       std::cout << "got here" << std::endl;
       std::cout << "pushed: " << graph.back()->key << std::endl;
       for (int j = 0; j < tubes; j++){
         std::cin >> loc2 >> weight;
         Edge* temp = new Edge(loc1, loc2, weight);
         graph[i]->edges.push_back(temp);
         delete temp;
       }
     }
     for (int l = 0; l < graph.size(); l++){
         std::cout << "graph[" << l << "]: " << graph[l]->key << std::endl;
     }
     std::cout << dijkstra(graph, findA(graph, "airport")) << std::endl;
   }
   
   for (int i = 0; i < graph.size(); i++){
       for (int j = 0; j < graph[i]->edges.size();j++){
           delete graph[i]->edges[j];
       }
       delete graph[i];
   }
   
    return 0;
}

int dijkstra(std::vector<Node*> g, int start){
    int topweight = 0;
    g[start]->dist = 0;
    
    std::priority_queue<Edge*, std::vector<Edge*>, Comparator> pq;
    
    for (int i = 0; i < g[start]->edges.size(); i++){
        std::cout << "adding initially: " << g[start]->edges[i]->from << " to " << g[start]->edges[i]->to << std::endl;
        pq.push(g[start]->edges[i]);
        g[findA(g, g[start]->edges[i]->to)]->pi = g[start]->key;
    }
    
    while (pq.top()->to != "robotbar"){
        topweight = pq.top()->weight;
        Node* tope = g[findA(g,pq.top()->to)];
        pq.pop();
        for (int i = 0; i < tope->edges.size(); i++){
            Node* temp = g[findA(g,tope->edges[i]->to)];
            if (temp->dist > topweight + tope->edges[i]->weight){
                temp->dist = topweight + tope->edges[i]->weight;
            }
            tope->edges[i]->weight += topweight;
            std::cout << "adding: " << tope->edges[i]->from << " to " << tope->edges[i]->to << std::endl;
            pq.push(tope->edges[i]);
        }
    }
    
    return g[findA(g,"robotbar")]->dist;
    
}

int findA(std::vector<Node*> vec, std::string val)
{
    for (int i = 0; i < vec.size(); i++){
        if (vec[i]->key == val){
            return i;
        }
    }
    std::cout << val << " could not be found" << std::endl;
    return -1;
}