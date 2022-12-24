#include "connectorsManager.hpp"
#include "TGFConnector.hpp"

TGFConnector* graph_connectors::fetch(ConnectorsManager* connectorsManager) {
    TGFConnector* firstConnector = NULL;
    TGFConnector* currentConnector = NULL;
    for (int i = 0 ; i < *connectorsManager->elementsCount ; i++) {
        nlohmann::json* currentData = &connectorsManager->jsonData->at(i);
        if (currentData->contains("fill")) {
            bool isConnector = strcmp(currentData->at("fill").get<std::string>().c_str(), "CONNECTOR") == 0;
            if (isConnector) {
                if (firstConnector == NULL) {
                    firstConnector = new TGFConnector();
                    currentConnector = firstConnector;
                }
                else if (currentConnector->next == NULL) {
                    TGFConnector* newConnector = new TGFConnector();
                    currentConnector->next = newConnector;
                    currentConnector = newConnector;
                }
                currentConnector->sourceNode = currentData->at("connect.a").get<std::string>();
                currentConnector->targetNode = currentData->at("connect.b").get<std::string>();
                currentConnector->label = currentData->at("label").get<std::string>();
            }
        }
    }
    return firstConnector;
}

std::string graph_connectors::buildString(TGFConnector* connector) {
    std::string connectorString = connector->sourceNode + " " + connector->targetNode;
    if (connector->label != "") {
        connectorString += " " + connector->label;
    }
    connectorString += '\n';
    return connectorString;
}
