#ifndef REDISCACHE_H
#define REDISCACHE_H

#include <string>

// Redis Cache - high-level cache operations
class RedisCache {
public:
    static RedisCache& getInstance();

    // Find a value by key in the cache
    bool find(const std::string& key, const std::string& threadId, std::string& value);

    // Store a value in the cache
    bool store(const std::string& key, const std::string& value, const std::string& threadId);

private:
    RedisCache() = default;
    RedisCache(const RedisCache&) = delete;
    RedisCache& operator=(const RedisCache&) = delete;
};

#endif // REDISCACHE_H
