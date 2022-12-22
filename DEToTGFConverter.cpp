/**
 * This utility converts a DF file (DrawExpress file encoded in JSON) to a TGF file (Trivial Graph Format)
 * This TGF file can be opened with yEd Graph Editor
*/

// DrawExpress Diagram App: https://drawexpress.com/
// yEd Graph Editor : https://yworks.com
// About the trivial graph format file (TGF): https://en.wikipedia.org/wiki/Trivial_Graph_Format

#include <iostream>
#include "libs/json.hpp"
#include <fstream>
#include <string>
#include "structs/nodesManager.hpp"
#include "structs/connectorsManager.hpp"
#include "structs/TGFNode.hpp"

using namespace std;

using json = nlohmann::json;

string buildGraphNodesString(NodesManager* nodesManager) {
    TGFNode* nodes = graph_nodes::fetch(nodesManager);
    TGFNode* currentNode = nodes;
    string nodesString = "";
    while (currentNode != NULL) {
        nodesString += graph_nodes::buildString(currentNode);
        currentNode = currentNode->next;
    }
    delete nodes;
    return nodesString;
}

string buildGraphConnectorsString(ConnectorsManager* connectorsManager) {
    TGFConnector* connectors = graph_connectors::fetch(connectorsManager);
    TGFConnector* currentConnector = connectors;
    string connectorsString = "";
    while (currentConnector != NULL) {
        connectorsString += graph_connectors::buildString(currentConnector);
        currentConnector = currentConnector->next;
    }
    delete connectors;
    return connectorsString;
}

string convertToTGF(json* jsonData) {
    string tgf = "";
    int elementsCount = jsonData->size();
    NodesManager* nodesManager = new NodesManager();
    nodesManager->elementsCount = &elementsCount;
    nodesManager->jsonData = jsonData;
    tgf += buildGraphNodesString(nodesManager);
    tgf += "#\n";
    delete nodesManager;
    ConnectorsManager* connectorsManager = new ConnectorsManager();
    connectorsManager->elementsCount = &elementsCount;
    connectorsManager->jsonData = jsonData;
    tgf += buildGraphConnectorsString(connectorsManager);
    delete connectorsManager;
    return tgf;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "This utility needs 2 arguments. They are the following: " << endl;
        cout << "ARGUMENT 1: The path to the source .de File" << endl;
        cout << "ARGUMENT 2: The path to the target .tgf File" << endl;
    }
    else {
        char* inputFilePath = argv[1];
        char* outputFilePath = argv[2];

        std::ifstream inputFile(inputFilePath);
        json data = json::parse(inputFile);
        inputFile.close();

        string tgf = convertToTGF(&data);

        std::ofstream outputFile(outputFilePath);
        outputFile << tgf;
        outputFile.close();
    }
}
