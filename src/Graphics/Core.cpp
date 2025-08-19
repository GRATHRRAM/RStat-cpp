#include "Graphics.hpp"
#include <string>

Graphics::Graphics(GetStats *_StatsPtr) : _StatsPtr(_StatsPtr)  {
    bool Done = false; while(!Done) {Done = _StatsPtr->Update();}

    std::string Title = "RStats C++ | " + _StatsPtr->Get().Name;
    InitWindow(800, 600, Title.c_str());
}

Graphics::~Graphics() {
    CloseWindow();
}