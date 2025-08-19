#include "Graphics.hpp"
#include <string>

void Graphics::Loop() {
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(_StatsPtr->Get().Name.c_str(), 10, 10, 20, BLACK);
            DrawText(std::to_string(_StatsPtr->Get().Playing).c_str(), 100, 100, 20, BLACK);
        EndDrawing();
    }
}