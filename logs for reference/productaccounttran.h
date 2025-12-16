/**
 * @file productaccounttran.h
 * @brief Product Account Transaction - Account/Transaction configuration
 * 
 * Reconstructed from log file analysis.
 */

#ifndef PRODUCTACCOUNTTRAN_H
#define PRODUCTACCOUNTTRAN_H

#include <string>
#include "logger.h"

class ProductAccountTran {
public:
    ProductAccountTran();
    ~ProductAccountTran();
    
    /**
     * @brief Fetch from database
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: productaccounttran 0137 fetchFromDB - Loading Product_Account_Tran
     */
    bool fetchFromDB(const std::string& logId);
    
    /**
     * @brief Check product account transaction configuration
     * @param logId Transaction log ID
     * @param productId Product ID
     * @param channelId Channel ID
     * @param tranCode Transaction code
     * @param accountType Account type
     * @return true if found, false otherwise
     * 
     * Log entry: productaccounttran 0225 CheckProductAc - Record found for Key [ProductID + ChannelID + TranCode + Account Type X
     */
    bool CheckProductAccountTran(const std::string& logId, const std::string& productId,
                                  const std::string& channelId, const std::string& tranCode,
                                  const std::string& accountType);

private:
    std::string m_productId;
    std::string m_channelId;
    std::string m_tranCode;
    std::string m_accountType;
};

#endif // PRODUCTACCOUNTTRAN_H
