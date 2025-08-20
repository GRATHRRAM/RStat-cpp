#pragma once
#include <raylib.h>
#include <stdint.h>
#include "NormalRes.hpp"

class NormalBgRect {
    public:
    Vector2 Size; //Normalized
    Color RectColor;

    void Draw(NormalRes& Res) {
        Vector2 Center = Res.ToPixel(0.5,0.5);
        Vector2 PxSize = Res.ToPixel(Size.x, Size.y);

        Vector2 TopLeft = { Center.x - PxSize.x / 2.0f, Center.y - PxSize.y / 2.0f };
        
        DrawRectangle(TopLeft.x, TopLeft.y, PxSize.x, PxSize.y, RectColor);
    }
};