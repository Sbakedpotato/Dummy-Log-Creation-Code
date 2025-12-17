/**
 * @file atmserver_main.h
 * @brief ATM Server Main - Main entry point for ATM server process
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ATMSERVER_MAIN_H
#define ATMSERVER_MAIN_H

#include <string>
#include "logger.h"

class ATMServerMain {
public:
    ATMServerMain();
    ~ATMServerMain();
    
    /**
     * @brief Connect to Redis server
     * @param host Redis host address
     * @param port Redis port
     * @return true if successful, false otherwise
     * 
     * Log entry: atmserver_main.cpp 0377 connectToRedis - X , port [X]
     */
    bool connectToRedis(const std::string& host, int port);
    
    /**
     * @brief Main entry point
     * @return Exit code
     * 
     * Log entry: atmserver_main.cpp 0479 main - Run Program
     * Log entry: atmserver_main.cpp 0568 main - Polling not defined in param, setting default polling time
     * Log entry: atmserver_main.cpp 0582 main - Polling not defined in param, setting default polling counter
     */
    int main();

private:
    std::string m_redisHost;
    int m_redisPort;
    int m_pollingTime;
    int m_pollingCounter;
};

#endif // ATMSERVER_MAIN_H
