#include "redisconnectionmgr.h"
#include "logger.h"
#include <hiredis/hiredis.h>

RedisConnectionMgr& RedisConnectionMgr::getInstance() {
    static RedisConnectionMgr instance;
    return instance;
}

bool RedisConnectionMgr::getValue(const std::string& key, const std::string& threadId, std::string& value) {
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if (context == nullptr || context->err) {
        LOG_ERROR("redisconnectionmgr", 864, "getValue", threadId, "Redis connection error");
        return false;
    }
    redisReply* reply = (redisReply*)redisCommand(context, "GET %s", key.c_str());
    if (reply == nullptr) {
        LOG_ERROR("redisconnectionmgr", 864, "getValue", threadId, "Redis command error");
        redisFree(context);
        return false;
    }
    if (reply->type == REDIS_REPLY_STRING) {
        value = reply->str;
        freeReplyObject(reply);
        redisFree(context);
        return true;
    } else {
        LOG_ERROR("redisconnectionmgr", 864, "getValue", threadId, "No record found");
        freeReplyObject(reply);
        redisFree(context);
        return false;
    }
}

bool RedisConnectionMgr::setValue(const std::string& key, const std::string& value, const std::string& threadId) {
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if (context == nullptr || context->err) {
        LOG_ERROR("redisconnectionmgr", 865, "setValue", threadId, "Redis connection error");
        return false;
    }
    redisReply* reply = (redisReply*)redisCommand(context, "SET %s %s", key.c_str(), value.c_str());
    if (reply == nullptr) {
        LOG_ERROR("redisconnectionmgr", 865, "setValue", threadId, "Redis command error");
        redisFree(context);
        return false;
    }
    freeReplyObject(reply);
    redisFree(context);
    return true;
}