/**
 * @file event.h
 * @brief Event - Event handling and logging
 * 
 * Reconstructed from log file analysis.
 */

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "logger.h"

class Event {
public:
    Event();
    ~Event();
    
    /**
     * @brief Initialize event system
     * @return true if successful, false otherwise
     * 
     * Log entry: event.cpp 0067 initialize - IP X Machine X
     */
    bool initialize();
    
    std::string getIP() const { return m_ip; }
    std::string getMachine() const { return m_machine; }

private:
    std::string m_ip;
    std::string m_machine;
};

#endif // EVENT_H
