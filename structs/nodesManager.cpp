#include "../libs/json.hpp"
#include <string>

using namespace std;

using json = nlohmann::json;

struct NodesManager {

    int elementsCount;
    json jsonData;

    NodesManager() : elementsCount(0) { }

    json fetch() {
        json nodes;
        int currentElementIndex = 0;
        for (int i = 0 ; i < elementsCount ; i++) {
            json currentData = jsonData[i];
            if (currentData.contains("fill")) {
                bool isNode = strcmp(currentData["fill"].get<string>().c_str(), "CONNECTOR") != 0;
                if (isNode) {
                    nodes[currentElementIndex] = currentData;
                    currentElementIndex++;
                }
            }
        }
        return nodes;
    }

    string buildString(json node) {
        return node["id"].get<string>() + " " + node["label"].get<string>() + " " + '\n';
    }

};