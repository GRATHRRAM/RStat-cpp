#include "Graphics.hpp"
#include <string>

void Graphics::Loop() {
    while(!WindowShouldClose()) {
        Normal.SetResolution(GetScreenWidth(), GetScreenHeight());
        CurrentPlayers.Text = "Current Players: " + std::to_string(StatsPtr->Get().Playing);
        Visits.Text = "Current Visits: " + std::to_string(StatsPtr->Get().Visits);
        FavoritedCount.Text = "Favorited Count: " + std::to_string(StatsPtr->Get().FavoritedCount);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            GameName.Draw(Normal);
            Creator.Draw(Normal);
            CreatedAndUpdated.Draw(Normal);
            CurrentPlayers.Draw(Normal);
            Visits.Draw(Normal);
            FavoritedCount.Draw(Normal);
        EndDrawing();

        Time -= GetFrameTime();
        if(Time <= 0) {
            Time = RefreshTime;
            StatsPtr->Update();
        }
    }
}