// cca.cpp
#include <iostream>
#include "configuration.cpp"

class CCA {
public:
    CCA(Configuration& config) : config_(config) {}

    void processTransaction() {
        std::string limit = config_.getValue("transaction_limit");
        if (limit.empty()) {
            std::cerr << "Transaction limit not configured." << std::endl;
            return;
        }
        // Process transaction logic using limit
    }

private:
    Configuration& config_;
};

int main() {
    Configuration config;
    config.loadConfiguration();
    CCA cca(config);
    cca.processTransaction();
    return 0;
}