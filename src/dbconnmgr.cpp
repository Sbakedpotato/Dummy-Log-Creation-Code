#include "dbconnmgr.h"
#include "logger.h"

DBConnMgr& DBConnMgr::getInstance() {
    static DBConnMgr instance;
    return instance;
}

bool DBConnMgr::dbHitForStoredProcedure(const std::string& procedureName, 
                                         const std::string& threadId,
                                         std::map<std::string, std::string>& outParams) {
    LOG_INFO("dbconnmgr.cpp", 765, "dbHitForStored", threadId, 
             "Procedure name: " + procedureName);
    
    // Simulate database call
    // Check for specific procedures that may fail
    if (procedureName.find("isDefaultCountry") != std::string::npos) {
        LOG_ERROR("dbconnmgr.cpp", 909, "dbHitForStored", threadId, "No data found");
        return false;
    }
    
    if (procedureName.find("INSERTTRAN") != std::string::npos) {
        // Simulate successful insertion
        return true;
    }
    
    if (procedureName.find("INSERTEXCEPTIONALMESSAGE") != std::string::npos) {
        return true;
    }
    
    return true;
}

bool DBConnMgr::dbHitForMultiple(const std::string& threadId) {
    LOG_INFO("dbconnmgr.cpp", 569, "dbHitForMultip", threadId, "Start execute");
    
    // Simulate database execution
    LOG_INFO("dbconnmgr.cpp", 578, "dbHitForMultip", threadId, "End executed");
    
    return true;
}
