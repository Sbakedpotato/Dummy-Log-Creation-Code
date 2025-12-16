/**
 * @file translator1linkiso.h
 * @brief 1Link ISO Translator - 1Link ISO 8583 message translator
 * 
 * Reconstructed from log file analysis.
 */

#ifndef TRANSLATOR1LINKISO_H
#define TRANSLATOR1LINKISO_H

#include <string>
#include "translator.h"
#include "logger.h"

class Translator1LinkISO : public Translator {
public:
    Translator1LinkISO();
    virtual ~Translator1LinkISO();
    
    /**
     * @brief Get source channel ID
     * @param logId Transaction log ID
     * @return Source channel ID
     * 
     * Log entry: translator1linkiso 1406 getSourceChann - sourceChannelID [X]
     * Log entry: translator1linkiso 1414 getSourceChann - sourceChannelID [X]
     */
    std::string getSourceChannelID(const std::string& logId);
    
    /**
     * @brief Set processing code
     * @param logId Transaction log ID
     * @param tranCode Transaction code
     * @return true if supported, false otherwise
     * 
     * Log entry: translator1linkiso 0626 setProcessingC - tranCode [X]
     * Log entry: translator1linkiso 0670 setProcessingC - Transaction code not supported
     */
    bool setProcessingCode(const std::string& logId, const std::string& tranCode);
    
    /**
     * @brief Set original data elements for reversal
     * @param logId Transaction log ID
     * @return true if successful, false otherwise
     * 
     * Log entry: translator1linkiso 1332 setOriginalDat - Unable to make original data elements, cannot send reversal
     */
    bool setOriginalDataElements(const std::string& logId);

private:
    std::string m_sourceChannelID;
};

#endif // TRANSLATOR1LINKISO_H
