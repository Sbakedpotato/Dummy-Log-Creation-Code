/**
 * @file productdetail.h
 * @brief Product Detail - Detailed product configuration
 * 
 * Reconstructed from log file analysis.
 */

#ifndef PRODUCTDETAIL_H
#define PRODUCTDETAIL_H

#include <string>
#include "logger.h"

class ProductDetail {
public:
    ProductDetail();
    ~ProductDetail();
    
    /**
     * @brief Get product detail record
     * @param logId Transaction log ID
     * @param productId Product ID
     * @return true if found, false otherwise
     * 
     * Log entry: productdetail.cpp 0207 GetProductDeta - Product Details Record found for Key [ProductID X]
     */
    bool GetProductDetail(const std::string& logId, const std::string& productId);
    
    /**
     * @brief Check if product is multicurrency
     * @param logId Transaction log ID
     * @param productId Product ID
     * @return true if multicurrency, false otherwise
     * 
     * Log entry: productdetail.cpp 0265 isMultiCurrenc - Not a multicurrency [ProductID =X]
     */
    bool isMultiCurrency(const std::string& logId, const std::string& productId);

private:
    std::string m_productId;
    bool m_isMultiCurrency;
};

#endif // PRODUCTDETAIL_H
