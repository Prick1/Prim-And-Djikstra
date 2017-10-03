//
// Created by wenderson on 29/09/17.
//

#include "graph.h"

Graph::Graph(const char str[]) {
    std::ifstream file(str);
    int value;

    if(file.is_open()) {

        file >> size;
        adjacencyMatrix = new int* [size];

        for(int i = 0; i < size; i++) {
            adjacencyMatrix[i] = new int [size]();
        }

        for(int i = 0; i < size - 1; i++) {
            for(int j = i + 1; j < size; j++) {
                file >> value;
                adjacencyMatrix[i][j] = value;
                adjacencyMatrix[j][i] = value;
            }
        }

        PrintGraph(*this, 4);


    }

}

Graph::Graph(unsigned int sizeIn) {
    size = sizeIn;
    adjacencyMatrix = new int* [size];
    for(int i = 0; i < size; i++) {
        adjacencyMatrix[i] = new int [size]();
    }
}


bool Graph::Compare(void* i, void* j) {

    return ( (Vertex*) i )->ID == ( (Vertex*) j )->ID ? true : false;
}

Graph Graph::Prim(int root) {
    if(root >= 0 && root < size) {




        std::vector<Vertex> vertexes(size);
        for (int i = 0; i < size; i++) {
            vertexes[i].ID = i;
        }

        MinHeap<Vertex> vertexHeap;
        vertexHeap.Insert(vertexes[root], 0);

        for(int i = 0; i < size; i++){
            if(i != root)
                vertexHeap.Insert(vertexes[i], INT_MAX);
        }

        vertexes.clear();

        HeapElement<Vertex>* pSonNode;
        HeapElement<Vertex> fatherNode;

        while( !vertexHeap.Empty() ){

            fatherNode = vertexHeap.Extract();

            for(int i = 0; i < size; i++) {
                if(adjacencyMatrix[fatherNode.element.ID][i] > 0) {

                    int sonNodeHeapIndex = vertexHeap.SearchOnHeap(Vertex(i), pSonNode, Compare);

                    if (sonNodeHeapIndex >= 0 && adjacencyMatrix[fatherNode.element.ID][i] < pSonNode->priority) {
                        pSonNode->element.IDFather = fatherNode.element.ID;

                        vertexHeap.DecreaseKey(sonNodeHeapIndex, adjacencyMatrix[fatherNode.element.ID][i]);
                    }
                }

            }

            vertexes.push_back(fatherNode.element);
        }

        Graph returnGraph(size);

        int j, k;
        std::cout << std::endl;

        for(int i = 0; i < vertexes.size(); i++){

            j = vertexes[i].IDFather;
            k = vertexes[i].ID;
            //std::cout << "Vertex: " << vertexes[i].ID << " Parent: " << vertexes[i].IDFather << std::endl;
            if(j != -1) {
                returnGraph.adjacencyMatrix[j][k] = adjacencyMatrix[j][k];
                returnGraph.adjacencyMatrix[k][j] = adjacencyMatrix[k][j];
            }


        }

        return returnGraph;



    }
    return Graph(1);

}

void PrintGraph(const Graph& g, const int pd){
    int sum = 0;
    for(int i = 0; i < g.Size(); i++) {
        for (int j = 0; j < g.Size(); j++) {
            std::cout << std::fixed << std::setfill('0') << std::setw(pd)
                      << g.adjacencyMatrix[i][j] << " ";
            sum += g.adjacencyMatrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "Sum: " << sum/2 << std::endl;
}

Graph Graph::Dijkstra(int root) {
    if(root >= 0 && root < size) {

        std::vector<Vertex> vertexes(size);
        for (int i = 0; i < size; i++) {
            vertexes[i].ID = i;
        }

        MinHeap<Vertex> vertexHeap;
        vertexHeap.Insert(vertexes[root], 0);

        for(int i = 0; i < size; i++){
            if(i != root)
                vertexHeap.Insert(vertexes[i], INT_MAX);
        }

        vertexes.clear();

        HeapElement<Vertex>* pSonNode;
        HeapElement<Vertex> fatherNode;
        int weight;

        while( !vertexHeap.Empty() ){

            fatherNode = vertexHeap.Extract();

            for(int i = 0; i < size; i++) {
                if(adjacencyMatrix[fatherNode.element.ID][i] > 0) {

                    int sonNodeHeapIndex = vertexHeap.SearchOnHeap(Vertex(i), pSonNode, Compare);

                    if (sonNodeHeapIndex >= 0) {
                        weight = adjacencyMatrix[fatherNode.element.ID][i] + fatherNode.priority;

                        if(weight < pSonNode->priority) {
                            pSonNode->element.IDFather = fatherNode.element.ID;

                            vertexHeap.DecreaseKey(sonNodeHeapIndex, weight);
                        }
                    }
                }

            }

            vertexes.push_back(fatherNode.element);
        }

        Graph returnGraph(size);

        int j, k;
        std::cout << std::endl;

        for(int i = 0; i < vertexes.size(); i++){

            j = vertexes[i].IDFather;
            k = vertexes[i].ID;
            //std::cout << "Vertex: " << vertexes[i].ID << " Parent: " << vertexes[i].IDFather << std::endl;
            if(j != -1) {
                returnGraph.adjacencyMatrix[j][k] = adjacencyMatrix[j][k];
                returnGraph.adjacencyMatrix[k][j] = adjacencyMatrix[k][j];
            }


        }

        return returnGraph;



    }
    return Graph(1);

}

