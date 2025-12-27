#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count) 
    : matrix(vertices_count, std::vector<bool>(vertices_count, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) : MatrixGraph(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int next : graph.GetNextVertices(i)) {
            matrix[i][next] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> next;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i]) next.push_back(i);
    }
    return next;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][vertex]) prev.push_back(i);
    }
    return prev;
}
