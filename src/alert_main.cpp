/**
 * @file alert_main.cpp
 * @brief Alert Main implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "alert_main.h"

AlertMain::AlertMain() : m_alertsRunning(false) {
}

AlertMain::~AlertMain() {
}

bool AlertMain::startAlerts() {
    LOG_INFO("alert_main.cpp", "0110", "startAlerts", "", "Starting ALERTS");
    m_alertsRunning = true;
    return true;
}
