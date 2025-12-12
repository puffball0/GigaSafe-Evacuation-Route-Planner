#ifndef BFS_H
#define BFS_H

#include "../Graph.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

// Structure to represent algorithm state at each step
struct AlgorithmState {
    int currentNode = -1;                    // Node being processed
    int exploringNode = -1;                  // Node being explored (neighbor)
    std::pair<int, int> activeEdge = {-1, -1}; // Edge being explored
    std::vector<int> queueState;             // Current queue/stack state
    std::unordered_set<int> visitedNodes;    // All visited nodes
    std::string message;                     // Description of current step
};

// Result structure with full state history
struct BFSResult {
    std::vector<AlgorithmState> states;      // All algorithm states
    std::unordered_map<int, int> distances;  // Final distances
    std::unordered_map<int, int> parents;    // Parent pointers for path reconstruction
};

// BFS with full state tracking
BFSResult bfsWithStates(const Graph& graph, int source, int target = -1);

// Original BFS (returns only distances)
std::unordered_map<int, int> bfs(const Graph& graph, int source);

// Helper: get hop distance to nearest exit node
int findNearestExitBFS(const Graph& graph, int source, int& outDistance);

#endif