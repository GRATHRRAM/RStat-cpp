#include "GetStats.hpp"
#include "NoGui.hpp"

int main(int argc, char **argv) {
    std::string universeId = "8353903143";

    if (argc >= 3 && std::string(argv[1]) == "--universeid") {
        universeId = argv[2];
        std::cout << "Universe ID: " << universeId << std::endl;
    }

    GetStats _GetStats(std::strtoull(universeId.c_str(), nullptr, 10));
    NoGui Tui(&_GetStats);
    Tui.Loop();
    return 0;
}
