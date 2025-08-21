#include "GetRobloxData.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

GetStats::GetStats(uint64_t UniverseID) : UniverseID(UniverseID) {}

GameStats GetStats::Get() {
    GameStats st = {};

    if (Buff.contains("data") && !Buff["data"].empty()) {
        st.Name = Buff["data"][0]["name"];
        st.CreatorName = Buff["data"][0]["creator"]["name"];
        st.CreatorType = Buff["data"][0]["creator"]["type"];
        st.Created = Buff["data"][0]["created"];
        st.Updated = Buff["data"][0]["updated"];

        st.Visits = Buff["data"][0]["visits"];
        st.Playing = Buff["data"][0]["playing"];
        st.FavoritedCount = Buff["data"][0]["favoritedCount"];
        st.UpVotes = Likes;
        st.DownVotes = Dislikes;
    } else st.DataEmpty = true;

    return st;
}

bool GetStats::Update() {
    std::string str = std::string("https://games.roproxy.com/v1/games?universeIds=")
    + std::to_string(UniverseID);
    return MakeRequest(Buff, str) | GetLikes(Likes, Dislikes, UniverseID);
}