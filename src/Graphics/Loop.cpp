#include "Graphics.hpp"
#include <string>

void Graphics::Loop() {
    while(!WindowShouldClose()) {
        Normal.SetResolution(GetScreenWidth(), GetScreenHeight());
        CurrentPlayers.Text = "Current Players: " + std::to_string(StatsPtr->Get().Playing);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            GameName.Draw(Normal);
            Creator.Draw(Normal);
            CurrentPlayers.Draw(Normal);
        EndDrawing();
    }
}