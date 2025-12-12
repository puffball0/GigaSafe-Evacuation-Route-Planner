#include "AStar.h"
#include <queue>
#include <limits>
#include <cmath>
#include <algorithm>

// Heuristic: Euclidean distance
float heuristic(const Node& a, const Node& b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

AStarResult astarWithStates(const Graph& graph, int source, int goal) {
    AStarResult result;
    const auto& edges = graph.getEdges();
    const auto& nodes = graph.getNodes();
    
    // Find goal node
    auto goalNodeIt = std::find_if(nodes.begin(), nodes.end(), 
                                   [goal](const Node& n) { return n.id == goal; });
    if (goalNodeIt == nodes.end()) {
        return result;
    }
    const Node& goalNode = *goalNodeIt;
    
    std::unordered_map<int, float> gScore;  // Cost from start
    std::unordered_map<int, float> fScore;  // Estimated total cost
    std::unordered_map<int, int> parent;
    
    // Initialize
    for (const auto& node : nodes) {
        gScore[node.id] = std::numeric_limits<float>::max();
        fScore[node.id] = std::numeric_limits<float>::max();
        parent[node.id] = -1;
    }
    
    auto sourceNodeIt = std::find_if(nodes.begin(), nodes.end(), 
                                     [source](const Node& n) { return n.id == source; });
    if (sourceNodeIt == nodes.end()) {
        return result;
    }
    
    gScore[source] = 0;
    fScore[source] = heuristic(*sourceNodeIt, goalNode);
    
    // Priority queue: (fScore, node)
    std::priority_queue<std::pair<float, int>, 
                        std::vector<std::pair<float, int>>, 
                        std::greater<std::pair<float, int>>> pq;
    pq.push({fScore[source], source});
    
    std::unordered_set<int> visited;
    
    // Initial state
    AlgorithmState initialState;
    initialState.currentNode = source;
    initialState.message = "Starting A* from node " + std::to_string(source) + 
                          " to goal " + std::to_string(goal);
    result.states.push_back(initialState);
    
    while (!pq.empty()) {
        auto [currentF, current] = pq.top();
        pq.pop();
        
        if (current == goal) {
            // Found goal
            AlgorithmState goalState;
            goalState.currentNode = current;
            goalState.visitedNodes = visited;
            goalState.message = "Goal reached! Node " + std::to_string(goal) + 
                               " at distance " + std::to_string(gScore[goal]);
            result.states.push_back(goalState);
            break;
        }
        
        if (visited.find(current) != visited.end()) {
            continue;
        }
        
        visited.insert(current);
        
        // State: Processing current node
        auto currentNodeIt = std::find_if(nodes.begin(), nodes.end(), 
                                         [current](const Node& n) { return n.id == current; });
        
        AlgorithmState processingState;
        processingState.currentNode = current;
        processingState.visitedNodes = visited;
        
        if (currentNodeIt != nodes.end()) {
            float h = heuristic(*currentNodeIt, goalNode);
            processingState.message = "Processing node " + std::to_string(current) + 
                                     ", g=" + std::to_string(gScore[current]) + 
                                     ", h=" + std::to_string(h) + 
                                     ", f=" + std::to_string(currentF);
        }
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
            
            float tentativeG = gScore[current] + weight;
            
            if (tentativeG < gScore[neighbor]) {
                parent[neighbor] = current;
                gScore[neighbor] = tentativeG;
                
                auto neighborNodeIt = std::find_if(nodes.begin(), nodes.end(), 
                                                   [neighbor](const Node& n) { return n.id == neighbor; });
                if (neighborNodeIt != nodes.end()) {
                    fScore[neighbor] = gScore[neighbor] + heuristic(*neighborNodeIt, goalNode);
                    pq.push({fScore[neighbor], neighbor});
                    
                    // State: Found better path
                    AlgorithmState relaxState;
                    relaxState.currentNode = current;
                    relaxState.exploringNode = neighbor;
                    relaxState.activeEdge = {current, neighbor};
                    relaxState.visitedNodes = visited;
                    
                    relaxState.message = "Updated node " + std::to_string(neighbor) + 
                                        ", new g=" + std::to_string(gScore[neighbor]) + 
                                        ", f=" + std::to_string(fScore[neighbor]);
                    result.states.push_back(relaxState);
                }
            }
        }
    }
    
    // Final state
    AlgorithmState finalState;
    finalState.currentNode = -1;
    finalState.visitedNodes = visited;
    finalState.message = "A* Complete! Explored " + std::to_string(visited.size()) + " nodes";
    result.states.push_back(finalState);
    
    result.distances = gScore;
    result.parents = parent;
    
    return result;
}

std::unordered_map<int, float> astar(const Graph& graph, int source, int goal) {
    AStarResult result = astarWithStates(graph, source, goal);
    return result.distances;
}

int findNearestExitAStar(const Graph& graph, int source, float& outDistance) {
    const auto& nodes = graph.getNodes();
    
    int bestExit = -1;
    float bestDist = std::numeric_limits<float>::max();
    
    for (const auto& n : nodes) {
        if (!n.isExit)
            continue;
        
        auto dist = astar(graph, source, n.id);
        auto it = dist.find(n.id);
        
        if (it != dist.end() && it->second < bestDist) {
            bestDist = it->second;
            bestExit = n.id;
        }
    }
    
    outDistance = bestDist;
    return bestExit;
}