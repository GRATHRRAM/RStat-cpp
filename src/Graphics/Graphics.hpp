#pragma once
#include <raylib_win32.h>
#include <raylib.h>
#include "../RobloxData/GetStats.hpp"

#include "NormalRes.hpp"
#include "NormalText.hpp"

class Graphics { 
    private:
    GetStats Stats;
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
    Graphics(uint64_t UniverseID);
    ~Graphics();
    void Loop();
};

