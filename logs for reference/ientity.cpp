#include "ientity.h"
#include "logger.h"

void* IEntity::getMakerObject(const std::string& libraryName, const std::string& threadId) {
    // Simulate failure to load custom library
    LOG_ERROR("ientity.h", 78, "getMakerObject", threadId, 
              "Failed to load custom library from database");
    
    return nullptr;
}
