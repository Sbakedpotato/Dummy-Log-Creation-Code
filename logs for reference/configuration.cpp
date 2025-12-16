#include "configuration.h"
#include "logger.h"
#include "rediscache.h"

Configuration& Configuration::getInstance() {
    static Configuration instance;
    return instance;
}

std::string Configuration::getParamValue(const std::string& key, const std::string& threadId) {
    std::string value;
    std::string cacheKey = "Configuration_" + key;
    
    // Try to find in Redis cache first
    if (!RedisCache::getInstance().find(cacheKey, threadId, value)) {
        LOG_ERROR("configuration.cpp", 201, "getParamValue", threadId, 
                  "Could not find corresponding parameter for key = [" + key + "]");
        return "";
    }
    
    return value;
}
