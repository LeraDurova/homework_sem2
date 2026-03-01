#include "Student.hpp"
#include <iostream>

int main() {
    Student s1("Ivanov", 1001);
    s1.addGrade(4.5);
    s1.addGrade(5.0);
    s1.addGrade(3.5);
    s1.print();

    std::cout << "\n";

    Student s2("Petrov", 1002);
    s2.print(); // зачётка пуста

    return 0;
}
