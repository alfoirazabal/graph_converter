#ifndef CONNECTORS_MANAGER_H_INCLUDED
#define CONNECTORS_MANAGER_H_INCLUDED

#include "../libs/json.hpp"
#include <string>

struct ConnectorsManager {

    int elementsCount;
    nlohmann::json* jsonData;

};

namespace graph_connectors
{
    nlohmann::json fetch(ConnectorsManager connectorsManager);

    std::string buildString(nlohmann::json* connector);
}

#endif
