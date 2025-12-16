#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    Message() = default;

    // Prints the message stamp details (DateTime, Stan, RRN)
    void printMessageStamp(const std::string& threadId);

    // Inserts an exceptional message into the database
    bool insertException(const std::string& threadId, int& exceptionId);

    // Setters
    void setDateTime(const std::string& dt) { dateTime_ = dt; }
    void setStan(const std::string& stan) { stan_ = stan; }
    void setRRN(const std::string& rrn) { rrn_ = rrn; }
    void setPan(const std::string& pan) { pan_ = pan; }
    void setMessageStamp(const std::string& stamp) { messageStamp_ = stamp; }

    // Getters
    std::string getDateTime() const { return dateTime_; }
    std::string getStan() const { return stan_; }
    std::string getRRN() const { return rrn_; }
    std::string getPan() const { return pan_; }
    std::string getMessageStamp() const { return messageStamp_; }

private:
    std::string dateTime_;
    std::string stan_;
    std::string rrn_;
    std::string pan_;
    std::string messageStamp_;
};

#endif // MESSAGE_H
