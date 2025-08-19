#pragma once
#include <raylib_win32.h>
#include <raylib.h>
#include "../RobloxData/GetStats.hpp"

#include "NormalRes.hpp"
#include "NormalText.hpp"

class Graphics { 
    private:
    GetStats *StatsPtr;
    NormalRes Normal = NormalRes(100,100);

    float RefreshTime = 5.f;
    float Time = RefreshTime;

    NormalText GameName;
    NormalText Creator;
    NormalText CreatedAndUpdated;
    NormalText CurrentPlayers;
    NormalText Visits;
    NormalText FavoritedCount;

    public:
    Graphics(GetStats *StatsPtr);
    ~Graphics();
    void Loop();
};

