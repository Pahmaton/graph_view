#ifndef SET_GRAPH_H
#define SET_GRAPH_H

#include "IGraph.h"
#include <unordered_set>

class SetGraph : public IGraph {
public:
    SetGraph(int vertices_count);
    SetGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> adjacencySets;
};

#endif
