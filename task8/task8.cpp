#include <iostream>
#include <vector>
#include <string>

class RecordBook {
private:
    int                 number;
    std::vector<double> grades;

public:
    explicit RecordBook(int number) : number(number) {}

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
        std::cout << "  Record book #" << number << ": ";
        for (double g : grades) std::cout << g << " ";
        std::cout << "\n";
    }

    int getNumber() const { return number; }
};

class Person {
protected:
    std::string name;

public:
    explicit Person(const std::string& name) : name(name) {}
    virtual ~Person() {}

    virtual void print() const {
        std::cout << "Name: " << name << "\n";
    }

    const std::string& getName() const { return name; }
};

class Student : public Person {
private:
    RecordBook recordBook; // композиция

public:
    Student(const std::string& name, int bookNumber)
        : Person(name), recordBook(bookNumber) {}

    void addGrade(double grade) {
        recordBook.addGrade(grade);
    }

    double calcAverage() const {
        return recordBook.calcAverage();
    }

    void print() const override {
        std::cout << "Student: " << name << "\n";
        recordBook.print();
        std::cout << "  Average: " << calcAverage() << "\n";
    }
};

int main() {
    Student s1("Ivanov", 1001);
    s1.addGrade(4.5);
    s1.addGrade(5.0);
    s1.addGrade(3.5);
    s1.print();

    std::cout << "\n";

    Student s2("Petrov", 1002);
    s2.addGrade(3.0);
    s2.addGrade(2.5);
    s2.addGrade(6.0); // некорректная — должна быть отвергнута
    s2.print();

    return 0;
}
