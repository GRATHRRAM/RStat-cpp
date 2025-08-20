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

uint64_t Str2U64(std::string str);
bool GetUniverseID(uint64_t &UniverseID, uint64_t PlaceID);
bool MakeRequest(json &ReturnJson, std::string Url);
std::string StripURL(std::string URL); //Converts Link To PlaceID