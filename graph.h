//
// Created by wenderson on 29/09/17.
//

#ifndef PRIMANDDJIKSTRA_GRAPH_H
#define PRIMANDDJIKSTRA_GRAPH_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include "minheap.tcc"
#include <climits>

class Vertex{
public:
    int ID, IDFather = -1;
    Vertex(int IDin): ID(IDin) {}
    Vertex(){};
};

class Graph {
    friend void PrintGraph(const Graph& g,const int pd);

    int ** adjacencyMatrix;
    unsigned int size;
public:
    Graph(const char str[]);
    Graph(unsigned int sizeIn);
    Graph Prim(int root);
    Graph Dijkstra(int root);
    static bool Compare(void* i, void* j);
    int Size() const {return size;}

};


#endif //PRIMANDDJIKSTRA_GRAPH_H
