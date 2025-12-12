#ifndef REDISCONNECTIONMGR_H
#define REDISCONNECTIONMGR_H

#include <string>

// Redis Connection Manager - handles Redis cache operations
class RedisConnectionMgr {
public:
    static RedisConnectionMgr& getInstance();

    // Get a value by key from Redis
    bool getValue(const std::string& key, const std::string& threadId, std::string& value);

    // Set a value in Redis
    bool setValue(const std::string& key, const std::string& value, const std::string& threadId);

private:
    RedisConnectionMgr() = default;
    RedisConnectionMgr(const RedisConnectionMgr&) = delete;
    RedisConnectionMgr& operator=(const RedisConnectionMgr&) = delete;
};

#endif // REDISCONNECTIONMGR_H
