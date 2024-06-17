#include "parser.h"
#include "logger.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

std::map<std::string, std::vector<Event>> Parser::parseFile(const std::string& filename) {
    std::map<std::string, std::vector<Event>> events;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        Logger::log("Unable to open file: " + filename);
        return events;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, time, description;
        if (iss >> date >> time) {
            std::getline(iss, description);
            if (isValidDate(date) && isValidTime(time)) {
                events[date].emplace_back(date, time, description);
            } else {
                Logger::log("Invalid date or time format in line: " + line);
            }
        }
    }

    file.close();
    return events;
}

bool Parser::isValidDate(const std::string& date) {
    std::regex date_pattern("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(date, date_pattern);
}

bool Parser::isValidTime(const std::string& time) {
    std::regex time_pattern("\\d{2}:\\d{2}:\\d{2}");
    return std::regex_match(time, time_pattern);
}
