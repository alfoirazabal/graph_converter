#include "../libs/json.hpp"
#include <string>

using namespace std;

using json = nlohmann::json;

struct ConnectorsManager {

    int elementsCount;
    json jsonData;

    ConnectorsManager() : elementsCount(0) { }

    json fetch() {
        json connectors;
        int currentElementIndex = 0;
        for (int i = 0 ; i < elementsCount ; i++) {
            json currentData = jsonData[i];
            if (currentData.contains("fill")) {
                bool isConnector = strcmp(currentData["fill"].get<string>().c_str(), "CONNECTOR") == 0;
                if (isConnector) {
                    connectors[currentElementIndex] = currentData;
                    currentElementIndex++;
                }
            }
        }
        return connectors;
    }

    string buildString(json connector) {
        string connectorString = "";
        if (!connector["connect.a"].is_null() && !connector["connect.b"].is_null()) {
            connectorString = connector["connect.a"].get<string>() + " " + connector["connect.b"].get<string>() + " " + '\n';
        }
        return connectorString;
    }

};