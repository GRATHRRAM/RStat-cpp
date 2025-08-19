#pragma once
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

#define OK true
#define FAILURE false

typedef struct GameStats {
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
        CURL* curl;
        CURLcode res;
        std::string readBuffer;
        json Buff;
        uint64_t UniverseID;
    public:
    GetStats(uint64_t UniverseID = 8353903143);
    ~GetStats();

    bool InitOk();
    GameStats Get();
    bool Update(); //Make a http request
};
