#pragma once
#include <raylib.h>

class NormalRes {
    private:
        int ScreenWidth;
        int ScreenHeight;
    public:
    NormalRes(int ScreenWidth, int ScreenHeight)
        : ScreenWidth(ScreenWidth), ScreenHeight(ScreenHeight) {}

    Vector2 ToNormalized(int x, int y) const {
        return {
            static_cast<float>(x) / static_cast<float>(ScreenWidth),
            static_cast<float>(y) / static_cast<float>(ScreenHeight)
        };
    }

    Vector2 ToPixel(float normX, float normY) const {
        return {
            normX * ScreenWidth,
            normY * ScreenHeight
        };
    }

    int GetWidth() const { return ScreenWidth; }
    int GetHeight() const { return ScreenHeight; }

    void SetResolution(int x, int y) {ScreenWidth = x; ScreenHeight = y;}
};