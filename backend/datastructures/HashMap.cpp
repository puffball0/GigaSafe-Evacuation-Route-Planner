#include "HashMap.h"

GraphHashMap::GraphHashMap(int size) : bucketCount(size) {
    buckets.resize(size, nullptr);
}

GraphHashMap::~GraphHashMap() {
    for (int i = 0; i < bucketCount; ++i) {
        HashNode* current = buckets[i];
        while (current != nullptr) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int GraphHashMap::hashFunction(int id) {
    // A simple, deterministic hash function for visualization
    return id % bucketCount;
}

void GraphHashMap::insertWithSteps(const Node& node, std::vector<HashMapState>& history, int& stepCounter) {
    int index = hashFunction(node.id);

    // Step 1: Calculate Hash
    HashMapState hashStep;
    hashStep.stepId = stepCounter++;
    hashStep.insertedNodeId = node.id;
    hashStep.insertedNodeName = node.name;
    hashStep.currentBucketIndex = index;
    hashStep.isCollision = false;
    hashStep.description = "Computing hash: " + std::to_string(node.id) + " % " + std::to_string(bucketCount) + " = " + std::to_string(index);
    history.push_back(hashStep);

    // Get the current chain state for the *next* step (Pre-Insertion)
    std::vector<ChainLink> initialChainState; // MODIFIED: Use ChainLink
    HashNode* temp = buckets[index];
    while (temp) {
        initialChainState.push_back({temp->id, temp->name}); // MODIFIED: Push ChainLink object
        temp = temp->next;
    }

    // Step 2: Check Bucket (Pre-Insertion State)
    HashMapState checkStep = hashStep; // Copy base info from hashStep
    checkStep.stepId = stepCounter++;
    checkStep.chainState = initialChainState; // State of chain *before* insertion
    checkStep.isCollision = (buckets[index] != nullptr); // Collision if bucket is not empty
    
    HashNode* newNode = new HashNode(node.id, node.name);

    if (buckets[index] == nullptr) {
        // No Collision
        checkStep.description = "Bucket " + std::to_string(index) + " is empty. Inserting " + node.name + ".";
        history.push_back(checkStep);

        // Actual insertion
        buckets[index] = newNode;
    } else {
        // Collision
        checkStep.description = "Collision detected at bucket " + std::to_string(index) + ". " + node.name + " is chained.";
        history.push_back(checkStep);

        // Actual insertion (Add to head of chain)
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    // Step 3: Show updated chain (Post-Insertion State)
    HashMapState linkedStep = checkStep; // Copy base info from checkStep
    linkedStep.stepId = stepCounter++;
    
    // Capture new chain after insertion
    linkedStep.chainState.clear();
    temp = buckets[index];
    while (temp) {
        linkedStep.chainState.push_back({temp->id, temp->name}); // MODIFIED: Push ChainLink object
        temp = temp->next;
    }
    linkedStep.description = "Result: " + node.name + " successfully inserted into bucket " + std::to_string(index) + ".";
    history.push_back(linkedStep);
}

std::vector<HashMapState> GraphHashMap::simulateInsertion(const std::vector<Node>& nodes) {
    std::vector<HashMapState> history;
    int stepCounter = 0;

    // Insert all nodes (shops, exits, corridors, etc.)
    for (const auto& node : nodes) {
        insertWithSteps(node, history, stepCounter);
    }
    
    return history;
}

HashNode* GraphHashMap::lookup(int id) {
    int index = hashFunction(id);
    HashNode* current = buckets[index];
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}