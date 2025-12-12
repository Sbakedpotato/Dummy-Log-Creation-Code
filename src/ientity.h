#ifndef IENTITY_H
#define IENTITY_H

#include <string>

// Interface for entity/object creation from database
class IEntity {
public:
    virtual ~IEntity() = default;

    // Get a maker object from the database-stored library
    static void* getMakerObject(const std::string& libraryName, const std::string& threadId);
};

#endif // IENTITY_H
