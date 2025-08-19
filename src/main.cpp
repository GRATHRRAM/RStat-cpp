#include <raylib_win32.h>
#include "GetStats.hpp"
#include "NoGui.hpp"
#include "Graphics/Raylib.hpp"

int main(int argc, char **argv) {
    std::string universeId = "8353903143";
    bool UseGui = true;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--universeid" && i + 1 < argc) {
            universeId = argv[++i];
        } else if (arg == "--nogui") {
            UseGui = false;
        }
    }

    std::cout << "Universe ID: " << universeId << "\n";
    std::cout << "Gui: " << UseGui << "\n";

    GetStats _GetStats(std::strtoull(universeId.c_str(), nullptr, 10));

    if(UseGui) {
        Graphics Raylib(&_GetStats);
        Raylib.Loop();
        std::cout << "Graphics Api: Raylib\n";
    } else {
        NoGui Tui(&_GetStats);
        Tui.Loop();
    }
    return 0;
}
