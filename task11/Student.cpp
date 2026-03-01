#include "Student.hpp"
#include <iostream>

Student::Student(const std::string& name, int bookNumber)
    : Person(name), recordBook(bookNumber) {}

void Student::addGrade(double grade) {
    recordBook.addGrade(grade);
}

double Student::calcAverage() const {
    return recordBook.calcAverage();
}

void Student::print() const {
    std::cout << "  Student: " << name << "\n";
    recordBook.printGrades();
    std::cout << "    Average: " << calcAverage() << "\n";
}

const RecordBook& Student::getRecordBook() const {
    return recordBook;
}
