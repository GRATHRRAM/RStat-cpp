#include "ArgCheck.hpp"
#include "RobloxData/GetRobloxData.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <algorithm>

#ifdef WIN32
#include <raylib_win32.h>
#include <windows.h>
#endif

bool isNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) {
        return std::isdigit(c) || c == '.' || c == '-';
    });
}

bool hasNextArg(int i, int argc) {
    return (i + 1 < argc);
}


bool ArgCheck::Check(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if ((arg == "--universeid" || arg == "--unid") && hasNextArg(i, argc)) {
            universeId = argv[++i];
            if (!isNumber(universeId)) {
                std::cerr << "Error: Invalid universe ID: " << universeId << "\n";
                return NOTVALID;
            }
        }
        else if (arg == "--nogui") {
            UseGui = false;
        }
        else if (arg == "--nofont") {
            UseFont = false;
        }
        else if (arg == "--reftime" && hasNextArg(i, argc)) {
            std::string val = argv[++i];
            try {
                RefTime = std::stof(val);
            } catch (...) {
                std::cerr << "Error: Invalid value for --reftime: " << val << "\n";
                return NOTVALID;
            }
        }
        else if (arg == "--url2uni" && hasNextArg(i, argc)) {
            uint64_t Unid = 0;
            std::string url = argv[++i];
            GetUniverseID(Unid, Str2U64(StripURL(url)));
            std::cout << "UniverseID: " << Unid << "\n";
            return NOTVALID;
        }
        else if (arg == "--url" && hasNextArg(i, argc)) {
            uint64_t Unid = 0;
            std::string url = argv[++i];
            GetUniverseID(Unid, Str2U64(StripURL(url)));
            universeId = std::to_string(Unid);
        }
        else if (arg == "--placeid" && hasNextArg(i, argc)) {
            uint64_t Unid = 0;
            std::string place = argv[++i];
            if (!isNumber(place)) {
                std::cerr << "Error: Invalid place ID: " << place << "\n";
                return NOTVALID;
            }
            GetUniverseID(Unid, Str2U64(place));
            universeId = std::to_string(Unid);
        }
        else if (arg == "--noterm") {
            #ifdef WIN32
                HWND hwnd = GetConsoleWindow();
                ShowWindow(hwnd, SW_HIDE);
            #endif
        }
        else if (arg == "--help") {
            std::cout << "--universeid / --unid # Set Universe ID\n"
                    << "--nogui   # Uses Terminal As Output\n"
                    << "--nofont  # Disables font in GUI mode\n"
                    << "--noterm  # Windows Only, hides terminal\n"
                    << "--url2uni # Converts Roblox Link To Universe ID\n"
                    << "--url     # Converts Link To Universe ID and Starts RStats\n"
                    << "--placeid # Converts PlaceID to UniverseID and Starts RStats\n"
                    << "--reftime # Example: --reftime 5\n";
            return NOTVALID;
        }
        else {
            std::cerr << "Invalid argument: " << arg << "\n";
            return NOTVALID;
        }
    }
    return ALLVALID;
}