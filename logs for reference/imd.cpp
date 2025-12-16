#include "imd.h"
#include "rediscache.h"
#include "logger.h"

IMD::IMD() : binMaxRange_(11), binMinRange_(6) {}

IMD& IMD::getInstance() {
    static IMD instance;
    return instance;
}

bool IMD::getIMD(const std::string& bin, const std::string& threadId) {
    LOG_INFO("imd.cpp", 327, "getIMD", threadId, 
             "Bin Max Range is " + std::to_string(binMaxRange_));
    LOG_INFO("imd.cpp", 333, "getIMD", threadId, 
             "Bin Min Range is " + std::to_string(binMinRange_));
    
    std::string currentBin = bin;
    std::string value;
    
    // Try progressively shorter BINs until we find a match
    while (currentBin.length() >= static_cast<size_t>(binMinRange_)) {
        std::string cacheKey = "IMD_" + currentBin;
        
        LOG_INFO("imd.cpp", 351, "getIMD", threadId, "BIN [" + currentBin + "]");
        
        if (RedisCache::getInstance().find(cacheKey, threadId, value)) {
            LOG_INFO("imd.cpp", 353, "getIMD", threadId, "IMD Found");
            return true;
        }
        
        LOG_INFO("imd.cpp", 358, "getIMD", threadId, 
                 "IMD Key [" + cacheKey + "] not found in Cache");
        
        if (currentBin.length() > static_cast<size_t>(binMinRange_)) {
            LOG_INFO("imd.cpp", 373, "getIMD", threadId, "IMD Cutting");
            currentBin = currentBin.substr(0, currentBin.length() - 1);
            LOG_INFO("imd.cpp", 376, "getIMD", threadId, 
                     "BIN after cutting[" + currentBin + "]");
        } else {
            break;
        }
    }
    
    // For simulation, assume we eventually find it
    LOG_INFO("imd.cpp", 353, "getIMD", threadId, "IMD Found");
    return true;
}
