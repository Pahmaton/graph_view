#include <iostream>
#include <algorithm>
#include <cassert>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

bool AreVectorsEqual(std::vector<int> v1, std::vector<int> v2) {
    if (v1.size() != v2.size()) return false;
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
}

void AssertGraphsEqual(const IGraph& g1, const IGraph& g2) {
    assert(g1.VerticesCount() == g2.VerticesCount());
    for (int i = 0; i < g1.VerticesCount(); ++i) {
        assert(AreVectorsEqual(g1.GetNextVertices(i), g2.GetNextVertices(i)));
        assert(AreVectorsEqual(g1.GetPrevVertices(i), g2.GetPrevVertices(i)));
    }
}

void RunComplexTest() {
    std::cout << "--- Tests ---" << std::endl;
    int v = 6;
    ListGraph listG(v);

    listG.AddEdge(0, 1);
    listG.AddEdge(0, 2);
    listG.AddEdge(0, 0);
    listG.AddEdge(5, 0);
    listG.AddEdge(1, 3);
    listG.AddEdge(2, 3);
    listG.AddEdge(4, 4);

    MatrixGraph matrixG(listG);
    SetGraph setG(matrixG);
    ArcGraph arcG(setG);

    AssertGraphsEqual(listG, matrixG);
    AssertGraphsEqual(matrixG, setG);
    AssertGraphsEqual(setG, arcG);
    AssertGraphsEqual(arcG, listG);

}

void RunEmptyGraphTest() {
    std::cout << "--- Empty Graph Test ---" << std::endl;
    int v = 10;
    ListGraph lg(v);
    MatrixGraph mg(lg);
    
    AssertGraphsEqual(lg, mg);
    for(int i = 0; i < v; ++i) {
        assert(lg.GetNextVertices(i).empty());
        assert(lg.GetPrevVertices(i).empty());
    }
    std::cout << "Empty graph test passed." << std::endl;
}

int main() {
    try {
        RunComplexTest();
        RunEmptyGraphTest();
        
        std::cout << "\n--- All tests passed! ---" << std::endl;
        
        ArcGraph finalGraph(5);
        finalGraph.AddEdge(0, 1);
        finalGraph.AddEdge(0, 4);
        std::cout << "Final check (Next for 0): ";
        for (int n : finalGraph.GetNextVertices(0)) std::cout << n << " ";
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test failed with error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
