#pragma once

#define OK true
#define FAILURE false

#include <string>
#include <stdint.h>

struct GameStats {
    std::string Name;
    std::string CreatorName;
    std::string CreatorType;
    std::string Created;
    std::string Updated;
    uint64_t Playing;
    uint64_t Visits;
    uint64_t FavoritedCount;
    uint64_t UpVotes;
    uint64_t DownVotes;
    bool DataEmpty;
};