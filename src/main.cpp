#ifdef WIN32
#include <raylib_win32.h>
#include <windows.h>
#endif

#include "RobloxData/GetRobloxData.hpp"
#include "TerminalGraphics/NoGui.hpp"
#include "Graphics/Graphics.hpp"
#include "ArgCheck.hpp"

#include <iostream>

std::string Bool2Str(bool Bool) {return Bool ? "True" : "False";}

int main(int argc, char **argv) {
    ArgCheck Arg;
    if(Arg.Check(argc, argv) == NOTVALID) return 0;

    std::cout << "Universe ID: " << Arg.universeId << "\n";
    std::cout << "Refreah Time: " << Arg.RefTime << " if = 0 No Refresh\n";
    std::cout << "Use Font: " << Bool2Str(Arg.UseFont) << "\n";
    std::cout << "Gui: " << Bool2Str(Arg.UseGui) << "\n";

    if(Arg.UseGui) {
        std::cout << "Graphics Api: Raylib\n";
        Graphics Raylib(Str2U64(Arg.universeId), Arg.RefTime, Arg.UseFont);
        Raylib.Loop();
    } else {
        NoGui Tui(Str2U64(Arg.universeId), Arg.RefTime);
        Tui.Loop();
    }
    return 0;
}
