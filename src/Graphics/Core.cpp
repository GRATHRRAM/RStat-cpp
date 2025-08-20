#include "Graphics.hpp"
#include <string>

Graphics::Graphics(uint64_t UniverseID)  {
    Stats = GetStats(UniverseID);
    bool Done = false; while(!Done) {Done = Stats.Update();}

    std::string Title = "RStats C++ | " + Stats.Get().Name;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, Title.c_str());
    SetTargetFPS(30);

    Stats.Update();

    GameName.Text = Stats.Get().Name;
    GameName.FontSize = 20;
    GameName.AnchorPoint = Vector2{0.5f,0.5f};
    GameName.NormalPos = Vector2{0.5,0.3};
    GameName.TextColor = Color{0,0,0,255};

    Creator.Text = "By " + Stats.Get().CreatorType + " " + Stats.Get().CreatorName;
    Creator.FontSize = 20;
    Creator.AnchorPoint = Vector2{0.5f,0.5f};
    Creator.NormalPos = Vector2{0.5, 0.4f};
    Creator.TextColor = Color{0,0,0,255};

    std::string Created = Stats.Get().Created;
    Created.insert(0,  "Date: ");
    int pos = Created.find("T");
    Created.replace(pos+9, 10, "");
    Created.replace(pos, 1, "");
    Created.insert(pos,  " Time: ");

    std::string Updated = Stats.Get().Updated;
    Updated.insert(0,  "Date: ");
    pos = Updated.find("T");
    Updated.replace(pos+9, 10, "");
    Updated.replace(pos, 1, "");
    Updated.insert(pos,  " Time: ");

    CreatedAndUpdated.Text = "Created " +  Created + "\n" + "Updated " + Updated;
    CreatedAndUpdated.FontSize = 20;
    CreatedAndUpdated.AnchorPoint = Vector2{0.5f,0.5f};
    CreatedAndUpdated.NormalPos = Vector2{0.5, 0.5f};
    CreatedAndUpdated.TextColor = Color{0,0,0,255};

    CurrentPlayers.FontSize = 20;
    CurrentPlayers.AnchorPoint = Vector2{0.5f,0.5f};
    CurrentPlayers.NormalPos = Vector2{0.5,0.6};
    CurrentPlayers.TextColor = Color{0,0,0,255};

    Visits.FontSize = 20;
    Visits.AnchorPoint = Vector2{0.5f,0.5f};
    Visits.NormalPos = Vector2{0.5,0.7};
    Visits.TextColor = Color{0,0,0,255};

    FavoritedCount.FontSize = 20;
    FavoritedCount.AnchorPoint = Vector2{0.5f,0.5f};
    FavoritedCount.NormalPos = Vector2{0.5,0.8};
    FavoritedCount.TextColor = Color{0,0,0,255};
}

Graphics::~Graphics() {
    CloseWindow();
}