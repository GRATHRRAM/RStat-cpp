#include "Graphics.hpp"
#include <string>
#include <future>

std::future<void> UpdateTask;

void Graphics::Loop() {
    while(!WindowShouldClose()) {
        Normal.SetResolution(GetScreenWidth(), GetScreenHeight());
        CurrentPlayers.Text = "Current Players: " + std::to_string(Stats.Get().Playing);
        Visits.Text = "Current Visits: " + std::to_string(Stats.Get().Visits);
        FavoritedCount.Text = "Favorited Count: " + std::to_string(Stats.Get().FavoritedCount);

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
            if (!UpdateTask.valid() || UpdateTask.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
                UpdateTask = std::async(std::launch::async, [this] {
                    Stats.Update();
                });
            }
        }
    }
}