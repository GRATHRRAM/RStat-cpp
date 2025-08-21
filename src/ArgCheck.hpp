#pragma once
#include <string>

#define ALLVALID true
#define NOTVALID false

class ArgCheck {
    public:
    std::string universeId = "8353903143";
    bool UseGui = true;
    bool UseFont = true;
    float RefTime = 5;

    bool Check(int argc, char **argv);
};