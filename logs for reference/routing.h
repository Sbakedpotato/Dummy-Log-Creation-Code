/**
 * @file routing.h
 * @brief Routing Manager - Handles transaction routing based on BIN/routing tags
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ROUTING_H
#define ROUTING_H

#include <string>
#include "logger.h"

class Routing {
public:
    Routing();
    ~Routing();
    
    /**
     * @brief Get routing information for a transaction
     * @param logId Transaction log ID
     * @param routingTag BIN/routing tag
     * @param tranCode Transaction code
     * @param srcChannelID Source channel ID
     * @return Destination channel ID or empty if not found
     * 
     * Log entry: routing.cpp 0489 getRoutingInfo - Routing found and destinationChannelID = [X]
     */
    std::string getRoutingInfo(const std::string& logId, const std::string& routingTag,
                                const std::string& tranCode, const std::string& srcChannelID);
    
    /**
     * @brief Get routing from cache/database
     * @param logId Transaction log ID
     * @param key Routing key
     * @param tranCode Transaction code
     * @param srcChannelID Source channel ID
     * @return true if routing found, false otherwise
     * 
     * Log entry: routing.cpp 0435 getRouting - Key [X] tranCode [X] srcChannelID[X] not found
     */
    bool getRouting(const std::string& logId, const std::string& key,
                    const std::string& tranCode, const std::string& srcChannelID);

private:
    std::string m_destinationChannelID;
};

#endif // ROUTING_H
