#pragma once

#include <vector>

class RecordBook {
private:
    int                 number;
    std::vector<double> grades;

public:
    explicit RecordBook(int number);

    void   addGrade(double grade);
    double calcAverage() const;
    void   printGrades() const;

    int                        getNumber() const;
    const std::vector<double>& getGrades() const;

    inline bool isEmpty() const { return grades.empty(); }
};
