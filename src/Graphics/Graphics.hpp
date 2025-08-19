#pragma once
#include <raylib_win32.h>
#include <raylib.h>
#include "../RobloxData/GetStats.hpp"

class Graphics {
    private:
    GetStats *_StatsPtr;
    public:
    Graphics(GetStats *_StatsPtr);
    ~Graphics();
    void Loop();
};

