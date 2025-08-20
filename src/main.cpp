#ifdef WIN32
#include <raylib_win32.h>
#endif

#include "RobloxData/GetStats.hpp"
#include "TerminalGraphics/NoGui.hpp"
#include "Graphics/Graphics.hpp"

#include <iostream>

int main(int argc, char **argv) {
    std::string universeId = "8353903143";
    bool UseGui = true;
    bool UseFont = true;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--universeid" && i + 1 < argc) {
            universeId = argv[++i];
        } else if (arg == "--unid" && i + 1 < argc) {
            universeId = argv[++i];
        } else if (arg == "--nogui") {
            UseGui = false;
        } else if (arg == "--nofont") {
            UseFont = false;
        } else if (arg == "--help") {
            std::cout << "--universeid / --unid # Use To Set Universe ID\n"
                      << "--nogui # Uses Terminal As Output (def refresh 1 sec, clears screen)\n"
                      << "--nofont # Makes Gui Mode Not Load Font\n";
            return 0;
        }
    }

    std::cout << "Universe ID: " << universeId << "\n";
    std::cout << "Gui: " << UseGui << "\n";


    if(UseGui) {
        Graphics Raylib(std::strtoull(universeId.c_str(), nullptr, 10), UseFont);
        Raylib.Loop();
        std::cout << "Graphics Api: Raylib\n";
    } else {
        NoGui Tui(std::strtoull(universeId.c_str(), nullptr, 10));
        Tui.Loop();
    }
    return 0;
}
