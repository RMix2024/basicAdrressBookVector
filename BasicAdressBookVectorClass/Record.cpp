#include "Record.h"

// Default constructor
Record::Record() : name(""), phone("") {}

// Parameterized constructor
Record::Record(const std::string& name, const std::string& phone)
    : name(name), phone(phone) {
}

// Destructor
Record::~Record() {}
