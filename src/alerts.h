/**
 * @file alerts.h
 * @brief Alerts - Alert processing and management
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ALERTS_H
#define ALERTS_H

#include <string>
#include "logger.h"

class Alerts {
public:
    Alerts();
    ~Alerts();
    
    /**
     * @brief Initialize alert service
     * @return true if successful, false otherwise
     * 
     * Log entry: alerts.cpp 0082 initialize - Running ALERT Retriever thread
     * Log entry: alerts.cpp 0084 initialize - ALERTS STARTING
     * Log entry: alerts.cpp 0086 initialize - Sync from Q thread started
     */
    bool initialize();
    
    /**
     * @brief Process pending alerts
     * @return Number of alerts processed
     */
    int processAlerts();

private:
    bool m_initialized;
    bool m_retrieverRunning;
    bool m_syncThreadRunning;
};

#endif // ALERTS_H
