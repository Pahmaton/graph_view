#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count) : adjacencySets(vertices_count) {}

SetGraph::SetGraph(const IGraph& graph) : adjacencySets(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int next : graph.GetNextVertices(i)) {
            adjacencySets[i].insert(next);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacencySets.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (int i = 0; i < adjacencySets.size(); ++i) {
        if (adjacencySets[i].count(vertex)) prev.push_back(i);
    }
    return prev;
}
