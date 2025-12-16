/**
 * @file loadbalancer.cpp
 * @brief Load Balancer implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "loadbalancer.h"

LoadBalancer::LoadBalancer() 
    : m_commsStatus(1)
    , m_processingStatus(1)
    , m_processingMode(1) {
}

LoadBalancer::~LoadBalancer() {
}

bool LoadBalancer::doWork(const std::string& logId) {
    LOG_INFO("loadbalancer.cpp", "0120", "doWork", logId,
             "Comms Status [" + std::to_string(m_commsStatus) + 
             "], processing status [" + std::to_string(m_processingStatus) + 
             "], processing Mode [" + std::to_string(m_processingMode) + "]");
    return true;
}

int LoadBalancer::getCommsStatus() const {
    return m_commsStatus;
}

int LoadBalancer::getProcessingStatus() const {
    return m_processingStatus;
}

int LoadBalancer::getProcessingMode() const {
    return m_processingMode;
}
