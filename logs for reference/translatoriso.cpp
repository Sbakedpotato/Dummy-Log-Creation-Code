#include "translatoriso.h"
#include "logger.h"
#include <sstream>

bool TranslatorISO::parseMessage(const std::string& messageData, 
                                  Message& msg, 
                                  const std::string& threadId) {
    LOG_INFO("translatoriso.cpp", 34, "parseMessage", threadId, "Parsing Header");
    
    // Simulate header parsing
    LOG_INFO("translatoriso.cpp", 41, "parseMessage", threadId, "Header parsed successfully");
    
    LOG_INFO("translatoriso.cpp", 43, "parseMessage", threadId, "Parsing message fields");
    
    // Fill and show bitmap
    fillBitmap("", threadId);
    showBitmap(threadId);
    showBitmapFields(threadId);
    
    // Parse fields
    parseFields(messageData, msg, threadId);
    
    LOG_INFO("translatoriso.cpp", 50, "parseMessage", threadId, "Fields parsed successfully");
    
    return true;
}

bool TranslatorISO::buildMessage(Message& msg, 
                                  std::string& outputData, 
                                  const std::string& threadId) {
    LOG_INFO("translatoriso.cpp", 61, "buildMessage", threadId, "Start building message");
    
    // Build fields
    int position = 2;
    buildField("DE-2", "516067**********", "EBCDIC", position, threadId);
    position = 18;
    buildField("DE-3", "000000", "EBCDIC", position, threadId);
    position = 24;
    buildField("DE-4", "000000001000", "EBCDIC", position, threadId);
    position = 36;
    buildField("DE-5", "000000001000", "EBCDIC", position, threadId);
    position = 48;
    buildField("DE-7", "0918171152", "EBCDIC", position, threadId);
    position = 58;
    buildField("DE-9", "61000000", "EBCDIC", position, threadId);
    position = 66;
    buildField("DE-10", "61000000", "EBCDIC", position, threadId);
    position = 74;
    buildField("DE-11", "566611", "EBCDIC", position, threadId);
    position = 80;
    buildField("DE-12", "171152", "EBCDIC", position, threadId);
    position = 86;
    buildField("DE-13", "0918", "EBCDIC", position, threadId);
    position = 90;
    buildField("DE-15", "0918", "EBCDIC", position, threadId);
    position = 96;
    buildField("DE-32", "987654321", "EBCDIC", position, threadId);
    position = 107;
    buildField("DE-33", "9000000999", "EBCDIC", position, threadId);
    position = 117;
    buildField("DE-37", "335000100003", "EBCDIC", position, threadId);
    position = 129;
    buildField("DE-39", "41", "EBCDIC", position, threadId);
    position = 131;
    buildField("DE-41", "Term-A01", "EBCDIC", position, threadId);
    position = 139;
    buildField("DE-42", "ID-Code-A000001", "EBCDIC", position, threadId);
    position = 158;
    buildField("DE-49", "840", "EBCDIC", position, threadId);
    position = 161;
    buildField("DE-50", "840", "EBCDIC", position, threadId);
    position = 164;
    buildField("DE-51", "840", "EBCDIC", position, threadId);
    position = 173;
    buildField("DE-63", "MS1000006416", "EBCDIC", position, threadId);
    
    // Build bitmap
    buildOutgoingBitmap(threadId);
    
    LOG_INFO("translatoriso.cpp", 87, "buildMessage", threadId, "Bitmap built successfully");
    
    // Build header
    position = 0;
    buildField("DE-1", "0210", "EBCDIC", position, threadId);
    
    LOG_INFO("translatoriso.cpp", 118, "buildMessage", threadId, "Header built successfully");
    LOG_INFO("translatoriso.cpp", 120, "buildMessage", threadId, "Message built successfully");
    
    int headerLength = 4;
    int fieldsLength = 193;
    int messageLength = headerLength + fieldsLength;
    
    LOG_INFO("translatoriso.cpp", 127, "buildMessage", threadId, 
             "Header Length is = [" + std::to_string(headerLength) + "]");
    LOG_INFO("translatoriso.cpp", 130, "buildMessage", threadId, 
             "Message Fields Length is = [" + std::to_string(fieldsLength) + "]");
    LOG_INFO("translatoriso.cpp", 133, "buildMessage", threadId, 
             "Message Length is = [" + std::to_string(messageLength) + "]");
    
    return true;
}

bool TranslatorISO::fillBitmap(const std::string& bitmapData, const std::string& threadId) {
    // Simulate filling bitmap
    bitmapString_ = "11111110111111110100011001000001101010001110000111100010000010100000000000000000000000000000000000000000000000000000000000000100";
    
    LOG_INFO("translatoriso.cpp", 164, "fillBitmap", threadId, "Bitmap set successfully");
    return true;
}

