/**
 * @file redisconnection.h
 * @brief Redis Connection - Low-level Redis connection handler
 * 
 * Reconstructed from log file analysis.
 */

#ifndef REDISCONNECTION_H
#define REDISCONNECTION_H

#include <string>
#include "logger.h"

class RedisConnection {
public:
    RedisConnection();
    ~RedisConnection();
    
    /**
     * @brief Attempt to connect to Redis
     * @param host Redis host
     * @param port Redis port
     * @return true if successful, false otherwise
     * 
     * Log entry: redisconnection.cp 0024 RedisConnectio - Failed connecting to redis
     */
    bool connect(const std::string& host, int port);
    
    /**
     * @brief Check if connected
     * @return true if connected, false otherwise
     */
    bool isConnected() const;
    
    /**
     * @brief Disconnect from Redis
     */
    void disconnect();

private:
    std::string m_host;
    int m_port;
    bool m_connected;
};

#endif // REDISCONNECTION_H
