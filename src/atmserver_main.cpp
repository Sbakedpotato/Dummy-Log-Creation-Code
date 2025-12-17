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
    // Initialize endpoint
    m_endpoint = "";
}

ATMServerMain::~ATMServerMain() {
}

// New function to validate endpoint
bool ATMServerMain::validateEndpoint(const std::string& endpoint) {
    // Check if endpoint is empty
    if (endpoint.empty()) {
        LOG_ERROR("atmserver_main.cpp", "0568", "validateEndpoint", "", "Endpoint is empty");
        return false;
    }
    // Additional validation logic can be added here
    return true;
}

bool ATMServerMain::connectToRedis(const std::string& host, int port) {
    // Validate endpoint before connecting to Redis
    if (!validateEndpoint(host)) {
        return false;
    }
    m_redisHost = host;
    m_redisPort = port;
    
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
    
    // Validate endpoint before proceeding
    if (!validateEndpoint(m_endpoint)) {
        LOG_ERROR("atmserver_main.cpp", "0590", "main", "", "Endpoint is empty");
        return -1;
    }
    
    return 0;
}
