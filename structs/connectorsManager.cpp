#include "connectorsManager.hpp"

nlohmann::json graph_connectors::fetch(ConnectorsManager connectorsManager) {
    nlohmann::json connectors;
    int currentElementIndex = 0;
    for (int i = 0 ; i < connectorsManager.elementsCount ; i++) {
        nlohmann::json currentData = connectorsManager.jsonData[i];
        if (currentData.contains("fill")) {
            bool isConnector = strcmp(currentData["fill"].get<std::string>().c_str(), "CONNECTOR") == 0;
            if (isConnector) {
                connectors[currentElementIndex] = currentData;
                currentElementIndex++;
            }
        }
    }
    return connectors;
}

std::string graph_connectors::buildString(nlohmann::json connector) {
    std::string connectorString = "";
    if (!connector["connect.a"].is_null() && !connector["connect.b"].is_null()) {
        connectorString = connector["connect.a"].get<std::string>() + " " + connector["connect.b"].get<std::string>() + " " + '\n';
    }
    return connectorString;
}
