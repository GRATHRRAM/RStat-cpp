#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../Types.hpp"

class GetStats {
    private:
        json Buff;
        uint64_t UniverseID;
    public:
    GetStats(uint64_t UniverseID = 8353903143);

    GameStats Get();
    bool Update(); //Make a http request
};
