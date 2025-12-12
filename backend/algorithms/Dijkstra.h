#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../Graph.h"
#include "BFS.h"  // Reuse AlgorithmState structure
#include <vector>
#include <unordered_map>

// Result structure with full state history
struct DijkstraResult {
    std::vector<AlgorithmState> states;
    std::unordered_map<int, float> distances;
    std::unordered_map<int, int> parents;
};

// Dijkstra with full state tracking
DijkstraResult dijkstraWithStates(const Graph& graph, int source, int target = -1);

// Original Dijkstra
std::unordered_map<int, float> dijkstra(const Graph& graph, int source);

// Helper: find nearest exit
int findNearestExit(const Graph& graph, int source, float& outDistance);

#endif