#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string        name;
    std::vector<double> grades;

public:
    Student() : name("No name") {}

    explicit Student(const std::string& name) : name(name) {}

    void addGrade(double grade) {
        if (grade >= 0 && grade <= 5)
            grades.push_back(grade);
        else
            std::cout << "Invalid grade: " << grade << "\n";
    }

    double calcAverage() const {
        if (grades.empty()) return 0;
        double sum = 0;
        for (double g : grades) sum += g;
        return sum / grades.size();
    }

    void print() const {
        std::cout << "Student: " << name << "\n";
        std::cout << "Grades:  ";
        for (double g : grades) std::cout << g << " ";
        std::cout << "\nAverage: " << calcAverage() << "\n";
    }
};

int main() {
    Student s1("Ivanov");
    s1.addGrade(4.5);
    s1.addGrade(3.0);
    s1.addGrade(5.0);
    s1.addGrade(6.0);
    s1.print();

    std::cout << "\n";

    Student s2("Petrov");
    s2.addGrade(3.5);
    s2.addGrade(2.5);
    s2.print();

    std::cout << "\n";


    Student s3;
    s3.addGrade(4.0);
    s3.print();

    return 0;
}
