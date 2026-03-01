#include "Group.hpp"
#include <iostream>
#include <algorithm>

Group::Group(const std::string& name) : groupName(name) {}

void Group::addStudent(Student* student) {
    students.push_back(student);
}

void Group::removeStudent(const std::string& name) {
    auto it = std::remove_if(students.begin(), students.end(),
        [&name](Student* s) { return s->getName() == name; });
    students.erase(it, students.end());
}

double Group::calcGroupAverage() const {
    if (students.empty()) return 0;
    double sum = 0;
    for (Student* s : students) sum += s->calcAverage();
    return sum / students.size();
}

void Group::printAll() const {
    std::cout << "Group \"" << groupName << "\" (" << students.size() << " students):\n";
    for (Student* s : students) s->print();
    std::cout << "  Group average: " << calcGroupAverage() << "\n";
}

void Group::sortByAverage() {
    std::sort(students.begin(), students.end(),
        [](Student* a, Student* b) {
            return a->calcAverage() > b->calcAverage();
        });
    std::cout << "Students sorted by descending average.\n";
}

void Group::filterByThreshold(double threshold) {
    auto it = std::remove_if(students.begin(), students.end(),
        [threshold](Student* s) { return s->calcAverage() < threshold; });
    int removed = (int)(students.end() - it);
    students.erase(it, students.end());
    std::cout << "Removed students below " << threshold << ": " << removed << "\n";
}

const std::string& Group::getName() const {
    return groupName;
}

const std::vector<Student*>& Group::getStudents() const {
    return students;
}
