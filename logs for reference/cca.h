/**
 * @file cca.h
 * @brief Card/Customer Account Manager - Handles account validation and limits
 * 
 * Reconstructed from log file analysis.
 */

#ifndef CCA_H
#define CCA_H

#include <string>
#include "logger.h"

class CCA {
public:
    CCA();
    ~CCA();
    
    /**
     * @brief Validate account information
     * @param logId Transaction log ID
     * @param accountId Account ID
     * @param accountType Account type
     * @param accountCurrency Account currency
     * @return true if valid, false otherwise
     * 
     * Log entry: cca.cpp 1102 validateAccoun - account id = [X] , account Type = [X] , account currency = [X]
     * Log entry: cca.cpp 1111 validateAccoun - Account Successfully Validated
     */
    bool validateAccount(const std::string& logId, const std::string& accountId,
                         const std::string& accountType, const std::string& accountCurrency);
    
    /**
     * @brief Check if transaction is blacklisted
     * @param logId Transaction log ID
     * @return true if blacklisted, false otherwise
     * 
     * Log entry: cca.cpp 2777 validateBlackL - isBlacklisted = []
     * Log entry: cca.cpp 2779 validateBlackL - Transaction is not blacklisted
     */
    bool validateBlacklist(const std::string& logId);
    
    /**
     * @brief Check transaction limits
     * @param logId Transaction log ID
     * @param amount Transaction amount
     * @return true if within limits, false otherwise
     * 
     * Log entry: cca.cpp 1189 checkLimit - Parameter not found
     * Log entry: cca.cpp 1198 checkLimit - Current System UTC DateTime[X]
     * Log entry: cca.cpp 1199 checkLimit - Current Institution DateTime[X]
     * Log entry: cca.cpp 1329 checkLimit - sIndividualLimit = false
     * Log entry: cca.cpp 1345 checkLimit - Old remaining amount X
     * Log entry: cca.cpp 1586 checkLimit - Limits applied
     */
    bool checkLimit(const std::string& logId, long amount);
    
    /**
     * @brief Update transaction limits after transaction
     * @param logId Transaction log ID
     * @param relationshipId Card/account relationship ID
     * 
     * Log entry: cca.cpp 3014 updateLimits - Limit remainingAmount = [X]
     * Log entry: cca.cpp 3017 updateLimits - Limit remainingFrequency = [X]
     * Log entry: cca.cpp 3020 updateLimits - AmountCycleBeginDate = [X]
     * Log entry: cca.cpp 3052 updateLimits - Updating limitX
     */
    void updateLimits(const std::string& logId, const std::string& relationshipId);
    
    /**
     * @brief Reverse limits after failed/reversed transaction
     * @param logId Transaction log ID
     * 
     * Log entry: cca.cpp 1749 reverseLimit - sIndividualLimit = false
     * Log entry: cca.cpp 1771 reverseLimit - Limits reversed
     */
    void reverseLimit(const std::string& logId);

private:
    long m_remainingAmount;
    int m_remainingFrequency;
    std::string m_cycleBeginDate;
    bool m_isBlacklisted;
};

#endif // CCA_H
