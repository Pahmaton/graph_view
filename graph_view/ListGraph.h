#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph {
public:
    ListGraph(int vertices_count);
    ListGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif
