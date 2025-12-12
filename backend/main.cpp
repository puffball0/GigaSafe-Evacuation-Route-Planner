#include <iostream>
#include <algorithm>
#include "Graph.h"

#include "groundfloor.h"
#include "firstfloor.h"
#include "secondfloor.h"
#include "lowergroundfloor.h"
#include "mezzaninefloor.h"
#include "floor2a.h"

#include "algorithms/Dijkstra.h"
#include "algorithms/BFS.h"
#include "algorithms/DFS.h"
#include "algorithms/AStar.h"
#include "visualization/visualizer.h"

int main() {
    std::cout << "Select floor graph:\n";
    std::cout << "1. Mezzanine floor\n";
    std::cout << "2. Lower ground floor\n";
    std::cout << "3. Ground floor\n";
    std::cout << "4. First floor\n"; 
    std::cout << "5. Second floor\n";
    std::cout << "6. 2A floor\n";

    int choice;
    std::cin >> choice;

    Graph g;

    switch (choice) {
        case 1: g = MezzanineFloor::buildMezzanineFloorGraph(); break;
        case 2: g = LowerGroundFloor::buildLowerGroundFloorGraph(); break;
        case 3: g = GroundFloor::buildGroundFloorGraph(); break;
        case 4: g = FirstFloor::buildFirstFloorGraph(); break;
        case 5: g = SecondFloor::buildSecondFloorGraph(); break;
        case 6: g = Floor2A::buildFloor2AGraph(); break;
        default:
            std::cout << "Invalid choice.\n";
            return 0;
    }

    int sourceId;
    std::cout << "Enter starting node id: ";
    std::cin >> sourceId;

    std::cout << "\nSelect pathfinding algorithm:\n";
    std::cout << "1. Dijkstra (Weighted Shortest Path)\n";
    std::cout << "2. BFS (Unweighted Shortest Path)\n";
    std::cout << "3. DFS (Any Path)\n";
    std::cout << "4. A* (Heuristic Shortest Path)\n";

    int algoChoice;
    std::cin >> algoChoice;

    std::vector<int> path;
    std::vector<int> visitedOrder;
    std::string algoName;

    if (algoChoice == 1) {
        // === DIJKSTRA ===
        algoName = "Dijkstra";
        
        float distanceToExit;
        int exitId = findNearestExit(g, sourceId, distanceToExit);

        if (exitId == -1) {
            std::cout << "No reachable exit from node " << sourceId << ".\n";
            return 0;
        }

        std::cout << "\nNearest exit from node " << sourceId
                  << " is node " << exitId
                  << " at distance " << distanceToExit << ".\n";

        auto dist = dijkstra(g, sourceId);

        // Reconstruct path
        int current = exitId;
        while (current != sourceId) {
            path.push_back(current);

            bool parentFound = false;
            for (const auto& e : g.getEdges()) {
                if (e.to == current && dist[e.from] + e.distance == dist[current]) {
                    current = e.from;
                    parentFound = true;
                    break;
                }
                if (e.from == current && dist[e.to] + e.distance == dist[current]) {
                    current = e.to;
                    parentFound = true;
                    break;
                }
            }

            if (!parentFound) break;
            visitedOrder.push_back(current);
        }
        path.push_back(sourceId);
        std::reverse(path.begin(), path.end());

    } else if (algoChoice == 2) {
        // === BFS ===
        algoName = "BFS";
        
        int distanceToExit;
        int exitId = findNearestExitBFS(g, sourceId, distanceToExit);

        if (exitId == -1) {
            std::cout << "No reachable exit from node " << sourceId << ".\n";
            return 0;
        }

        std::cout << "\nNearest exit from node " << sourceId
                  << " is node " << exitId
                  << " at hop distance " << distanceToExit << ".\n";

        auto dist = bfs(g, sourceId);

        // Reconstruct path
        int current = exitId;
        const auto& adj = g.getAdjacencyList();
        
        while (current != sourceId) {
            path.push_back(current);

            bool parentFound = false;
            auto it = adj.find(current);
            if (it != adj.end()) {
                for (int neighbor : it->second) {
                    if (dist[neighbor] == dist[current] - 1) {
                        current = neighbor;
                        parentFound = true;
                        break;
                    }
                }
            }

            if (!parentFound) break;
            visitedOrder.push_back(current);
        }
        path.push_back(sourceId);
        std::reverse(path.begin(), path.end());

    } else if (algoChoice == 3) {
        // === DFS ===
        algoName = "DFS";
        
        int dist;
        int exitId = findNearestExitDFS(g, sourceId, dist);

        if (exitId == -1) {
            std::cout << "No reachable exit from node " << sourceId << ".\n";
            return 0;
        }

        std::cout << "\nFound exit at node " << exitId 
                  << " (DFS does not guarantee shortest path).\n";

        // For DFS, we do a manual traversal to build a path
        const auto& adj = g.getAdjacencyList();
        std::vector<int> stack;
        std::unordered_map<int, int> parent;
        std::unordered_set<int> visited;

        stack.push_back(sourceId);
        parent[sourceId] = -1;

        bool found = false;
        while (!stack.empty() && !found) {
            int current = stack.back();
            stack.pop_back();

            if (visited.count(current))
                continue;

            visited.insert(current);
            visitedOrder.push_back(current);

            // Check if exit
            for (const auto& n : g.getNodes()) {
                if (n.id == current && n.isExit) {
                    exitId = current;
                    found = true;
                    break;
                }
            }

            if (found) break;

            auto it = adj.find(current);
            if (it != adj.end()) {
                for (int neighbor : it->second) {
                    if (!visited.count(neighbor)) {
                        stack.push_back(neighbor);
                        if (parent.find(neighbor) == parent.end()) {
                            parent[neighbor] = current;
                        }
                    }
                }
            }
        }

        // Reconstruct path from parent map
        int current = exitId;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        std::reverse(path.begin(), path.end());

    } else if (algoChoice == 4) {
        // === A* ===
        algoName = "A*";
        
        float distanceToExit;
        int exitId = findNearestExitAStar(g, sourceId, distanceToExit);

        if (exitId == -1) {
            std::cout << "No reachable exit from node " << sourceId << ".\n";
            return 0;
        }

        std::cout << "\nNearest exit from node " << sourceId
                  << " is node " << exitId
                  << " at distance " << distanceToExit << ".\n";

        auto dist = astar(g, sourceId, exitId);

        // Reconstruct path (same as Dijkstra)
        int current = exitId;
        while (current != sourceId) {
            path.push_back(current);

            bool parentFound = false;
            for (const auto& e : g.getEdges()) {
                if (e.to == current && dist[e.from] + e.distance == dist[current]) {
                    current = e.from;
                    parentFound = true;
                    break;
                }
                if (e.from == current && dist[e.to] + e.distance == dist[current]) {
                    current = e.to;
                    parentFound = true;
                    break;
                }
            }

            if (!parentFound) break;
            visitedOrder.push_back(current);
        }
        path.push_back(sourceId);
        std::reverse(path.begin(), path.end());

    } else {
        std::cout << "Invalid algorithm choice.\n";
        return 0;
    }

    //
    // === Visualization ===
    //
    visualizePath(path, algoName);
    visualizeVisited(visitedOrder, algoName);

    return 0;
}