/**
 * @file alert_main.h
 * @brief Alert Main - Main entry point for alert service
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ALERT_MAIN_H
#define ALERT_MAIN_H

#include <string>
#include "logger.h"

class AlertMain {
public:
    AlertMain();
    ~AlertMain();
    
    /**
     * @brief Start alert service
     * @return true if successful, false otherwise
     * 
     * Log entry: alert_main.cpp 0110 startAlerts - Starting ALERTS
     */
    bool startAlerts();

private:
    bool m_alertsRunning;
};

#endif // ALERT_MAIN_H
