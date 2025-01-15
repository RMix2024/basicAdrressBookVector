#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record {
public:
    std::string name;  // Name field
    std::string phone; // Phone field

    Record();
    Record(const std::string& name, const std::string& phone);
    ~Record();
};

#endif
