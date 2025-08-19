#include "Raylib.hpp"
#include <string>

Graphics::Graphics(GetStats *_StatsPtr) : _StatsPtr(_StatsPtr)  {
    bool Done = false; while(!Done) {Done = _StatsPtr->Update();}

    std::string Title = "RStats C++ | " + _StatsPtr->Get().Name;
    InitWindow(800, 600, Title.c_str());
}

Graphics::~Graphics() {
    CloseWindow();
}

void Graphics::Loop() {
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(_StatsPtr->Get().Name.c_str(), 10, 10, 20, BLACK);
            DrawText(std::to_string(_StatsPtr->Get().Playing).c_str(), 100, 100, 20, BLACK);
        EndDrawing();
    }
}