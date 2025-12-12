// /**
//  * Backend Wrapper - Modified to output state-by-state visualization data
//  * Updated by agent to fix JSON output issues
//  */

// #include <iostream>
// #include <string>
// #include <sstream>
// #include <algorithm>
// #include "../backend/Graph.h"
// #include "../backend/algorithms/Dijkstra.h"
// #include "../backend/algorithms/BFS.h"
// #include "../backend/algorithms/DFS.h"
// #include "../backend/algorithms/AStar.h"
// #include "../backend/groundfloor.h"
// #include "../backend/firstfloor.h"
// #include "../backend/secondfloor.h"
// #include "../backend/lowergroundfloor.h"
// #include "../backend/mezzaninefloor.h"
// #include "../backend/floor2a.h"

// // JSON output helper functions
// void outputGraphAsJSON(const Graph& graph) {
//     std::cout << "{\n";
//     std::cout << "  \"nodes\": [\n";
    
//     const auto& nodes = graph.getNodes();
//     for (size_t i = 0; i < nodes.size(); ++i) {
//         const auto& n = nodes[i];
//         std::cout << "    {\n";
//         std::cout << "      \"id\": " << n.id << ",\n";
//         std::cout << "      \"name\": \"" << n.name << "\",\n";
//         std::cout << "      \"type\": \"" << n.type << "\",\n";
//         std::cout << "      \"x\": " << n.x << ",\n";
//         std::cout << "      \"y\": " << n.y << ",\n";
//         std::cout << "      \"floor\": " << n.z << ",\n";
//         std::cout << "      \"isExit\": " << (n.isExit ? "true" : "false") << "\n";
//         std::cout << "    }";
//         if (i < nodes.size() - 1) std::cout << ",";
//         std::cout << "\n";
//     }
    
//     std::cout << "  ],\n";
//     std::cout << "  \"edges\": [\n";
    
//     const auto& edges = graph.getEdges();
//     for (size_t i = 0; i < edges.size(); ++i) {
//         const auto& e = edges[i];
//         std::cout << "    {\n";
//         std::cout << "      \"from\": " << e.from << ",\n";
//         std::cout << "      \"to\": " << e.to << ",\n";
//         std::cout << "      \"distance\": " << e.distance << ",\n";
//         std::cout << "      \"type\": \"" << e.type << "\"\n";
//         std::cout << "    }";
//         if (i < edges.size() - 1) std::cout << ",";
//         std::cout << "\n";
//     }
    
//     std::cout << "  ]\n";
//     std::cout << "}\n";
// }

// void outputAlgorithmStateAsJSON(const AlgorithmState& state, bool isLast) {
//     std::cout << "    {\n";
//     std::cout << "      \"currentNode\": " << state.currentNode << ",\n";
//     std::cout << "      \"exploringNode\": " << state.exploringNode << ",\n";
//     std::cout << "      \"activeEdge\": [" << state.activeEdge.first << ", " << state.activeEdge.second << "],\n";
    
//     std::cout << "      \"queueState\": [";
//     for (size_t i = 0; i < state.queueState.size(); ++i) {
//         std::cout << state.queueState[i];
//         if (i < state.queueState.size() - 1) std::cout << ", ";
//     }
//     std::cout << "],\n";
    
//     std::cout << "      \"visitedNodes\": [";
//     bool first = true;
//     for (int nodeId : state.visitedNodes) {
//         if (!first) std::cout << ", ";
//         std::cout << nodeId;
//         first = false;
//     }
//     std::cout << "],\n";
    
//     std::cout << "      \"message\": \"" << state.message << "\"\n";
//     std::cout << "    }";
//     if (!isLast) std::cout << ",";
//     std::cout << "\n";
// }

// Graph buildFloorGraph(int floorId) {
//     switch (floorId) {
//         case 1: return MezzanineFloor::buildMezzanineFloorGraph();
//         case 2: return LowerGroundFloor::buildLowerGroundFloorGraph();
//         case 3: return GroundFloor::buildGroundFloorGraph();
//         case 4: return FirstFloor::buildFirstFloorGraph();
//         case 5: return SecondFloor::buildSecondFloorGraph();
//         case 6: return Floor2A::buildFloor2AGraph();
//         default:
//             std::cerr << "Invalid floor ID: " << floorId << std::endl;
//             return Graph();
//     }
// }

// #include "../backend/datastructures/HashMap.h"

// // ... (previous includes)

