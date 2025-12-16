/**
 * @file loadbalancer.h
 * @brief Load Balancer - Handles connection load balancing and status
 * 
 * Reconstructed from log file analysis.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include "logger.h"

class LoadBalancer {
public:
    LoadBalancer();
    ~LoadBalancer();
    
    /**
     * @brief Perform load balancing work
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: loadbalancer.cpp 0120 doWork - Comms Status [X], processing status [X], processing Mode [X]
     */
    bool doWork(const std::string& logId);
    
    /**
     * @brief Get communication status
     * @return Communication status (1 = online, 0 = offline)
     */
    int getCommsStatus() const;
    
    /**
     * @brief Get processing status
     * @return Processing status (1 = active, 0 = inactive)
     */
    int getProcessingStatus() const;
    
    /**
     * @brief Get processing mode
     * @return Processing mode (1 = normal, 2 = failover, etc.)
     */
    int getProcessingMode() const;

private:
    int m_commsStatus;
    int m_processingStatus;
    int m_processingMode;
};

#endif // LOADBALANCER_H
