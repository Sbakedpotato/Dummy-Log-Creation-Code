/**
 * @file redisstreamsmgr.h
 * @brief Redis Streams Manager - Manages Redis stream connections
 * 
 * Reconstructed from log file analysis.
 */

#ifndef REDISSTREAMSMGR_H
#define REDISSTREAMSMGR_H

#include <string>
#include "logger.h"

class RedisStreamsMgr {
public:
    RedisStreamsMgr();
    ~RedisStreamsMgr();
    
    /**
     * @brief Constructor log
     * 
     * Log entry: redisstreamsmgr.cp 0043 RedisStreams - Creating new instance of Redis QueueMgr
     */
    void RedisStreamsInstance();
    
    /**
     * @brief Check connection status
     * @return true if connected, false otherwise
     * 
     * Log entry: redisstreamsmgr.cp 0503 checkConnectio - Connecting to redis
     */
    bool checkConnection();
    
    /**
     * @brief Connect to Redis stream
     * @param host Redis host
     * @param port Redis port
     * @return true if successful, false otherwise
     * 
     * Log entry: redisstreamsmgr.cp 0564 connectStream - Connecting to redis host [X], port [X]
     * Log entry: redisstreamsmgr.cp 0581 connectStream - Successfully connected to redis
     */
    bool connectStream(const std::string& host, int port);

private:
    std::string m_host;
    int m_port;
    bool m_connected;
};

#endif // REDISSTREAMSMGR_H
