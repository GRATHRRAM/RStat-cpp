#include "NoGui.hpp"
#include <thread>
#include <chrono>

void NoGui::Print(GameStats &Stats) {
    std::cout << "===============================\n";
    std::cout << "Name: " << Stats.Name << "\n";
    std::cout << "CreatorName: " << Stats.CreatorName << "\n";
    std::cout << "CreatorType: " << Stats.CreatorType << "\n";
    std::cout << "Created: " << Stats.Created << "\n";
    std::cout << "Updated: " << Stats.Updated << "\n";
    std::cout << "Playing: " << Stats.Playing << "\n";
    std::cout << "Visits: " << Stats.Visits << "\n";
    std::cout << "FavoritedCount: " << Stats.FavoritedCount << "\n";
    std::cout << "===============================\n";
}

void NoGui::Clear() {
    #ifdef WIN32
    if(ClearTerminal) system("cls");
    #elif 
    if(ClearTerminal) system("clear")
    #endif
}

void NoGui::Loop() {
    do {
        _StatsPtr->Update();
        GameStats st = _StatsPtr->Get();

        Clear();
        Print(st);
        std::this_thread::sleep_for(std::chrono::duration<double>(RefreshTime));
    } while(RefreshTime > 0);
}