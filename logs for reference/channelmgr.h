/**
 * @file channelmgr.h
 * @brief Channel Manager - Manages communication channels for the payment switch
 * 
 * Reconstructed from log file analysis.
 */

#ifndef CHANNELMGR_H
#define CHANNELMGR_H

#include <string>
#include "logger.h"

class ChannelMgr {
public:
    ChannelMgr();
    ~ChannelMgr();
    
    /**
     * @brief Get destination channel with failsafe handling
     * @param logId Transaction log ID
     * @return true if destination found, false otherwise
     * 
     * Log entry: channelmgr.cpp 0560 getDestination - Failsafe & default handling
     */
    bool getDestinationChannel(const std::string& logId);
    
    /**
     * @brief Fetch channel configuration from database
     * @param logId Transaction log ID
     * @param channelId Channel identifier
     * @return true if successful, false otherwise
     * 
     * Log entry: channelmgr.cpp 0253 fetchFromDB - Initializing channel [X]
     */
    bool fetchFromDB(const std::string& logId, const std::string& channelId);
    
    /**
     * @brief Get channel ID by criteria
     * @param logId Transaction log ID
     * @return Channel ID string
     * 
     * Log entry: channelmgr.cpp 0734 getChannelIDby - channelList is empty no detail found.
     */
    std::string getChannelIDby(const std::string& logId);
    
    /**
     * @brief Get network for channel
     * @param logId Transaction log ID
     * @param channelId Channel identifier
     * @return Network ID or empty if not found
     * 
     * Log entry: channelmgr.cpp 0535 getDestination - Failed getting network for channel [X], no networks configured
     */
    std::string getNetworkForChannel(const std::string& logId, const std::string& channelId);

private:
    std::string m_currentChannel;
    bool m_initialized;
};

#endif // CHANNELMGR_H
