/**
 * @file onelinkiss.h
 * @brief 1Link Issuer - 1Link network issuer processing
 * 
 * Reconstructed from log file analysis.
 */

#ifndef ONELINKISS_H
#define ONELINKISS_H

#include <string>
#include "logger.h"

class OneLinkIss {
public:
    OneLinkIss();
    ~OneLinkIss();
    
    /**
     * @brief Check if customer consent is required
     * @param logId Transaction log ID
     * @param tranCode Transaction code
     * @param channelType Channel type
     * 
     * Log entry: onelinkiss.cpp 5578 checkCustomerC - Checking if consent required trancode [X] , channel type [X]
     */
    void checkCustomerConsent(const std::string& logId, const std::string& tranCode,
                               const std::string& channelType);
    
    /**
     * @brief Perform customer validations
     * @param logId Transaction log ID
     * @param relationshipId Relationship ID
     * @return true if valid, false otherwise
     * 
     * Log entry: onelinkiss.cpp 2330 performCustome - Populating Product Detail Record
     * Log entry: onelinkiss.cpp 2395 performCustome - Validating card of relationship id = [X]
     * Log entry: onelinkiss.cpp 2452 performCustome - Validating account of account id = [X] [X] [X]
     */
    bool performCustomerValidations(const std::string& logId, const std::string& relationshipId);
    
    /**
     * @brief Get destination network
     * @param logId Transaction log ID
     * @param networkId Network ID
     * @param channelId Channel ID
     * @return true if host online, false otherwise
     * 
     * Log entry: onelinkiss.cpp 3622 getDestination - Get Network processing status network ID [X], channelID [X]
     * Log entry: onelinkiss.cpp 3648 getDestination - Host is online
     */
    bool getDestinationNetwork(const std::string& logId, const std::string& networkId,
                                const std::string& channelId);
    
    /**
     * @brief Process rejection
     * @param logId Transaction log ID
     * 
     * Log entry: onelinkiss.cpp 1546 processRejecti - Inserting transaction in database
     */
    void processRejection(const std::string& logId);
    
    /**
     * @brief Send to acquirer
     * @param logId Transaction log ID
     * 
     * Log entry: onelinkiss.cpp 4711 sendToAcquirer - Removing transaction from in-memory database
     */
    void sendToAcquirer(const std::string& logId);

private:
    bool m_hostOnline;
};

#endif // ONELINKISS_H
