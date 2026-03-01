#pragma once

#include "Person.hpp"
#include "RecordBook.hpp"

class Student : public Person {
private:
    RecordBook recordBook;

public:
    Student(const std::string& name, int bookNumber);

    void   addGrade(double grade);
    double calcAverage() const;
    void   print() const override;

    const RecordBook& getRecordBook() const;
};
