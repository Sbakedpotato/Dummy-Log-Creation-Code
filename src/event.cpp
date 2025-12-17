/**
 * @file event.cpp
 * @brief Event implementation
 * 
 * Reconstructed from log file analysis.
 */

#include "event.h"

Event::Event() 
    : m_ip("127.0.0.1")
    , m_machine("localhost.localdomain") {
}

Event::~Event() {
}

bool Event::initialize() {
    LOG_INFO("event.cpp", "0067", "initialize", "",
             "IP " + m_ip + " Machine " + m_machine);
    return true;
}
