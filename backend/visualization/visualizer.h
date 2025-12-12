// #pragma once
// #include <vector>
// #include <string>

// void visualizePath(
//     const std::vector<int>& path,
//     const std::string& algorithmName
// );

// void visualizeVisited(
//     const std::vector<int>& visited,
//     const std::string& algorithmName
// );


#pragma once
#include <vector>
#include <string>

// Prints the final path
void visualizePath(
    const std::vector<int>& path,
    const std::string& algorithmName
);

// Prints the order in which nodes were visited
void visualizeVisited(
    const std::vector<int>& visited,
    const std::string& algorithmName
);

// Prints the current node being explored and the path so far
void visualizeStep(
    int currentNode,
    const std::vector<int>& pathSoFar,
    const std::string& algorithmName
);
