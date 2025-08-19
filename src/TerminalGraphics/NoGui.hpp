#pragma once
#include "../RobloxData/GetStats.hpp"

class NoGui {
    private:
        float RefreshTime = 1; //sec (0 == no Refresh)
        bool ClearTerminal = true;
        GetStats *_StatsPtr;
    public:
    NoGui(GetStats *_StatsPtr, float RefreshTime = 1, bool ClearTerminal = true) 
    : RefreshTime(RefreshTime), ClearTerminal(ClearTerminal), _StatsPtr(_StatsPtr) {}

    void Print(GameStats &Stats);
    void Clear();

    void Loop();
};
