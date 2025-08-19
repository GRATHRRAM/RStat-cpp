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

    void Draw(NormalRes &Res) {
        Vector2 PxPos = Res.ToPixel(NormalPos.x, NormalPos.y);
        int textWidth = MeasureText(Text.c_str(), FontSize);
        int textHeight = FontSize;
        PxPos.x -= textWidth  * AnchorPoint.x;
        PxPos.y -= textHeight * AnchorPoint.y;
        DrawText(Text.c_str(), PxPos.x, PxPos.y, FontSize, TextColor);
    }
};