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
    // Input validation: check if host is empty
    if (host.empty()) {
        LOG_ERROR("atmserver_main.cpp", "0377", "connectToRedis", "",
                 "Host cannot be empty");
        return false;
    }
    m_redisHost = host;
    m_redisPort = port;
    
    LOG_INFO("atmserver_main.cpp", "0377", "connectToRedis", "",
             host + " , port [" + std::to_string(port) + "]");
    return true;
}

// New function to process commands with endpoint validation
bool ATMServerMain::processCommand(const std::string& endpoint) {
    // Input validation: check if endpoint is empty
    if (endpoint.empty()) {
        LOG_ERROR("atmserver_main.cpp", "0479", "processCommand", "",
                 "Endpoint cannot be empty");
        return false;
    }
    // Process command logic here
    LOG_INFO("atmserver_main.cpp", "0479", "processCommand", "",
             "Command processed successfully");
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


// === APPENDED FIX (original not found) ===
int ATMServerMain::main() {
    LOG_INFO("atmserver_main.cpp", "0479", "main", "",
             "Run Program");
    
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
    
    // Call processCommand function with endpoint validation
    if (!processCommand("example_endpoint")) {
        LOG_ERROR("atmserver_main.cpp", "0479", "main", "",
                  "Failed to process command");
    }
    
    return 0;
}