/**
 * @file cmschannel.h
 * @brief CMS Channel - Card Management System channel configuration
 * 
 * Reconstructed from log file analysis.
 */

#ifndef CMSCHANNEL_H
#define CMSCHANNEL_H

#include <string>
#include "logger.h"

class CMSChannel {
public:
    CMSChannel();
    ~CMSChannel();
    
    /**
     * @brief Fetch single record from database
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: cmschannel.cpp 0349 fetchSingleRec - CMSchannel loaded successfully
     */
    bool fetchSingleRecord(const std::string& logId);
    
    /**
     * @brief Get CMS channel attributes
     * @param logId Transaction log ID
     * 
     * Log entry: cmschannel.cpp 0180 getCMSChannela - channelType[X]
     * Log entry: cmschannel.cpp 0181 getCMSChannela - channelCode[X]
     */
    void getCMSChannelAttributes(const std::string& logId);
    
    /**
     * @brief Check if consent is required
     * @param logId Transaction log ID
     * @return true if required, false otherwise
     * 
     * Log entry: cmschannel.cpp 0144 isConsentRequi - Consent Not Required
     */
    bool isConsentRequired(const std::string& logId);

    std::string getChannelType() const { return m_channelType; }
    std::string getChannelCode() const { return m_channelCode; }

private:
    std::string m_channelType;
    std::string m_channelCode;
    bool m_consentRequired;
};

#endif // CMSCHANNEL_H
