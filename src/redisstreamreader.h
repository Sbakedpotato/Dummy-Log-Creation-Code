/**
 * @file redisstreamreader.h
 * @brief Redis Stream Reader - Reads from Redis streams
 * 
 * Reconstructed from log file analysis.
 */

#ifndef REDISSTREAMREADER_H
#define REDISSTREAMREADER_H

#include <string>
#include "logger.h"

class RedisStreamReader {
public:
    RedisStreamReader();
    ~RedisStreamReader();
    
    /**
     * @brief Connect to Redis stream
     * @param connectionString Connection string (host:port)
     * @return true if successful, false otherwise
     * 
     * Log entry: redisstreamreader. 0204 connect - Connecting redis stream reader on [X]
     * Log entry: redisstreamreader. 0213 connect - X
     */
    bool connect(const std::string& connectionString);
    
    /**
     * @brief Callback when connected
     * @param streamName Stream name
     * 
     * Log entry: redisstreamreader. 0419 onConnect - Reader Connected -> X
     */
    void onConnect(const std::string& streamName);
    
    /**
     * @brief Create consumer group
     * @param groupName Group name
     * @return true if successful, false otherwise
     * 
     * Log entry: redisstreamreader. 0286 createGroup - Creating group [X]
     * Log entry: redisstreamreader. 0276 groupCallback - Group created
     */
    bool createGroup(const std::string& groupName);
    
    /**
     * @brief Handle authentication
     * @return true if successful, false otherwise
     * 
     * Log entry: redisstreamreader. 0389 handleAuth - ERR AUTH <password> called without any password configured...
     */
    bool handleAuth();
    
    /**
     * @brief Handle stream read events
     * @param channelId Channel identifier
     * 
     * Log entry: redisstreamreader. 0344 handleStreamRe - X
     */
    void handleStreamRead(const std::string& channelId);

private:
    std::string m_host;
    int m_port;
    bool m_connected;
    std::string m_currentGroup;
};

#endif // REDISSTREAMREADER_H
