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
    
    // Validate endpoint data before running the program
    if (!validateEndpoint(m_redisHost)) {
        LOG_ERROR("atmserver_main.cpp", "0590", "main", "", "Endpoint is empty, cannot run program");
        return -1;
    }
    
    return 0;
}
