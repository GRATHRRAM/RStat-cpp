#pragma once
#include <raylib_win32.h>
#include <raylib.h>
#include "../RobloxData/GetRobloxData.hpp"

#include "NormalRes.hpp"
#include "NormalText.hpp"
#include "NormalBgRect.hpp"

class Graphics { 
    private:
    GetStats Stats;
    NormalRes Normal = NormalRes(0,0);

    Font GlobalFont = {};
    bool UseFont = true;

    float RefreshTime = 5.f;
    float Time = RefreshTime;

    float TextScale = 1;

    NormalText GameName;
    NormalText Creator;
    NormalText CreatedAndUpdated;
    NormalText CurrentPlayers;
    NormalText Visits;
    NormalText FavoritedCount;

    NormalBgRect BgRect;

    void SetupText();
    public:
    Graphics(uint64_t UniverseID, float RefreshTime, bool UseFont = true);
    ~Graphics();
    void Loop();
};

