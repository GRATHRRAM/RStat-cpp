#include <curl/curl.h>
#include <iostream>
#include "GetRobloxData.hpp"

// Callback function to collect the HTTP response into a std::string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool MakeRequest(json& ReturnJson, std::string Url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_CAINFO, "./curl-ca-bundle.crt");

    if(curl) {
        const char* url = Url.c_str();
        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " 
                      << curl_easy_strerror(res) << std::endl;
        } else {
            try {
                ReturnJson = json::parse(readBuffer);
            } catch (std::exception& e) {
                std::cerr << "JSON parsing error: " << e.what() << std::endl;
                return FAILURE;
            }
        }
    }

    curl_easy_cleanup(curl);
    return OK;
}

bool GetUniverseID(uint64_t& UniverseID, uint64_t PlaceID) {
    json Buff;
    bool ret = MakeRequest(Buff,
        std::string("https://apis.roblox.com/universes/v1/places/") +
        std::to_string(PlaceID) +
        std::string("/universe")
    );

    if(!Buff.contains("universeId")) {std::cerr << "UniverseID Request Returned Null\n"; return FAILURE;} 
    UniverseID = Buff["universeId"];
    return ret;
}

std::string StripURL(std::string url) {
    const std::string marker = "/games/";
    auto pos = url.find(marker);
    if (pos == std::string::npos) return "";

    pos += marker.length();
    auto endPos = url.find('/', pos);
    if (endPos == std::string::npos)
        return url.substr(pos);
    else
        return url.substr(pos, endPos - pos);
}

uint64_t Str2U64(std::string str) {
    return std::strtoull(str.c_str(), nullptr, 10);
}