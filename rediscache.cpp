// rediscache.cpp
#include <iostream>
#include <string>
#include <hiredis/hiredis.h>
#include "redisconnectionmgr.cpp"

class RedisCache {
public:
    RedisCache(RedisConnectionManager& connManager) : connManager_(connManager) {}

    std::string getValue(const std::string& key) {
        redisContext* context = connManager_.getContext();
        redisReply* reply = (redisReply*)redisCommand(context, "GET %s", key.c_str());
        if (reply == nullptr) {
            std::cerr << "Error fetching value for key: " << key << std::endl;
            return "";
        }
        std::string value = reply->str ? reply->str : "";
        freeReplyObject(reply);
        return value;
    }

private:
    RedisConnectionManager& connManager_;
};

int main() {
    RedisConnectionManager manager("127.0.0.1", 6379);
    if (!manager.connect()) {
        return 1;
    }
    RedisCache cache(manager);
    std::string value = cache.getValue("some_key");
    std::cout << "Value: " << value << std::endl;
    return 0;
}