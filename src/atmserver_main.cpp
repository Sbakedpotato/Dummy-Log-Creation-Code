/**
 * @file atmserver_main.cpp
 * @brief ATM Server Main implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "atmserver_main.h"

ATMServerMain::ATMServerMain() 
    : m_redisHost("127.0.0.1")
    , m_redisPort(1337)
    , m_pollingTime(0)
    , m_pollingCounter(0) {
}

ATMServerMain::~ATMServerMain() {
}

bool ATMServerMain::connectToRedis(const std::string& host, int port) {
    m_redisHost = host;
    m_redisPort = port;
    
    // Check if endpoint is set before connecting to Redis
    if (m_endpoint.empty()) {
        LOG_ERROR("atmserver_main.cpp", "0378", "connectToRedis", "", "Endpoint is not set");
        return false;
    }
    
    LOG_INFO("atmserver_main.cpp", "0377", "connectToRedis", "",
             host + " , port [" + std::to_string(port) + "]");
    return true;
}

int ATMServerMain::main() {
    LOG_INFO("atmserver_main.cpp", "0479", "main", "", "Run Program");
    
    // Check polling configuration
    if (m_pollingTime == 0) {
        LOG_ERROR("atmserver_main.cpp", "0568", "main", "",
                  "Polling not defined in param, setting default polling time");
        m_pollingTime = 5000; // Default 5 seconds
    }
    
    if (m_pollingCounter == 0) {
        LOG_ERROR("atmserver_main.cpp", "0582", "main", "",
                  "Polling not defined in param, setting default polling counter");
        m_pollingCounter = 10;
    }
    
    return 0;
}
