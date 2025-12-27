#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"


void PrintGraph(const IGraph& graph) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::cout << i << ": ";
        for (int next : graph.GetNextVertices(i)) {
            std::cout << next << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int v = 4;
    ListGraph listG(v);
    listG.AddEdge(0, 1);
    listG.AddEdge(1, 2);
    listG.AddEdge(2, 3);
    listG.AddEdge(3, 0);

    MatrixGraph matrixG(listG);
    SetGraph setG(matrixG);
    ArcGraph arcG(setG);

    std::cout << "--- Results ---" << std::endl;
    PrintGraph(arcG);

    return 0;
}
