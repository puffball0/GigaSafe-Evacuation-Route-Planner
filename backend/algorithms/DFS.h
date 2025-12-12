#ifndef DFS_H
#define DFS_H

#include "../Graph.h"
#include "BFS.h"  // Reuse AlgorithmState structure
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Result structure with full state history
struct DFSResult {
    std::vector<AlgorithmState> states;
    std::unordered_set<int> visitedNodes;
    std::unordered_map<int, int> parents;
};

// DFS with full state tracking
DFSResult dfsWithStates(const Graph& graph, int source, int target = -1);

// Original DFS
std::unordered_set<int> dfs(const Graph& graph, int source);

// Helper: find nearest exit
int findNearestExitDFS(const Graph& graph, int source, int& outDistance);

#endif