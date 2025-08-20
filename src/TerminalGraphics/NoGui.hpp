#pragma once
#include "../RobloxData/GetStats.hpp"

class NoGui {
    private:
        float RefreshTime = 5; //sec (0 == no Refresh)
        bool ClearTerminal = true;
        GetStats Stats;
    public:
    NoGui(uint64_t UniverseID, float RefreshTime = 1, bool ClearTerminal = true) 
    : RefreshTime(RefreshTime), ClearTerminal(ClearTerminal) {
        Stats = GetStats(UniverseID);
    }

    void Print(GameStats &Stats);
    void Clear();

    void Loop();
};