void TranslatorISO::showBitmap(const std::string& threadId) {
    LOG_INFO("translatoriso.cpp", 186, "showBitmap", threadId, 
             "Bitmap = [" + bitmapString_ + "]");
}

void TranslatorISO::showBitmapFields(const std::string& threadId) {
    std::string fields = "SecondaryBitmap, DE-2, DE-3, DE-4, DE-5, DE-6, DE-7, DE-9, DE-10, DE-11, "
                        "DE-12, DE-13, DE-14, DE-15, DE-16, DE-18, DE-22, DE-23, DE-26, DE-32, "
                        "DE-33, DE-35, DE-37, DE-41, DE-42, DE-43, DE-48, DE-49, DE-50, DE-51, "
                        "DE-55, DE-61, DE-63, Tertiary Bitmap , DE-126, ";
    
    LOG_INFO("translatoriso.cpp", 213, "showBitmapFiel", threadId, 
             "Fields = [" + fields + "]");
}

bool TranslatorISO::parseFields(const std::string& messageData, 
                                 Message& msg, 
                                 const std::string& threadId) {
    // Simulate DE-48 parsing
    LOG_INFO("translatoriso.cpp", 263, "parseFields", threadId, 
             "DE-48 [ADDITIONAL_DATA_PRIVATE], value [D9] length = 1");
    
    return true;
}

bool TranslatorISO::buildField(const std::string& fieldName, 
                                const std::string& value,
                                const std::string& encoding,
                                int position,
                                const std::string& threadId) {
    std::string fieldType;
    int length = value.length();
    
    // Determine field type based on field name
    if (fieldName == "DE-2" || fieldName == "DE-32" || fieldName == "DE-33") {
        fieldType = "LLVariable";
        length += 2; // Include length indicator
    } else if (fieldName == "DE-63") {
        fieldType = "LLLVariable";
        length += 3; // Include length indicator
    } else {
        fieldType = "Fixed";
    }
    
    // Map field names to descriptions
    std::string description = fieldName;
    if (fieldName == "DE-2") description = "PAN";
    else if (fieldName == "DE-3") description = "PROCESSING_CODE";
    else if (fieldName == "DE-4") description = "AMOUNT_TRANSACTION";
    else if (fieldName == "DE-5") description = "SETTLEMENT_AMOUNT";
    else if (fieldName == "DE-7") description = "TRANSMISSION_DATE_TIME";
    else if (fieldName == "DE-9") description = "CONV_RATE_SETT";
    else if (fieldName == "DE-10") description = "CONV_RATE_CARD_HOLDER_BILL";
    else if (fieldName == "DE-11") description = "SYSTEM_TRACE_AUDIT_NUMBER";
    else if (fieldName == "DE-12") description = "TIME_LOCAL_TRANSACTION";
    else if (fieldName == "DE-13") description = "DATE_LOCAL_TRANSACTION";
    else if (fieldName == "DE-15") description = "DATE_SETTLEMENT";
    else if (fieldName == "DE-32") description = "ACQ_INSTITUTION_ID_CODE";
    else if (fieldName == "DE-33") description = "FORWARD_INSTITUTION_ID_CODE";
    else if (fieldName == "DE-37") description = "RETRIEVAL_REFERENCE_NUMBER";
    else if (fieldName == "DE-39") description = "RESPONSE_CODE";
    else if (fieldName == "DE-41") description = "CARD_ACCEPTOR_TERMINAL_ID";
    else if (fieldName == "DE-42") description = "CARD_ACCEPTOR_ID_CODE";
    else if (fieldName == "DE-49") description = "CURRENCY_CODE_TRANSACTION";
    else if (fieldName == "DE-50") description = "CURRENCY_CODE_SETTLEMENT";
    else if (fieldName == "DE-51") description = "CURRENCY_CODE_CARD_BILL";
    else if (fieldName == "DE-63") description = "NetworkData";
    else if (fieldName == "DE-1") description = "MESSAGE_TYPE";
    
    LOG_INFO("translatoriso.cpp", 1251, "buildField", threadId, 
             fieldType + "     ->" + encoding + "->Length = [" + std::to_string(length) + 
             "], Position = [" + std::to_string(position) + "]");
    
    LOG_INFO("translatoriso.cpp", 1264, "buildField", threadId, 
             fieldName + " " + description + " [" + std::to_string(value.length()) + 
             "][" + value + "]" + fieldType + " Encoded[" + encoding + "]");
    
    return true;
}

bool TranslatorISO::buildOutgoingBitmap(const std::string& threadId) {
    LOG_INFO("translatoriso.cpp", 1357, "buildOutgoingB", threadId, "Building bitmap");
    
    std::string outBitmap = "0111101011111010000000000000000110001010110000011110001000000010";
    
    LOG_INFO("translatoriso.cpp", 1391, "buildOutgoingB", threadId, 
             "Bitmap [" + outBitmap + "]");
    
    return true;
}
