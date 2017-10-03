
#include "graph.h"
#include <chrono>

typedef std::chrono::steady_clock Clock;
typedef std::chrono::steady_clock::time_point Time;


int main(int argc, char *argv[]) {
    Graph firstGraph(argv[1]);
    std::cout << "Prim: " << std::endl;
    Time t1 = Clock::now();
    Graph PrimGraph(firstGraph.Prim(0));
    Time t2 = Clock::now();
    PrintGraph(PrimGraph, 4);
    Time t3 = Clock::now();
    Graph DjikstraGraph(firstGraph.Dijkstra(0));
    Time t4 = Clock::now();
    std::cout << "Djikstra: " << std::endl;
    PrintGraph(DjikstraGraph, 4);
    std::cout << "Times: " << std::endl << "Prim: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;
    std::cout << "Djikstra: " << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << std::endl;
    return 0;
}