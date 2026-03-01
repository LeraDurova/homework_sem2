#include "Teacher.hpp"
#include <iostream>

Teacher::Teacher(const std::string& name, const std::string& subject)
    : Person(name), subject(subject) {}

void Teacher::print() const {
    std::cout << "  Teacher: " << name << ", subject: " << subject << "\n";
}

const std::string& Teacher::getSubject() const {
    return subject;
}
