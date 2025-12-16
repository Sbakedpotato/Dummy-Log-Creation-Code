#include "rediscache.h"
#include "redisconnectionmgr.h"
#include "logger.h"

RedisCache& RedisCache::getInstance() {
    static RedisCache instance;
    return instance;
}

bool RedisCache::find(const std::string& key, const std::string& threadId, std::string& value) {
    // Try to get from Redis connection manager
    if (!RedisConnectionMgr::getInstance().getValue(key, threadId, value)) {
        LOG_ERROR("rediscache.cpp", 91, "find", threadId, 
                  "Unable to find key:" + key);
        return false;
    }
    
    return true;
}

bool RedisCache::store(const std::string& key, const std::string& value, const std::string& threadId) {
    return RedisConnectionMgr::getInstance().setValue(key, value, threadId);
}
