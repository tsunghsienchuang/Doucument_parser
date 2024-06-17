#ifndef PARSER_H
#define PARSER_H

#include "event.h"
#include <vector>
#include <string>
#include <map>

class Parser {
public:
    std::map<std::string, std::vector<Event>> parseFile(const std::string& filename);

private:
    bool isValidDate(const std::string& date);
    bool isValidTime(const std::string& time);
};

#endif 
