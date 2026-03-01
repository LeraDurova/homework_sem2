#include "Person.hpp"
#include <iostream>

Person::Person(const std::string& name) : name(name) {}

Person::~Person() {}

void Person::print() const {
    std::cout << "Name: " << name << "\n";
}

const std::string& Person::getName() const {
    return name;
}
