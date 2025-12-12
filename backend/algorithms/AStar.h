#ifndef ASTAR_H
#define ASTAR_H

#include "../Graph.h"
#include "BFS.h"  // Reuse AlgorithmState structure
#include <vector>
#include <unordered_map>

// Result structure with full state history
struct AStarResult {
    std::vector<AlgorithmState> states;
    std::unordered_map<int, float> distances;
    std::unordered_map<int, int> parents;
};

// A* with full state tracking
AStarResult astarWithStates(const Graph& graph, int source, int goal);

// Original A*
std::unordered_map<int, float> astar(const Graph& graph, int source, int goal);

// Helper: find nearest exit
int findNearestExitAStar(const Graph& graph, int source, float& outDistance);

#endif