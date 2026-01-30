// redisconnectionmgr.cpp
#include <iostream>
#include <string>
#include <hiredis/hiredis.h>

class RedisConnectionManager {
public:
    RedisConnectionManager(const std::string& host, int port) : host_(host), port_(port) {}

    bool connect() {
        context_ = redisConnect(host_.c_str(), port_);
        if (context_ == nullptr || context_->err) {
            if (context_) {
                std::cerr << "Error: " << context_->errstr << std::endl;
                redisFree(context_);
            } else {
                std::cerr << "Can't allocate redis context" << std::endl;
            }
            return false;
        }
        return true;
    }

    redisContext* getContext() {
        return context_;
    }

    ~RedisConnectionManager() {
        if (context_) {
            redisFree(context_);
        }
    }

private:
    std::string host_;
    int port_;
    redisContext* context_ = nullptr;
};

int main() {
    RedisConnectionManager manager("127.0.0.1", 6379);
    if (!manager.connect()) {
        return 1;
    }
    // Additional logic for using the connection
    return 0;
}