/**
 * @file connectionstring.cpp
 * @brief Connection String Parser implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "connectionstring.h"

ConnectionString::ConnectionString() 
    : m_port(1521) {
}

ConnectionString::~ConnectionString() {
}

bool ConnectionString::parseConnectionString(const std::string& connectionString) {
    // Parse format: username/password@host:port/database
    // Example: iris/******@10.100.53.26:1521/CMSATM
    
    size_t atPos = connectionString.find('@');
    if (atPos != std::string::npos) {
        std::string credentials = connectionString.substr(0, atPos);
        std::string hostPart = connectionString.substr(atPos + 1);
        
        // Parse credentials
        size_t slashPos = credentials.find('/');
        if (slashPos != std::string::npos) {
            m_username = credentials.substr(0, slashPos);
            m_password = credentials.substr(slashPos + 1);
        }
        
        // Parse host:port/database
        size_t colonPos = hostPart.find(':');
        if (colonPos != std::string::npos) {
            m_host = hostPart.substr(0, colonPos);
            
            size_t dbSlashPos = hostPart.find('/', colonPos);
            if (dbSlashPos != std::string::npos) {
                m_port = std::stoi(hostPart.substr(colonPos + 1, dbSlashPos - colonPos - 1));
                m_database = hostPart.substr(dbSlashPos + 1);
            }
        }
    }
    
    // Log the parsed credentials (masking password)
    std::string maskedCredentials = m_username + "/******@" + m_host + ":" + 
                                    std::to_string(m_port) + "/" + m_database;
    LOG_INFO("connectionstring.c", "0506", "parseConnectio", "",
             "Database credentials: " + maskedCredentials);
    
    return true;
}
