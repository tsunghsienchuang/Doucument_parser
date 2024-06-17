#ifndef EVENT_H
#define EVENT_H

#include <string>

struct Event {
    std::string date;
    std::string time;
    std::string description;

    Event(const std::string& date, const std::string& time, const std::string& description)
        : date(date), time(time), description(description) {}
};

#endif 
