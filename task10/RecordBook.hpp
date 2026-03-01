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
    void   print() const;
    int    getNumber() const;

    // inline метод в заголовочном файле
    inline bool isEmpty() const { return grades.empty(); }
};
