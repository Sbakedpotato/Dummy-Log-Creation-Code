/**
 * @file productchanneltran.h
 * @brief Product Channel Transaction - Channel/Transaction configuration
 * 
 * Reconstructed from log file analysis.
 */

#ifndef PRODUCTCHANNELTRAN_H
#define PRODUCTCHANNELTRAN_H

#include <string>
#include "logger.h"

class ProductChannelTran {
public:
    ProductChannelTran();
    ~ProductChannelTran();
    
    /**
     * @brief Check product channel transaction configuration
     * @param logId Transaction log ID
     * @param productId Product ID
     * @param channelId Channel ID
     * @param tranCode Transaction code
     * @return true if found, false otherwise
     * 
     * Log entry: productchanneltran 0216 CheckProductCh - Record found for Key [ProductID + ChannelID + TranCode X
     */
    bool CheckProductChannelTran(const std::string& logId, const std::string& productId,
                                  const std::string& channelId, const std::string& tranCode);

private:
    std::string m_productId;
    std::string m_channelId;
    std::string m_tranCode;
};

#endif // PRODUCTCHANNELTRAN_H
