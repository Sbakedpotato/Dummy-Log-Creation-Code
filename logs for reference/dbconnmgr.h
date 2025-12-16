#ifndef DBCONNMGR_H
#define DBCONNMGR_H

#include <string>
#include <vector>
#include <map>

// Database Connection Manager - handles Oracle DB connections and queries
class DBConnMgr {
public:
    static DBConnMgr& getInstance();

    // Execute a stored procedure and return results
    bool dbHitForStoredProcedure(const std::string& procedureName, 
                                  const std::string& threadId,
                                  std::map<std::string, std::string>& outParams);

    // Execute multiple queries
    bool dbHitForMultiple(const std::string& threadId);

private:
    DBConnMgr() = default;
    DBConnMgr(const DBConnMgr&) = delete;
    DBConnMgr& operator=(const DBConnMgr&) = delete;
};

#endif // DBCONNMGR_H
