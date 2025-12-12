#ifndef SAF_H
#define SAF_H

#include <string>

// Store and Forward (SAF) mechanism for handling messages
// when the destination is temporarily unavailable
class SAF {
public:
    SAF(const std::string& threadId);
    ~SAF() = default;

    // Initialize SAF with configurable intervals
    void initialize(int sleepIntervalRetriever, int sleepIntervalSender);

private:
    int sleepIntervalRetriever_;
    int sleepIntervalSender_;
    std::string threadId_;
};

#endif // SAF_H
