/**
 * @file productdetail.cpp
 * @brief Product Detail implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "productdetail.h"

ProductDetail::ProductDetail() : m_isMultiCurrency(false) {
}

ProductDetail::~ProductDetail() {
}

bool ProductDetail::GetProductDetail(const std::string& logId, const std::string& productId) {
    m_productId = productId;
    LOG_INFO("productdetail.cpp", "0207", "GetProductDeta", logId,
             "Product Details Record found for Key [ProductID " + productId + "]");
    return true;
}

bool ProductDetail::isMultiCurrency(const std::string& logId, const std::string& productId) {
    if (!m_isMultiCurrency) {
        LOG_ERROR("productdetail.cpp", "0265", "isMultiCurrenc", logId,
                  "Not a multicurrency [ProductID =" + productId + "]");
    }
    return m_isMultiCurrency;
}
