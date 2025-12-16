#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>

class Configuration {
public:
    static Configuration& getInstance();

    // Retrieves a parameter value by key from the configuration cache
    // Returns empty string if not found
    std::string getParamValue(const std::string& key, const std::string& threadId);

private:
    Configuration() = default;
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;
};

#endif // CONFIGURATION_H
