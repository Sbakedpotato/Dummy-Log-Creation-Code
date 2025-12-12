#ifndef IMD_H
#define IMD_H

#include <string>

// Issuer Master Data (IMD) - BIN lookup and card information
class IMD {
public:
    static IMD& getInstance();

    // Get IMD data for a given BIN (Bank Identification Number)
    bool getIMD(const std::string& bin, const std::string& threadId);

    // Get the min/max BIN range for lookups
    int getBinMaxRange() const { return binMaxRange_; }
    int getBinMinRange() const { return binMinRange_; }

private:
    IMD();
    IMD(const IMD&) = delete;
    IMD& operator=(const IMD&) = delete;

    int binMaxRange_ = 11;
    int binMinRange_ = 6;
};

#endif // IMD_H
