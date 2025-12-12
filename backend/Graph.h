#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

struct Node {
    int id;
    std::string name;
    std::string type;
    float x, y, z;
    bool isExit;
    bool isSpecial;
    bool visited;
    
    Node(int id_, std::string name_, std::string type_, float x_, float y_, float z_, 
         bool isExit_, bool isSpecial_) 
        : id(id_), name(name_), type(type_), x(x_), y(y_), z(z_), 
          isExit(isExit_), isSpecial(isSpecial_), visited(false) {}
};

struct Edge {
    int from, to;
    float distance, cost;
    std::string type;
    
    Edge(int from_, int to_, float distance_, float cost_, std::string type_)
        : from(from_), to(to_), distance(distance_), cost(cost_), type(type_) {}
};

class Graph {
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::unordered_map<int, std::vector<int>> adjacencyList;

public:
    Graph() = default;
    
    void addNode(const Node& node);
    void addEdge(int from, int to, float distance, float cost, std::string type);
    
    // Getters
    const std::vector<Node>& getNodes() const { return nodes; }
    const std::vector<Edge>& getEdges() const { return edges; }
    const std::unordered_map<int, std::vector<int>>& getAdjacencyList() const { return adjacencyList; }
    
    // Find shortest path (placeholder - implement A* or Dijkstra as needed)
    std::vector<int> findShortestPath(int start, int end) const;
    
    Node* findNode(int id);
    const Node* findNode(int id) const;
};

#endif // GRAPH_H
