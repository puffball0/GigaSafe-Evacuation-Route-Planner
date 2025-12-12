// #include "visualizer.h"
// #include <iostream>

// void visualizePath(
//     const std::vector<int>& path,
//     const std::string& algorithmName
// ) {
//     std::cout << "\n=== " << algorithmName << " PATH ===\n";

//     if (path.empty()) {
//         std::cout << "No path found.\n";
//         return;
//     }

//     for (size_t i = 0; i < path.size(); i++) {
//         std::cout << path[i];
//         if (i + 1 < path.size())
//             std::cout << " -> ";
//     }
//     std::cout << "\n";
// }

// void visualizeVisited(
//     const std::vector<int>& visited,
//     const std::string& algorithmName
// ) {
//     std::cout << "\n=== " << algorithmName << " VISITED ORDER ===\n";

//     if (visited.empty()) {
//         std::cout << "No visited nodes.\n";
//         return;
//     }

//     for (size_t i = 0; i < visited.size(); i++) {
//         std::cout << visited[i];
//         if (i + 1 < visited.size())
//             std::cout << ", ";
//     }
//     std::cout << "\n";
// }


#include "visualizer.h"
#include <iostream>

// Prints the final path from source to destination
void visualizePath(const std::vector<int>& path, const std::string& algorithmName) {
    std::cout << "\n=== " << algorithmName << " PATH ===\n";
    if (path.empty()) {
        std::cout << "No path found.\n";
        return;
    }
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i + 1 < path.size())
            std::cout << " -> ";
    }
    std::cout << "\n";
}

// Prints the order in which nodes were visited
void visualizeVisited(const std::vector<int>& visited, const std::string& algorithmName) {
    std::cout << "\n=== " << algorithmName << " VISITED ORDER ===\n";
    if (visited.empty()) {
        std::cout << "No visited nodes.\n";
        return;
    }
    for (size_t i = 0; i < visited.size(); i++) {
        std::cout << visited[i];
        if (i + 1 < visited.size())
            std::cout << ", ";
    }
    std::cout << "\n";
}

// Prints the current node being explored and the path so far
void visualizeStep(int currentNode, const std::vector<int>& pathSoFar, const std::string& algorithmName) {
    std::cout << "\n[" << algorithmName << "] Exploring node: " << currentNode << "\n";
    std::cout << "Current path: ";
    if (pathSoFar.empty()) {
        std::cout << "(empty)";
    } else {
        for (size_t i = 0; i < pathSoFar.size(); i++) {
            std::cout << pathSoFar[i];
            if (i + 1 < pathSoFar.size())
                std::cout << " -> ";
        }
    }
    std::cout << "\n";
}
