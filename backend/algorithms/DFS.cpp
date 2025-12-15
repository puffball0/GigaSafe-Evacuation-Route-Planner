#include <stack>
#include <algorithm>
#include <cmath>
#include "DFS.h"
#include <iostream>
#include <limits>

DFSResult dfsWithStates(const Graph& graph, int source, int target) {
    DFSResult result;
    const auto& adj = graph.getAdjacencyList();
    
    std::unordered_set<int> visited;
    std::unordered_map<int, int> parent;
    std::stack<int> s;
    
    s.push(source);
    
    // Initial state
    AlgorithmState initialState;
    initialState.currentNode = source;
    initialState.queueState = {source};
    initialState.message = "Starting DFS from node " + std::to_string(source);
    result.states.push_back(initialState);
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        
        // Early exit if target found
        if (target != -1 && current == target) {
            visited.insert(current);
            
            AlgorithmState goalState;
            goalState.currentNode = current;
            goalState.visitedNodes = visited;
            goalState.message = "Target node " + std::to_string(target) + " found!";
            result.states.push_back(goalState);
            break;
        }

        if (visited.find(current) != visited.end()) {
            continue;
        }
        
        visited.insert(current);
        
        // State: Processing current node
        AlgorithmState processingState;
        processingState.currentNode = current;
        processingState.visitedNodes = visited;
        
        // Copy stack state
        std::stack<int> tempS = s;
        std::vector<int> stackVec;
        while (!tempS.empty()) {
            stackVec.push_back(tempS.top());
            tempS.pop();
        }
        processingState.queueState = stackVec;
        
        processingState.message = "Visiting node " + std::to_string(current);
        result.states.push_back(processingState);
        
        // Get neighbors
        auto it = adj.find(current);
        if (it != adj.end()) {
            for (int neighbor : it->second) {
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
                    parent[neighbor] = current;
                    
                    // State: Found new neighbor
                    AlgorithmState neighborState;
                    neighborState.currentNode = current;
                    neighborState.exploringNode = neighbor;
                    neighborState.activeEdge = {current, neighbor};
                    neighborState.visitedNodes = visited;
                    
                    // Copy stack state
                    std::stack<int> tempS2 = s;
                    std::vector<int> stackVec2;
                    while (!tempS2.empty()) {
                        stackVec2.push_back(tempS2.top());
                        tempS2.pop();
                    }
                    neighborState.queueState = stackVec2;
                    
                    neighborState.message = "Found unvisited neighbor " + std::to_string(neighbor) + ", added to stack";
                    result.states.push_back(neighborState);

                    // OPTIMIZATION: Stop immediately if target is found
                    if (target != -1 && neighbor == target) {
                        AlgorithmState goalState;
                        goalState.currentNode = neighbor;
                        goalState.visitedNodes = visited;
                        goalState.visitedNodes.insert(neighbor);
                        goalState.message = "Target node " + std::to_string(target) + " found!";
                        result.states.push_back(goalState);
                        
                        // CRITICAL FIX: Populate result data before returning
                        result.visitedNodes = visited;
                        result.visitedNodes.insert(neighbor);
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
    finalState.visitedNodes = visited;
    finalState.message = "DFS Complete! Explored " + std::to_string(visited.size()) + " nodes";
    result.states.push_back(finalState);
    
    result.visitedNodes = visited;
    result.parents = parent;
    
    return result;
}

std::unordered_set<int> dfs(const Graph& graph, int source) {
    DFSResult result = dfsWithStates(graph, source);
    return result.visitedNodes;
}

int findNearestExitDFS(const Graph& graph, int source, int& outDistance) {
    auto visited = dfs(graph, source);
    const auto& nodes = graph.getNodes();
    
    int bestExit = -1;
    float bestDist = std::numeric_limits<float>::max();
    
    for (const auto& n : nodes) {
        if (!n.isExit || visited.find(n.id) == visited.end())
            continue;
        
        // Calculate Euclidean distance as approximation
        auto sourceNode = std::find_if(nodes.begin(), nodes.end(), 
                                      [source](const Node& node) { return node.id == source; });
        
        if (sourceNode != nodes.end()) {
            float dx = n.x - sourceNode->x;
            float dy = n.y - sourceNode->y;
            float dist = std::sqrt(dx * dx + dy * dy);
            
            if (dist < bestDist) {
                bestDist = dist;
                bestExit = n.id;
            }
        }
    }
    
    outDistance = static_cast<int>(bestDist);
    return bestExit;
}