/**
 * @file product.h
 * @brief Product Manager - Handles product configuration and details
 * 
 * Reconstructed from log file analysis.
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "logger.h"

class Product {
public:
    Product();
    ~Product();
    
    /**
     * @brief Fetch product from database
     * @param logId Transaction log ID
     * @param productId Product ID
     * @return true if successful, false otherwise
     * 
     * Log entry: product.cpp 0177 fetchFromDB - ProductID = [X] , ProductName = [X] , ProductType = [X]
     */
    bool fetchFromDB(const std::string& logId, const std::string& productId);
    
    std::string getProductId() const { return m_productId; }
    std::string getProductName() const { return m_productName; }
    std::string getProductType() const { return m_productType; }

private:
    std::string m_productId;
    std::string m_productName;
    std::string m_productType;
};

#endif // PRODUCT_H
