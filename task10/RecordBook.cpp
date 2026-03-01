#include "RecordBook.hpp"
#include <iostream>

RecordBook::RecordBook(int number) : number(number) {}

void RecordBook::addGrade(double grade) {
    if (grade >= 0 && grade <= 5)
        grades.push_back(grade);
    else
        std::cout << "Invalid grade: " << grade << "\n";
}

double RecordBook::calcAverage() const {
    if (grades.empty()) return 0;
    double sum = 0;
    for (double g : grades) sum += g;
    return sum / grades.size();
}

void RecordBook::print() const {
    std::cout << "  Record book #" << number << ": ";
    for (double g : grades) std::cout << g << " ";
    std::cout << "\n";
}

int RecordBook::getNumber() const {
    return number;
}
