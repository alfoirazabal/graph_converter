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

using namespace std;

using json = nlohmann::json;

string convertToTGF(json jsonData) {
    int elementsCount = jsonData.size();
    NodesManager nodesManager;
    nodesManager.elementsCount = elementsCount;
    nodesManager.jsonData = jsonData;
    ConnectorsManager connectorsManager;
    connectorsManager.elementsCount = elementsCount;
    connectorsManager.jsonData = jsonData;
    json nodes = graph_nodes::fetch(nodesManager);
    json connectors = graph_connectors::fetch(connectorsManager);
    int nodesSize = nodes.size();
    int connectorsSize = connectors.size();
    string tgf = "";
    for (int i = 0 ; i < nodesSize ; i++) {
        tgf += graph_nodes::buildString(nodes[i]);
    }
    tgf += "#\n";
    for (int i = 0 ; i < connectorsSize ; i++) {
        tgf += graph_connectors::buildString(connectors[i]);
    }
    return tgf;
}

int main(int argc, char * argv[])
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

        string tgf = convertToTGF(data);

        std::ofstream outputFile(outputFilePath);
        outputFile << tgf;
        outputFile.close();
    }
}
