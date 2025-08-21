#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../Types.hpp"

class GetStats {
    private:
        json Buff;
        uint64_t UniverseID;
        uint64_t Likes;
        uint64_t Dislikes;
    public:
    GetStats(uint64_t UniverseID = 8353903143);

    GameStats Get();
    bool Update(); //Make a http request
};

bool MakeRequest(json &ReturnJson, std::string Url);

uint64_t Str2U64(std::string str);
std::string StripURL(std::string URL); //Converts Link To PlaceID

bool GetUniverseID(uint64_t &UniverseID, uint64_t PlaceID);
bool GetLikes(uint64_t &Likes, uint64_t &DisLikes, uint64_t UniverseID);

//https://games.roproxy.com/v1/games/8353903143/votes