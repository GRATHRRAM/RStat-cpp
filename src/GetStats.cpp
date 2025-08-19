#include "GetStats.hpp"

// Callback function to collect the HTTP response into a std::string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

GetStats::GetStats(uint64_t UniverseID) : UniverseID(UniverseID) {
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_CAINFO, "./curl-ca-bundle.crt");
}

GetStats::~GetStats() {
    curl_easy_cleanup(curl);
}

bool GetStats::InitOk() {
    if(curl) return OK;
    return FAILURE;
}

GameStats GetStats::Get() {
    GameStats st = {};

    if (Buff.contains("data") && !Buff["data"].empty()) {
        st.Name = Buff["data"][0]["name"];
        st.CreatorName = Buff["data"][0]["creator"]["name"];
        st.CreatorType = Buff["data"][0]["creator"]["type"];
        st.Created = Buff["data"][0]["created"];
        st.Updated = Buff["data"][0]["updated"];

        st.Visits = Buff["data"][0]["visits"];
        st.Playing = Buff["data"][0]["playing"];
        st.FavoritedCount = Buff["data"][0]["favoritedCount"];
    } else st.DataEmpty = true;

    return st;
}

bool GetStats::Update() { //Make a http request
    if(curl) {
        std::string strURL = std::string("https://games.roproxy.com/v1/games?universeIds=") + std::to_string(UniverseID);

        const char* url = strURL.c_str();
        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " 
                      << curl_easy_strerror(res) << std::endl;
        } else {
            try {
                Buff = json::parse(readBuffer);
            } catch (std::exception& e) {
                std::cerr << "JSON parsing error: " << e.what() << std::endl;
                return FAILURE;
            }
        }
    }

    return OK;
}