// // Helper to output HashMap history as JSON
// void outputHashMapHistoryAsJSON(const std::vector<HashMapState>& history) {
//     std::cout << "{\n";
//     std::cout << "  \"steps\": [\n";
    
//     for (size_t i = 0; i < history.size(); ++i) {
//         const auto& step = history[i];
//         std::cout << "    {\n";
//         std::cout << "      \"stepId\": " << step.stepId << ",\n";
//         std::cout << "      \"description\": \"" << step.description << "\",\n";
//         std::cout << "      \"currentBucketIndex\": " << step.currentBucketIndex << ",\n";
//         std::cout << "      \"insertedNodeId\": " << step.insertedNodeId << ",\n";
//         std::cout << "      \"insertedNodeName\": \"" << step.insertedNodeName << "\",\n";
//         std::cout << "      \"isCollision\": " << (step.isCollision ? "true" : "false") << ",\n";
//         std::cout << "      \"chainState\": [";
//         for (size_t j = 0; j < step.chainState.size(); ++j) {
//             std::cout << step.chainState[j];
//             if (j < step.chainState.size() - 1) std::cout << ", ";
//         }
//         std::cout << "]\n";
//         std::cout << "    }";
//         if (i < history.size() - 1) std::cout << ",";
//         std::cout << "\n";
//     }
    
//     std::cout << "  ]\n";
//     std::cout << "}\n";
// }

// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << "Usage: " << argv[0] << " <command> [args...]\n";
//         std::cerr << "Commands:\n";
//         std::cerr << "  --get-graph <floorId>                  : Get graph data as JSON\n";
//         std::cerr << "  --compute-route <floorId> <startNode> <algorithm> : Compute route with states\n";
//         std::cerr << "  --visualize-hashmap <floorId>          : Visualize HashMap insertion steps\n";
//         return 1;
//     }

//     std::string command = argv[1];

//     // Command: Get graph data
//     if (command == "--get-graph") {
//         if (argc < 3) {
//             std::cerr << "Error: Missing floor ID\n";
//             return 1;
//         }

//         int floorId = std::stoi(argv[2]);
//         Graph graph = buildFloorGraph(floorId);
        
//         if (graph.getNodes().empty()) {
//             std::cerr << "Error: Failed to build graph for floor " << floorId << "\n";
//             return 1;
//         }

//         outputGraphAsJSON(graph);
//         return 0;
//     }

//     // Command: Visualize HashMap
//     if (command == "--visualize-hashmap") {
//         if (argc < 3) {
//             std::cerr << "Error: Missing floor ID\n";
//             return 1;
//         }

//         int floorId = std::stoi(argv[2]);
//         Graph graph = buildFloorGraph(floorId);
        
//         if (graph.getNodes().empty()) {
//             std::cerr << "Error: Failed to build graph for floor " << floorId << "\n";
//             return 1;
//         }

//         // Initialize HashMap (size 10 for demo purposes, as per user requirement to show collisions)
//         GraphHashMap hashMap(10); 
//         auto history = hashMap.simulateInsertion(graph.getNodes());
        
//         outputHashMapHistoryAsJSON(history);
//         return 0;
//     }

//     // Command: Compute evacuation route with state tracking
//     if (command == "--compute-route") {
//         // ... (rest of the code is same as before)
//         if (argc < 5) {
//              std::cerr << "Error: Missing parameters\n";
//              return 1;
//         }

//         int floorId = std::stoi(argv[2]);
//         int startNodeId = std::stoi(argv[3]);
//         std::string algorithm = argv[4];
//         std::cerr << "DEBUG: C++ Backend received algorithm: '" << algorithm << "'" << std::endl;

//         Graph graph = buildFloorGraph(floorId);
        
//         if (graph.getNodes().empty()) {
//             std::cerr << "Error: Failed to build graph for floor " << floorId << "\n";
//             return 1;
//         }

//         // Find nearest exit
//         float distanceToExit;
//         int exitId = -1;
        
//         if (algorithm == "bfs") {
//             int dist;
//             exitId = findNearestExitBFS(graph, startNodeId, dist);
//             distanceToExit = static_cast<float>(dist);
//         } else if (algorithm == "dfs") {
//             int dist;
//             exitId = findNearestExitDFS(graph, startNodeId, dist);
//             distanceToExit = static_cast<float>(dist);
//         } else if (algorithm == "astar") {
//             exitId = findNearestExitAStar(graph, startNodeId, distanceToExit);
//         } else {
//             exitId = findNearestExit(graph, startNodeId, distanceToExit);
//         }

