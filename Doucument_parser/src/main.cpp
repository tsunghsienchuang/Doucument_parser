#include "parser.h"
#include <iostream>

int main() {
    std::string filename = "data/events.txt";
    Parser parser;
    std::map<std::string, std::vector<Event>> events = parser.parseFile(filename);

    for (const auto& [date, eventList] : events) {
        for (const auto& event : eventList) {
            std::cout << "Date: " << event.date 
                      << ", Time: " << event.time 
                      << ", Description: " << event.description << std::endl;
        }
    }

    return 0;
}
