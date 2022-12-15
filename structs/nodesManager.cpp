#include "nodesManager.hpp"

nlohmann::json graph_nodes::fetch(NodesManager nodesManager) {
    nlohmann::json nodes;
    int currentElementIndex = 0;
    for (int i = 0 ; i < nodesManager.elementsCount ; i++) {
        nlohmann::json currentData = nodesManager.jsonData[i];
        if (currentData.contains("fill")) {
            bool isNode = strcmp(currentData["fill"].get<std::string>().c_str(), "CONNECTOR") != 0;
            if (isNode) {
                nodes[currentElementIndex] = currentData;
                currentElementIndex++;
            }
        }
    }
    return nodes;
}

std::string graph_nodes::buildString(nlohmann::json node) {
    return node["id"].get<std::string>() + " " + node["label"].get<std::string>() + " " + '\n';
}
