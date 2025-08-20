#ifdef WIN32
#include <raylib_win32.h>
#include <windows.h>
#endif

#include "RobloxData/GetRobloxData.hpp"
#include "TerminalGraphics/NoGui.hpp"
#include "Graphics/Graphics.hpp"

#include <iostream>

int main(int argc, char **argv) {
    std::string universeId = "8353903143";
    bool UseGui = true;
    bool UseFont = true;
    float RefTime = 5;

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
        } else if (arg == "--reftime") {
            RefTime = std::stof(argv[++i]);
        } else if (arg == "--url2uni") {
            uint64_t Unid = 0;
            GetUniverseID(Unid, Str2U64(StripURL(std::string(argv[++i]))));
            std::cout << "UniverseID: " << Unid << "\n";
            return 0;
        } else if (arg == "--url") {
            uint64_t Unid = 0;
            GetUniverseID(Unid, Str2U64(StripURL(std::string(argv[++i]))));
            universeId = std::to_string(Unid);
        } else if (arg == "--placeid") {
            uint64_t Unid = 0;
            GetUniverseID(Unid, Str2U64(std::string(argv[++i])));
            universeId = std::to_string(Unid);
        } else if (arg == "--noterm") {
            #ifdef WIN32
                HWND hwnd = GetConsoleWindow();
                ShowWindow(hwnd, SW_HIDE);
            #endif
        } else if (arg == "--help") {
            std::cout << "--universeid / --unid # Use To Set Universe ID\n"
                      << "--nogui   # Uses Terminal As Output (def refresh 1 sec, clears screen)\n"
                      << "--nofont  # Makes Gui Mode Not Load Font\n"
                      << "--noterm  # Windows Only!!! Hides Terminal \n"
                      << "--url2uni # Converts Roblox Link To Universe ID\n"
                      << "--url     # Converts Link To Universe ID and Starts RStats With it\n"
                      << "--placeid # Converts PlaceID to UniverseID Adn Starts RStats With it\n"
                      << "--reftime # ex --reftime 5 # Sets Refresh Time if 0 Program Will not refresh\n";
            return 0;
        } else {
            std::cout << "Invalid Arg -> " << arg << "\n" << "Quiting!!!\n";
            return 0;
        }
    }

    std::cout << "Universe ID: " << universeId << "\n";
    std::cout << "Gui: " << UseGui << "\n";

    if(UseGui) {
        std::cout << "Graphics Api: Raylib\n";
        Graphics Raylib(Str2U64(universeId), RefTime, UseFont);
        Raylib.Loop();
    } else {
        NoGui Tui(Str2U64(universeId), RefTime);
        Tui.Loop();
    }
    return 0;
}
