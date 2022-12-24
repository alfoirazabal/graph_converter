#include "nodesManager.hpp"
#include "TGFNode.hpp"

TGFNode* graph_nodes::fetch(NodesManager* nodesManager) {
    TGFNode* firstNode = NULL;
    TGFNode* currentNode = NULL;
    for (int i = 0 ; i < *nodesManager->elementsCount ; i++) {
        nlohmann::json* currentData = &nodesManager->jsonData->at(i);
        if (currentData->contains("fill")) {
            bool isNode = strcmp(currentData->at("fill").get<std::string>().c_str(), "CONNECTOR") != 0;
            if (isNode) {
                if (firstNode == NULL) {
                    firstNode = new TGFNode();
                    currentNode = firstNode;
                }
                else if (currentNode->next == NULL) {
                    TGFNode* newNode = new TGFNode();
                    currentNode->next = newNode;
                    currentNode = newNode;
                }
                currentNode->id = currentData->at("id").get<std::string>();
                currentNode->label = currentData->at("label").get<std::string>();
            }
        }
    }
    return firstNode;
}

std::string graph_nodes::buildString(TGFNode* node) {
    std::string nodeString = node->id + " " + node->label + '\n';
    return nodeString;
}
