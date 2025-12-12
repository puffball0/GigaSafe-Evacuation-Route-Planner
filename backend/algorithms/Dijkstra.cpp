#include "Dijkstra.h"
#include <queue>
#include <limits>
#include <algorithm>

DijkstraResult dijkstraWithStates(const Graph& graph, int source, int target) {
    DijkstraResult result;
    const auto& edges = graph.getEdges();
    const auto& nodes = graph.getNodes();
    
    std::unordered_map<int, float> dist;
    std::unordered_map<int, int> parent;
    
    // Initialize distances
    for (const auto& node : nodes) {
        dist[node.id] = std::numeric_limits<float>::max();
        parent[node.id] = -1;
    }
    dist[source] = 0;
    
    // Priority queue: (distance, node)
    std::priority_queue<std::pair<float, int>, 
                        std::vector<std::pair<float, int>>, 
                        std::greater<std::pair<float, int>>> pq;
    pq.push({0.0f, source});
    
    std::unordered_set<int> visited;
    
    // Initial state
    AlgorithmState initialState;
    initialState.currentNode = source;
    initialState.message = "Starting Dijkstra from node " + std::to_string(source) + " with distance 0";
    result.states.push_back(initialState);
    
    while (!pq.empty()) {
        auto [currentDist, current] = pq.top();
        pq.pop();
        
        // Early exit if target found
        if (target != -1 && current == target) {
            visited.insert(current);
            dist[current] = currentDist;
            
            AlgorithmState goalState;
            goalState.currentNode = current;
            goalState.visitedNodes = visited;
            goalState.message = "Target node " + std::to_string(target) + " reached! Distance: " + std::to_string(currentDist);
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
        
        // Copy priority queue state
        auto tempPQ = pq;
        while (!tempPQ.empty()) {
            processingState.queueState.push_back(tempPQ.top().second);
            tempPQ.pop();
        }
        
        processingState.message = "Processing node " + std::to_string(current) + 
                                 " with distance " + std::to_string(currentDist);
        result.states.push_back(processingState);
        
        // Explore neighbors
        for (const auto& edge : edges) {
            int neighbor = -1;
            float weight = edge.distance;
            
            if (edge.from == current) {
                neighbor = edge.to;
            } else if (edge.to == current) {
                neighbor = edge.from;
            } else {
                continue;
            }
            
            if (visited.find(neighbor) != visited.end()) {
                continue;
            }
            
            float newDist = dist[current] + weight;
            
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                parent[neighbor] = current;
                pq.push({newDist, neighbor});
                
                // State: Found better path
                AlgorithmState relaxState;
                relaxState.currentNode = current;
                relaxState.exploringNode = neighbor;
                relaxState.activeEdge = {current, neighbor};
                relaxState.visitedNodes = visited;
                
                relaxState.message = "Relaxed edge to node " + std::to_string(neighbor) + 
                                    ", new distance = " + std::to_string(newDist);
                result.states.push_back(relaxState);
            }
        }
    }
    
    // Final state
    AlgorithmState finalState;
    finalState.currentNode = -1;
    finalState.visitedNodes = visited;
    finalState.message = "Dijkstra Complete! Visited " + std::to_string(visited.size()) + " nodes";
    result.states.push_back(finalState);
    
    result.distances = dist;
    result.parents = parent;
    
    return result;
}

std::unordered_map<int, float> dijkstra(const Graph& graph, int source) {
    DijkstraResult result = dijkstraWithStates(graph, source);
    return result.distances;
}

int findNearestExit(const Graph& graph, int source, float& outDistance) {
    auto dist = dijkstra(graph, source);
    const auto& nodes = graph.getNodes();
    
    int bestExit = -1;
    float bestDist = std::numeric_limits<float>::max();
    
    for (const auto& n : nodes) {
        if (!n.isExit)
            continue;
        
        auto it = dist.find(n.id);
        if (it != dist.end() && it->second < bestDist) {
            bestDist = it->second;
            bestExit = n.id;
        }
    }
    
    outDistance = bestDist;
    return bestExit;
}