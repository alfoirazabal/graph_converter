#ifndef NODES_MANAGER_H_INCLUDED
#define NODES_MANAGER_H_INCLUDED

#include "../libs/json.hpp"
#include <string>

struct NodesManager {

    int elementsCount;
    nlohmann::json jsonData;

};

namespace graph_nodes
{
    nlohmann::json fetch(NodesManager nodesManager);

    std::string buildString(nlohmann::json node);
}

#endif
