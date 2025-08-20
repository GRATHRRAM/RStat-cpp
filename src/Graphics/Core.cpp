#include "Graphics.hpp"
#include <string>

Graphics::Graphics(uint64_t UniverseID, bool UseFont) : UseFont(UseFont) {
    Stats = GetStats(UniverseID);
    bool Done = false; while(!Done) {Done = Stats.Update();}

    std::string Title = "RStats C++ | " + Stats.Get().Name;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(340, 400, Title.c_str());
    Normal = NormalRes(GetScreenWidth(), GetScreenHeight());

    SetTargetFPS(30);

    if(UseFont) GlobalFont = LoadFontEx("Font.ttf", 128, nullptr, 0);
    else TextScale = 0.9;

    Stats.Update();

    SetupText();

    BgRect.Size = Vector2{0.9,0.9};
    BgRect.RectColor = Color{46, 46, 68,255};
}

void Graphics::SetupText() {
    GameName.Text = Stats.Get().Name;
    GameName.FontSize = 24;
    GameName.AnchorPoint = Vector2{0.5f,0.5f};
    GameName.NormalPos = Vector2{0.5,0.2};
    GameName.TextColor = Color{255, 215, 0,255};
    if(UseFont) GameName.TextFont = GlobalFont;

    Creator.Text = "By " + Stats.Get().CreatorType + " " + Stats.Get().CreatorName;
    Creator.FontSize = 18;
    Creator.AnchorPoint = Vector2{0.5f,0.5f};
    Creator.NormalPos = Vector2{0.5, 0.27f};
    Creator.TextColor = Color{170, 170, 170,255};
    if(UseFont) Creator.TextFont = GlobalFont;

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
    CreatedAndUpdated.FontSize = 16;
    CreatedAndUpdated.AnchorPoint = Vector2{0.5f,0.5f};
    CreatedAndUpdated.NormalPos = Vector2{0.5, 0.35f};
    CreatedAndUpdated.TextColor = Color{200,200,200,255};
    if(UseFont) CreatedAndUpdated.TextFont = GlobalFont;

    CurrentPlayers.FontSize = 24;
    CurrentPlayers.AnchorPoint = Vector2{0.5f,0.5f};
    CurrentPlayers.NormalPos = Vector2{0.5,0.55};
    CurrentPlayers.TextColor = Color{200,200,200,255};
    if(UseFont) CurrentPlayers.TextFont = GlobalFont;

    Visits.FontSize = 24;
    Visits.AnchorPoint = Vector2{0.5f,0.5f};
    Visits.NormalPos = Vector2{0.5,0.61};
    Visits.TextColor = Color{200,200,200,255};
    if(UseFont) Visits.TextFont = GlobalFont;

    FavoritedCount.FontSize = 24;
    FavoritedCount.AnchorPoint = Vector2{0.5f,0.5f};
    FavoritedCount.NormalPos = Vector2{0.5,0.67};
    FavoritedCount.TextColor = Color{200,200,200,255};
    if(UseFont) FavoritedCount.TextFont = GlobalFont;
}

Graphics::~Graphics() {
    UnloadFont(GlobalFont);
    CloseWindow();
}