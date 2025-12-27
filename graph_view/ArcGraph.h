#ifndef ARC_GRAPH_H
#define ARC_GRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph {
public:
    ArcGraph(int vertices_count);
    ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    struct Edge {
        int from, to;
    };
    std::vector<Edge> edges;
    int v_count;
};

#endif
