#include "Graph.h"
#include <algorithm>
#include <queue>
#include <limits>

void Graph::addNode(const Node& node) {
    nodes.push_back(node);
    adjacencyList[node.id] = {};
}

void Graph::addEdge(int from, int to, float distance, float cost, std::string type) {
    edges.push_back(Edge(from, to, distance, cost, type));
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from); // Undirected graph
}

Node* Graph::findNode(int id) {
    for (auto& node : nodes) {
        if (node.id == id) return &node;
    }
    return nullptr;
}

const Node* Graph::findNode(int id) const {
    for (const auto& node : nodes) {
        if (node.id == id) return &node;
    }
    return nullptr;
}

std::vector<int> Graph::findShortestPath(int start, int end) const {
    // Simple BFS implementation (replace with A* for better performance)
    std::vector<int> distances(nodes.size(), -1);
    std::vector<int> previous(nodes.size(), -1);
    std::queue<int> q;
    
    distances[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        if (current == end) break;
        
        for (int neighbor : adjacencyList.at(current)) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                previous[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    // Reconstruct path
    std::vector<int> path;
    for (int at = end; at != -1; at = previous[at]) {
        path.push_back(at);
        if (at == start) break;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

