// configuration.cpp
#include <iostream>
#include <map>
#include <string>

class Configuration {
public:
    void loadConfiguration() {
        // Load configuration from a file or environment variables
        config_ = { {"key1", "value1"}, {"key2", "value2"} };
    }

    std::string getValue(const std::string& key) {
        auto it = config_.find(key);
        if (it != config_.end()) {
            return it->second;
        } else {
            std::cerr << "Configuration key not found: " << key << std::endl;
            return "";
        }
    }

private:
    std::map<std::string, std::string> config_;
};

int main() {
    Configuration config;
    config.loadConfiguration();
    std::string value = config.getValue("key1");
    std::cout << "Config value: " << value << std::endl;
    return 0;
}