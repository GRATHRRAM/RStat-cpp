#include "Graphics.hpp"
#include <string>

Graphics::Graphics(GetStats *StatsPtr) : StatsPtr(StatsPtr)  {
    bool Done = false; while(!Done) {Done = StatsPtr->Update();}

    std::string Title = "RStats C++ | " + StatsPtr->Get().Name;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, Title.c_str());

    StatsPtr->Update();

    GameName.Text = StatsPtr->Get().Name;
    GameName.FontSize = 20;
    GameName.AnchorPoint = Vector2{0.5f,0.5f};
    GameName.NormalPos = Vector2{0.5,0.3};
    GameName.TextColor = Color{0,0,0,255};

    Creator.Text = "By " + StatsPtr->Get().CreatorType + " " + StatsPtr->Get().CreatorName;
    Creator.FontSize = 20;
    Creator.AnchorPoint = Vector2{0.5f,0.5f};
    Creator.NormalPos = Vector2{0.5, 0.4f};
    GameName.TextColor = Color{0,0,0,255};

    CurrentPlayers.FontSize = 20;
    CurrentPlayers.AnchorPoint = Vector2{0.5f,0.5f};
    CurrentPlayers.NormalPos = Vector2{0.5,0.5};
    CurrentPlayers.TextColor = Color{0,0,0,255};
}

Graphics::~Graphics() {
    CloseWindow();
}