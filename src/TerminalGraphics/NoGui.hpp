#pragma once
#include "../RobloxData/GetRobloxData.hpp"

class NoGui {
    private:
        float RefreshTime = 5; //sec (0 == no Refresh)
        bool ClearTerminal = true;
        GetStats Stats;
        uint64_t Likes;
        uint64_t DisLikes;
    public:
    NoGui(uint64_t UniverseID, float RefreshTime = 5, bool ClearTerminal = true) 
    : RefreshTime(RefreshTime), ClearTerminal(ClearTerminal) {
        Stats = GetStats(UniverseID);
        GetLikes(Likes, DisLikes, UniverseID);
    }

    void Print(GameStats &Stats);
    void Clear();

    void Loop();
};
