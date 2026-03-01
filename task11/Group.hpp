#pragma once

#include "Student.hpp"
#include <vector>
#include <string>

class Group {
private:
    std::string           groupName;
    std::vector<Student*> students; // агрегация: группа не владеет студентами

public:
    explicit Group(const std::string& name);

    void addStudent(Student* student);
    void removeStudent(const std::string& name);

    void   printAll() const;
    double calcGroupAverage() const;
    void   sortByAverage();
    void   filterByThreshold(double threshold);

    const std::string&           getName()     const;
    const std::vector<Student*>& getStudents() const;
};
