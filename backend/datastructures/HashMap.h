#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "../Graph.h"

// Visualization State
struct HashMapState {
    std::string description;
    int currentBucketIndex;
    int insertedNodeId;
    std::string insertedNodeName;
    bool isCollision;
    std::vector<int> chainState; // IDs of nodes in the specific chain being modified
    int stepId;
};

// Node for Chaining
struct HashNode {
    int id;
    std::string name;
    HashNode* next;

    HashNode(int _id, std::string _name) : id(_id), name(_name), next(nullptr) {}
};

class GraphHashMap {
private:
    std::vector<HashNode*> buckets;
    int bucketCount;

    // Hash Function - simple modulo for demonstration
    int hashFunction(int id);

public:
    GraphHashMap(int size = 10);
    ~GraphHashMap();

    // Insert a node and record the steps for visualization
    void insertWithSteps(const Node& node, std::vector<HashMapState>& history, int& stepCounter);

    // Simulate inserting all nodes from a graph and return the full history
    std::vector<HashMapState> simulateInsertion(const std::vector<Node>& nodes);
    
    // Lookup function for fast node retrieval
    HashNode* lookup(int id);
};