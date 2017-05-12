//////
// Name: Joseph Kuhn
// Teacher: Dr. Taylor
// Section: B
//////

#include <vector>
#include <queue>
#include "node.h"

int findA(std::vector<Node*> vec, std::string val);

int dijkstra(std::vector<Node*> g, int start);

int main(){
   std::string cityName, loc1, loc2;
   int runs, tubes, weight, air, numRuns;

   
   std::cin >> numRuns;
   for (int k = 0; k < numRuns; k++){
     std::cin >> cityName >> runs;
     std::vector<Node*> graph;   
     for (int i = 0; i < runs; i++){
       std::cin >> loc1 >> tubes;
       Node* temp = new Node(loc1);
       graph.push_back(temp);
//       std::cout << "pushed: " << graph.back()->key << std::endl;
       for (int j = 0; j < tubes; j++){
         std::cin >> loc2 >> weight;
         Edge* temp = new Edge(loc1, loc2, weight);
         graph[i]->edges.push_back(temp);
       }
     }
     for (int l = 0; l < graph.size(); l++){
//         std::cout << "graph[" << l << "]: " << graph[l]->key << std::endl;
         if (graph[l]->edges.size() != 0){
//             std::cout << "    edges:" << std::endl;
             for (int m = 0; m < graph[l]->edges.size();m++){
//                 std::cout << "    " << graph[l]->edges[m]->from << " to " << graph[l]->edges[m]->to << std::endl;
             }
         }
     }
     std::cout << "#" << k+1 << " : " << cityName << ", " << dijkstra(graph, findA(graph, "airport")) << " tokens." << std::endl;
   
    for (int i = 0; i < graph.size(); i++){
      for (int j = 0; j < graph[i]->edges.size();j++){
           delete graph[i]->edges[j];
      }
      delete graph[i];
    } 
   }
   

   
    return 0;
}

int dijkstra(std::vector<Node*> g, int start){
    int topweight = 0;
    g[start]->dist = 0;
    
    std::priority_queue<Edge*, std::vector<Edge*>, Comparator> pq;
    
    for (int i = 0; i < g[start]->edges.size(); i++){
//        std::cout << "adding initially: " << g[start]->edges[i]->from << " to " << g[start]->edges[i]->to << std::endl;
        pq.push(g[start]->edges[i]);
        g[findA(g, g[start]->edges[i]->to)]->pi = g[start]->key;
    }
    
    while (pq.top()->to != "robotbar"){
        topweight = pq.top()->weight;
        Node* tope = g[findA(g,pq.top()->to)];
//        std::cout << "Looking at node: " << tope->key << std::endl;
        pq.pop();
        for (int i = 0; i < tope->edges.size(); i++){
            Node* temp = g[findA(g,tope->edges[i]->to)];
            if (temp->dist > topweight + tope->edges[i]->weight || temp->dist == -1){
                temp->dist = topweight + tope->edges[i]->weight;
            }
            tope->edges[i]->weight += topweight;
//            std::cout << "temp is " << temp->key  << ": " << temp->dist << std::endl;
//            std::cout << "adding: " << tope->edges[i]->from << " to " << tope->edges[i]->to << std::endl;
            pq.push(tope->edges[i]);
        }
    }
    if (g[findA(g,"robotbar")]->dist == -1){
        g[findA(g,"robotbar")]->dist = pq.top()->weight;
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