#pragma once
#include <string>
#include <raylib.h>
#include <stdint.h>
#include "NormalRes.hpp"

class NormalText {
    public:
    std::string Text;
    Color TextColor;
    uint16_t FontSize;
    Vector2 NormalPos;
    Vector2 AnchorPoint;
    Font TextFont;

    void Draw(NormalRes &Res, float Scale = 1, bool UseFont = false) {
        Vector2 PxPos = Res.ToPixel(NormalPos.x, NormalPos.y);
        Vector2 Size = {};

        if(UseFont) {
            Size = MeasureTextEx(TextFont,Text.c_str(), (FontSize * Res.GetScale()) * Scale, 0);
        } else {
            Size.x = MeasureText(Text.c_str(), (FontSize * Res.GetScale()) * Scale);
            Size.y = FontSize;
        }

        PxPos.x -= Size.x * AnchorPoint.x;
        PxPos.y -= Size.y * AnchorPoint.y;
        if(UseFont) DrawTextEx(TextFont, Text.c_str(), PxPos, (FontSize * Res.GetScale()) * Scale, 0, TextColor);
        else DrawText(Text.c_str(), PxPos.x, PxPos.y, (FontSize * Res.GetScale()) * Scale, TextColor);
    }
};