//         if (exitId == -1) {
//             std::cerr << "Error: No reachable exit from node " << startNodeId << "\n";
//             return 1;
//         }

//         // Run algorithm with state tracking
//         std::vector<AlgorithmState> states;
//         std::vector<int> path;
        
//         if (algorithm == "dijkstra") {
//             DijkstraResult result = dijkstraWithStates(graph, startNodeId, exitId);
//             states = result.states;
            
//             // Reconstruct path
//             int current = exitId;
//             while (current != -1 && current != startNodeId) {
//                 path.push_back(current);
//                 current = result.parents[current];
//             }
//             path.push_back(startNodeId);
//             std::reverse(path.begin(), path.end());
            
//         } else if (algorithm == "bfs") {
//             BFSResult result = bfsWithStates(graph, startNodeId, exitId);
//             states = result.states;
            
//             // Reconstruct path
//             int current = exitId;
//             while (current != -1 && current != startNodeId) {
//                 path.push_back(current);
//                 current = result.parents[current];
//             }
//             path.push_back(startNodeId);
//             std::reverse(path.begin(), path.end());
            
//         } else if (algorithm == "dfs") {
//             DFSResult result = dfsWithStates(graph, startNodeId, exitId);
//             states = result.states;
            
//             // Reconstruct path from parents
//             int current = exitId;
//             while (current != -1 && current != startNodeId) {
//                 path.push_back(current);
//                 current = result.parents[current];
//             }
//             path.push_back(startNodeId);
//             std::reverse(path.begin(), path.end());
            
//         } else if (algorithm == "astar") {
//             AStarResult result = astarWithStates(graph, startNodeId, exitId);
//             states = result.states;
            
//             // Reconstruct path
//             int current = exitId;
//             while (current != -1 && current != startNodeId) {
//                 path.push_back(current);
//                 current = result.parents[current];
//             }
//             path.push_back(startNodeId);
//             std::reverse(path.begin(), path.end());
//         }

//         // Output JSON result
//         std::cout << "{\n";
//         std::cout << "  \"startNodeId\": " << startNodeId << ",\n";
//         std::cout << "  \"exitId\": " << exitId << ",\n";
//         std::cout << "  \"distance\": " << distanceToExit << ",\n";
//         std::cout << "  \"algorithm\": \"" << algorithm << "\",\n";
        
//         std::cout << "  \"path\": [";
//         for (size_t i = 0; i < path.size(); ++i) {
//             std::cout << path[i];
//             if (i < path.size() - 1) std::cout << ", ";
//         }
//         std::cout << "],\n";
        
//         std::cout << "  \"states\": [\n";
//         for (size_t i = 0; i < states.size(); ++i) {
//             outputAlgorithmStateAsJSON(states[i], i == states.size() - 1);
//         }
//         std::cout << "  ]\n";
        
//         std::cout << "}\n";

//         return 0;
//     }

//     std::cerr << "Error: Unknown command '" << command << "'\n";
//     return 1;
// }


// /**
//  * Backend Wrapper - Modified to output state-by-state visualization data
//  * Updated by agent to fix JSON output issues
//  */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include "../backend/Graph.h"
#include "../backend/algorithms/Dijkstra.h"
#include "../backend/algorithms/BFS.h"
#include "../backend/algorithms/DFS.h"
#include "../backend/algorithms/AStar.h"
#include "../backend/datastructures/HashMap.h" // Include the HashMap
#include "../backend/groundfloor.h"
#include "../backend/firstfloor.h"
#include "../backend/secondfloor.h"
#include "../backend/lowergroundfloor.h"
#include "../backend/mezzaninefloor.h"
#include "../backend/floor2a.h"

// Helper to get graph based on floor ID
Graph getGraphByFloorId(int floorId) {
    switch (floorId) {
        case 1: return MezzanineFloor::buildMezzanineFloorGraph();
        case 2: return LowerGroundFloor::buildLowerGroundFloorGraph();
        case 3: return GroundFloor::buildGroundFloorGraph();
        case 4: return FirstFloor::buildFirstFloorGraph();
        case 5: return SecondFloor::buildSecondFloorGraph();
        case 6: return Floor2A::buildFloor2AGraph();
        default: return Graph(); // Empty graph
    }
}

