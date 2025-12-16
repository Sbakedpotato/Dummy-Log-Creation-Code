#ifndef PAYMENTNETWORK_H
#define PAYMENTNETWORK_H

#include <string>

// Payment Network - handles network-specific configurations
class PaymentNetwork {
public:
    static PaymentNetwork& getInstance();

    // Get the Fraud Risk Management System mode for a network
    std::string getFRMSMode(const std::string& networkId, const std::string& threadId);

private:
    PaymentNetwork() = default;
    PaymentNetwork(const PaymentNetwork&) = delete;
    PaymentNetwork& operator=(const PaymentNetwork&) = delete;
};

#endif // PAYMENTNETWORK_H
