#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count) : v_count(vertices_count) {}

ArcGraph::ArcGraph(const IGraph& graph) : v_count(graph.VerticesCount()) {
    for (int i = 0; i < v_count; ++i) {
        for (int next : graph.GetNextVertices(i)) {
            edges.push_back({i, next});
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
    return v_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> next;
    for (const auto& edge : edges) {
        if (edge.from == vertex) next.push_back(edge.to);
    }
    return next;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (const auto& edge : edges) {
        if (edge.to == vertex) prev.push_back(edge.from);
    }
    return prev;
}