// JSON output helper functions
void outputGraphAsJSON(const Graph& graph) {
    std::cout << "{\n";
    std::cout << "  \"nodes\": [\n";
    
    const auto& nodes = graph.getNodes();
    for (size_t i = 0; i < nodes.size(); ++i) {
        const auto& n = nodes[i];
        std::cout << "    {\n";
        std::cout << "      \"id\": " << n.id << ",\n";
        std::cout << "      \"name\": \"" << n.name << "\",\n";
        std::cout << "      \"type\": \"" << n.type << "\",\n";
        std::cout << "      \"x\": " << n.x << ",\n";
        std::cout << "      \"y\": " << n.y << ",\n";
        std::cout << "      \"floor\": " << n.floor << ",\n";
        std::cout << "      \"isExit\": " << (n.isExit ? "true" : "false") << "\n";
        std::cout << "    }";
        if (i < nodes.size() - 1) std::cout << ",";
        std::cout << "\n";
    }
    std::cout << "  ],\n";

    std::cout << "  \"edges\": [\n";
    const auto& edges = graph.getEdges();
    for (size_t i = 0; i < edges.size(); ++i) {
        const auto& e = edges[i];
        std::cout << "    {\n";
        std::cout << "      \"from\": " << e.from << ",\n";
        std::cout << "      \"to\": " << e.to << ",\n";
        std::cout << "      \"distance\": " << e.distance << ",\n";
        std::cout << "      \"type\": \"" << e.type << "\"\n";
        std::cout << "    }";
        if (i < edges.size() - 1) std::cout << ",";
        std::cout << "\n";
    }
    std::cout << "  ]\n";
    std::cout << "}\n";
}

