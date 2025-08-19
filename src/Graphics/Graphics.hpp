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

    NormalText GameName;
    NormalText CurrentPlayers;
    NormalText Creator;

    public:
    Graphics(GetStats *StatsPtr);
    ~Graphics();
    void Loop();
};

