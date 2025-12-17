/**
 * @file connectionstring.h
 * @brief Connection String Parser - Parses database connection strings
 * 
 * Reconstructed from log file analysis.
 */

#ifndef CONNECTIONSTRING_H
#define CONNECTIONSTRING_H

#include <string>
#include "logger.h"

class ConnectionString {
public:
    ConnectionString();
    ~ConnectionString();
    
    /**
     * @brief Parse connection string
     * @param connectionString The connection string to parse
     * @return true if successful, false otherwise
     * 
     * Log entry: connectionstring.c 0506 parseConnectio - Database credentials: X/******@X
     */
    bool parseConnectionString(const std::string& connectionString);
    
    std::string getUsername() const { return m_username; }
    std::string getHost() const { return m_host; }
    int getPort() const { return m_port; }
    std::string getDatabase() const { return m_database; }

private:
    std::string m_username;
    std::string m_password;
    std::string m_host;
    int m_port;
    std::string m_database;
};

#endif // CONNECTIONSTRING_H
