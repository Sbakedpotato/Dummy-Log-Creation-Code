if (conditionType == 1) {
    // existing condition check logic
} else if (conditionType == 2) {
    // added logic for conditionType 2
    if (inputData.isValid()) {
        // perform condition check for type 2
    } else {
        // handle invalid input data
        throw std::invalid_argument("Invalid input data");
    }
} else {
    // handle unknown condition types
    throw std::invalid_argument("Unknown condition type");
}