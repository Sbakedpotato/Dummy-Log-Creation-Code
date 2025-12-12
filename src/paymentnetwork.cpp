#include "paymentnetwork.h"
#include "rediscache.h"
#include "logger.h"

PaymentNetwork& PaymentNetwork::getInstance() {
    static PaymentNetwork instance;
    return instance;
}

std::string PaymentNetwork::getFRMSMode(const std::string& networkId, const std::string& threadId) {
    std::string cacheKey = "PAYMENTNETWORK_" + networkId + "_FMS_MODE";
    std::string frmsMode;
    
    // Try to find in cache
    RedisCache::getInstance().find(cacheKey, threadId, frmsMode);
    
    LOG_INFO("paymentnetwork.cpp", 177, "getFRMSMode", threadId, 
             "Payment Network Record got and FRMS Mode = [" + frmsMode + "]");
    
    return frmsMode;
}
