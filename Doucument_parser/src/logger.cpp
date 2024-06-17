#include "logger.h"
#include <fstream>
#include <iostream>

void Logger::log(const std::string& message) {
    std::ofstream log_file("logs/parser.log", std::ios_base::app);
    if (log_file.is_open()) {
        log_file << message << std::endl;
    } else {
        std::cerr << "Unable to open log file." << std::endl;
    }
}