void outputHashMapStepsAsJSON(const std::vector<HashMapState>& steps, const Graph& graph) {
    std::cout << "{\n";
    std::cout << "  \"totalNodes\": " << graph.getNodes().size() << ",\n";
    std::cout << "  \"bucketCount\": " << 10 << ",\n"; // Assuming a fixed 10 buckets as in HashMap.cpp
    std::cout << "  \"steps\": [\n";

    // Map Node IDs to names for easy lookup in the frontend
    std::map<int, std::string> nodeNames;
    for (const auto& node : graph.getNodes()) {
        nodeNames[node.id] = node.name;
    }

    for (size_t i = 0; i < steps.size(); ++i) {
        const auto& s = steps[i];
        std::cout << "    {\n";
        std::cout << "      \"stepId\": " << s.stepId << ",\n";
        std::cout << "      \"description\": \"" << s.description << "\",\n";
        std::cout << "      \"currentBucketIndex\": " << s.currentBucketIndex << ",\n";
        std::cout << "      \"insertedNodeId\": " << s.insertedNodeId << ",\n";
        std::cout << "      \"insertedNodeName\": \"" << s.insertedNodeName << "\",\n";
        std::cout << "      \"isCollision\": " << (s.isCollision ? "true" : "false") << ",\n";

        std::cout << "      \"chainState\": [\n";
        for (size_t j = 0; j < s.chainState.size(); ++j) {
            int nodeId = s.chainState[j];
            std::string nodeName = nodeNames.count(nodeId) ? nodeNames.at(nodeId) : "Unknown";
            std::cout << "        {\"id\": " << nodeId << ", \"name\": \"" << nodeName << "\"}";
            if (j < s.chainState.size() - 1) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << "      ]\n";
        std::cout << "    }";
        if (i < steps.size() - 1) std::cout << ",";
        std::cout << "\n";
    }

    std::cout << "  ]\n";
    std::cout << "}\n";
}


void outputAlgorithmStepsAsJSON(const std::vector<AlgorithmState>& states) {
    std::cout << "  \"states\": [\n";
    for (size_t i = 0; i < states.size(); ++i) {
        const auto& s = states[i];
        std::cout << "    {\n";
        std::cout << "      \"stepId\": " << s.stepId << ",\n";
        std::cout << "      \"currentNodeId\": " << s.currentNodeId << ",\n";
        std::cout << "      \"currentDistance\": " << s.currentDistance << ",\n";
        std::cout << "      \"newState\": [";
        for (size_t j = 0; j < s.newState.size(); ++j) {
            std::cout << s.newState[j];
            if (j < s.newState.size() - 1) std::cout << ", ";
        }
        std::cout << "],\n";
        std::cout << "      \"visitedNodes\": [";
        for (size_t j = 0; j < s.visitedNodes.size(); ++j) {
            std::cout << s.visitedNodes[j];
            if (j < s.visitedNodes.size() - 1) std::cout << ", ";
        }
        std::cout << "],\n";
        std::cout << "      \"message\": \"" << s.message << "\"\n";
        std::cout << "    }";
        if (i < states.size() - 1) std::cout << ",";
        std::cout << "\n";
    }
    std::cout << "  ]\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " --command [args...]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "--get-graph" && argc == 3) {
        int floorId = std::stoi(argv[2]);
        Graph graph = getGraphByFloorId(floorId);
        outputGraphAsJSON(graph);
    } else if (command == "--compute-route" && argc == 5) {
        int floorId = std::stoi(argv[2]);
        int startNodeId = std::stoi(argv[3]);
        std::string algorithm = argv[4];

        Graph graph = getGraphByFloorId(floorId);
        float distanceToExit = 0.0f;
        std::vector<int> path;
        std::vector<AlgorithmState> states;
        int exitId = -1;
        
        // Find closest exit
        std::map<int, int> parents;
        if (algorithm == "dijkstra" || algorithm == "astar") {
            int closestExitId = -1;
            float minDistance = std::numeric_limits<float>::max();
            
            for (const auto& node : graph.getNodes()) {
                if (node.isExit) {
                    float dist;
                    std::map<int, int> currentParents;
                    if (algorithm == "dijkstra") {
                        DijkstraResult result = dijkstra(graph, startNodeId, node.id);
                        dist = result.distance;
                        currentParents = result.parents;
                    } else { // astar
                        AStarResult result = astar(graph, startNodeId, node.id);
                        dist = result.distance;
                        currentParents = result.parents;
                    }

                    if (dist != -1 && dist < minDistance) {
                        minDistance = dist;
                        closestExitId = node.id;
                        parents = currentParents;
                    }
                }
            }
            
            if (closestExitId != -1) {
                exitId = closestExitId;
                distanceToExit = minDistance;
                
                // Reconstruct path
                int current = exitId;
                while (current != -1 && current != startNodeId) {
                    path.push_back(current);
                    current = parents[current];
                }
                path.push_back(startNodeId);
                std::reverse(path.begin(), path.end());
            }

            // Re-run the algorithm to capture the states for visualization
            if (exitId != -1) {
                if (algorithm == "dijkstra") {
                    DijkstraResult result = dijkstraWithStates(graph, startNodeId, exitId);
                    states = result.states;
                } else { // astar
                    AStarResult result = astarWithStates(graph, startNodeId, exitId);
                    states = result.states;
                }
            }

        } else if (algorithm == "bfs") {
            BFSResult result = bfsWithStates(graph, startNodeId);
            states = result.states;

            // BFS finds the *closest* exit in terms of number of edges (shortest path in unweighted graph)
            int closestExitId = -1;
            int minEdges = std::numeric_limits<int>::max();
            for (const auto& node : graph.getNodes()) {
                if (node.isExit) {
                    int edges = 0;
                    int current = node.id;
                    while (current != -1 && current != startNodeId) {
                        current = result.parents[current];
                        edges++;
                    }
                    if (current == startNodeId && edges < minEdges) {
                        minEdges = edges;
                        closestExitId = node.id;
                        parents = result.parents;
                    }
                }
            }

            if (closestExitId != -1) {
                exitId = closestExitId;
                distanceToExit = (float)minEdges; // Use edge count as 'distance' for BFS
                
                // Reconstruct path
                int current = exitId;
                while (current != -1 && current != startNodeId) {
                    path.push_back(current);
                    current = parents[current];
                }
                path.push_back(startNodeId);
                std::reverse(path.begin(), path.end());
            }
        }
        
        // Output JSON result
        std::cout << "{\n";
        std::cout << "  \"startNodeId\": " << startNodeId << ",\n";
        std::cout << "  \"exitId\": " << exitId << ",\n";
        std::cout << "  \"distance\": " << distanceToExit << ",\n";
        std::cout << "  \"algorithm\": \"" << algorithm << "\",\n";
        
        std::cout << "  \"path\": [";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) std::cout << ", ";
        }
        std::cout << "],\n";
        
        outputAlgorithmStepsAsJSON(states);

        std::cout << "}\n";

    } else if (command == "--visualize-hashmap" && argc == 3) {
        int floorId = std::stoi(argv[2]);
        Graph graph = getGraphByFloorId(floorId);
        
        // Simulate hash map insertion
        GraphHashMap hashMap(10); // Use 10 buckets for visualization
        std::vector<HashMapState> steps = hashMap.simulateInsertion(graph.getNodes());
        
        outputHashMapStepsAsJSON(steps, graph);

    } else {
        std::cerr << "Invalid command or arguments.\n";
        return 1;
    }

    return 0;
}