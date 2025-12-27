#include "ListGraph.h"

ListGraph::ListGraph(int vertices_count) : adjacencyLists(vertices_count) {}

ListGraph::ListGraph(const IGraph& graph) : adjacencyLists(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int next : graph.GetNextVertices(i)) {
            adjacencyLists[i].push_back(next);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(adjacencyLists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (int i = 0; i < adjacencyLists.size(); ++i) {
        for (int neighbor : adjacencyLists[i]) {
            if (neighbor == vertex) prev.push_back(i);
        }
    }
    return prev;
}
