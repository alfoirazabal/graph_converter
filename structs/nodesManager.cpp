#include "nodesManager.hpp"

nlohmann::json graph_nodes::fetch(NodesManager nodesManager) {
    nlohmann::json nodes = nlohmann::json::array();
    int currentElementIndex = 0;
    for (int i = 0 ; i < nodesManager.elementsCount ; i++) {
        nlohmann::json* currentData = &nodesManager.jsonData->at(i);
        if (currentData->contains("fill")) {
            bool isNode = strcmp(currentData->at("fill").get<std::string>().c_str(), "CONNECTOR") != 0;
            if (isNode) {
                nodes[currentElementIndex] = *currentData;
                currentElementIndex++;
            }
        }
    }
    return nodes;
}

std::string graph_nodes::buildString(nlohmann::json* node) {
    std::string nodeString = node->at("id").get<std::string>() + " " + node->at("label").get<std::string>() + " " + '\n';
    return nodeString;
}
