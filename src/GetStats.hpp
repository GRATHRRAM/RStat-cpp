#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

#define OK true
#define FAILURE false

struct GameStats {
    std::string Name;
    std::string CreatorName;
    std::string CreatorType;
    std::string Created;
    std::string Updated;
    uint64_t Playing;
    uint64_t Visits;
    uint64_t FavoritedCount;
    bool DataEmpty;
};

class GetStats {
    private:
        json Buff;
        uint64_t UniverseID;
    public:
    GetStats(uint64_t UniverseID = 8353903143);

    GameStats Get();
    bool Update(); //Make a http request
};
