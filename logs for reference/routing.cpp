/**
 * @file routing.cpp
 * @brief Routing Manager implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "routing.h"

Routing::Routing() : m_destinationChannelID("401") {
}

Routing::~Routing() {
}

std::string Routing::getRoutingInfo(const std::string& logId, const std::string& routingTag,
                                     const std::string& tranCode, const std::string& srcChannelID) {
    if (getRouting(logId, routingTag, tranCode, srcChannelID)) {
        LOG_INFO("routing.cpp", "0489", "getRoutingInfo", logId,
                 "Routing found and destinationChannelID = [" + m_destinationChannelID + "]");
        return m_destinationChannelID;
    } else {
        LOG_ERROR("routing.cpp", "0480", "getRoutingInfo", logId,
                  "Routing not found for Routing Tag = [" + routingTag + 
                  "], transactionCode = [" + tranCode + 
                  "], srcChannelID = [" + srcChannelID + "]");
        return "";
    }
}

bool Routing::getRouting(const std::string& logId, const std::string& key,
                         const std::string& tranCode, const std::string& srcChannelID) {
    // Simulate routing lookup - in real system this would check cache/database
    // Some transaction codes are not supported
    if (tranCode == "00" && (key.find("47612699990") != std::string::npos || 
                              key.find("40055299990") != std::string::npos)) {
        LOG_ERROR("routing.cpp", "0435", "getRouting", logId,
                  "Key [" + key + "] tranCode [" + tranCode + 
                  "] srcChannelID[" + srcChannelID + "] not found");
        return false;
    }
    return true;
}
