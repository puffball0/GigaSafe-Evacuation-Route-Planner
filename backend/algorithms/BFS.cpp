#include "BFS.h"
#include <queue>
#include <limits>

BFSResult bfsWithStates(const Graph& graph, int source, int target) {
    BFSResult result;
    const auto& adj = graph.getAdjacencyList();
    
    std::unordered_map<int, int> dist;
    std::unordered_map<int, int> parent;
    
    // Initialize all distances to -1 (unvisited)
    for (const auto& p : adj) {
        dist[p.first] = -1;
        parent[p.first] = -1;
    }
    
    if (dist.find(source) == dist.end()) {
        return result; // invalid source
    }
    
    std::queue<int> q;
    dist[source] = 0;
    q.push(source);
    
    // Initial state
    AlgorithmState initialState;
    initialState.currentNode = source;
    initialState.queueState = {source};
    initialState.visitedNodes = {source};
    initialState.message = "Starting BFS from node " + std::to_string(source);
    result.states.push_back(initialState);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Early exit if target found
        if (target != -1 && current == target) {
            AlgorithmState goalState;
            goalState.currentNode = current;
            
             // Mark all visited nodes
            for (const auto& p : dist) {
                if (p.second != -1) {
                    goalState.visitedNodes.insert(p.first);
                }
            }
            goalState.message = "Target node " + std::to_string(target) + " reached!";
            result.states.push_back(goalState);
            break;
        }

        // State: Processing current node
        AlgorithmState processingState;
        processingState.currentNode = current;
        
        // Copy queue state
        std::queue<int> tempQ = q;
        while (!tempQ.empty()) {
            processingState.queueState.push_back(tempQ.front());
            tempQ.pop();
        }
        
        // Mark all visited nodes
        for (const auto& p : dist) {
            if (p.second != -1) {
                processingState.visitedNodes.insert(p.first);
            }
        }
        
        processingState.message = "Processing node " + std::to_string(current);
        result.states.push_back(processingState);
        
        // Get neighbors
        auto it = adj.find(current);
        if (it != adj.end()) {
            for (int neighbor : it->second) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[current] + 1;
                    parent[neighbor] = current;
                    q.push(neighbor);
                    
                    // State: Found new neighbor
                    AlgorithmState neighborState;
                    neighborState.currentNode = current;
                    neighborState.exploringNode = neighbor;
                    neighborState.activeEdge = {current, neighbor};
                    
                    // Copy queue state
                    std::queue<int> tempQ2 = q;
                    while (!tempQ2.empty()) {
                        neighborState.queueState.push_back(tempQ2.front());
                        tempQ2.pop();
                    }
                    
                    // Mark visited
                    for (const auto& p : dist) {
                        if (p.second != -1) {
                            neighborState.visitedNodes.insert(p.first);
                        }
                    }
                    
                    neighborState.message = "Found unvisited neighbor " + std::to_string(neighbor) + 
                                           ", distance = " + std::to_string(dist[neighbor]);
                    result.states.push_back(neighborState);

                    // OPTIMIZATION: Stop immediately if target is found (BFS only)
                    if (target != -1 && neighbor == target) {
                        AlgorithmState goalState;
                        goalState.currentNode = neighbor;
                        goalState.visitedNodes = neighborState.visitedNodes;
                        goalState.message = "Target node " + std::to_string(target) + " found!";
                        result.states.push_back(goalState);
                        
                        // CRITICAL FIX: Populate result data before returning
                        result.distances = dist;
                        result.parents = parent;
                        return result;
                    }
                }
            }
        }
    }
    
    // Final state
    AlgorithmState finalState;
    finalState.currentNode = -1;
    for (const auto& p : dist) {
        if (p.second != -1) {
            finalState.visitedNodes.insert(p.first);
        }
    }
    finalState.message = "BFS Complete! Explored " + std::to_string(finalState.visitedNodes.size()) + " nodes";
    result.states.push_back(finalState);
    
    result.distances = dist;
    result.parents = parent;
    
    return result;
}

std::unordered_map<int, int> bfs(const Graph& graph, int source) {
    BFSResult result = bfsWithStates(graph, source);
    return result.distances;
}

int findNearestExitBFS(const Graph& graph, int source, int& outDistance) {
    auto dist = bfs(graph, source);
    const auto& nodes = graph.getNodes();
    
    int bestExit = -1;
    int bestDist = std::numeric_limits<int>::max();
    
    for (const auto& n : nodes) {
        if (!n.isExit)
            continue;
        
        auto it = dist.find(n.id);
        if (it != dist.end() && it->second != -1 && it->second < bestDist) {
            bestDist = it->second;
            bestExit = n.id;
        }
    }
    
    outDistance = bestDist;
    return bestExit;
}