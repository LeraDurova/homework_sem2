#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class RecordBook {
private:
    int                 number;
    std::vector<double> grades;

public:
    explicit RecordBook(int number) : number(number) {}

    void addGrade(double grade) {
        if (grade >= 0 && grade <= 5)
            grades.push_back(grade);
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
    RecordBook recordBook;

public:
    Student(const std::string& name, int bookNumber)
        : Person(name), recordBook(bookNumber) {}

    void addGrade(double grade) { recordBook.addGrade(grade); }

    double calcAverage() const { return recordBook.calcAverage(); }

    void print() const override {
        std::cout << "  Student: " << name << ", average: " << calcAverage() << "\n";
        recordBook.print();
    }
};

class Group {
private:
    std::string            groupName;
    std::vector<Student*>  students;

public:
    explicit Group(const std::string& name) : groupName(name) {}

    void addStudent(Student* student) {
        students.push_back(student);
    }

    void removeStudent(const std::string& name) {
        auto it = std::remove_if(students.begin(), students.end(),
            [&name](Student* s) { return s->getName() == name; });
        students.erase(it, students.end());
    }

    double calcGroupAverage() const {
        if (students.empty()) return 0;
        double sum = 0;
        for (Student* s : students) sum += s->calcAverage();
        return sum / students.size();
    }

    void printAll() const {
        std::cout << "Group \"" << groupName << "\" (" << students.size() << " students):\n";
        for (Student* s : students) s->print();
        std::cout << "  Group average: " << calcGroupAverage() << "\n";
    }
};

int main() {
    Student s1("Ivanov",   1001);
    s1.addGrade(4.5);
    s1.addGrade(5.0);

    Student s2("Petrov",   1002);
    s2.addGrade(3.0);
    s2.addGrade(2.5);

    Student s3("Sidorova", 1003);
    s3.addGrade(4.0);
    s3.addGrade(4.5);

    Group group("IT-21");
    group.addStudent(&s1);
    group.addStudent(&s2);
    group.addStudent(&s3);

    group.printAll();

    std::cout << "\nRemoving Petrov from group...\n\n";
    group.removeStudent("Petrov");

    group.printAll();

    return 0;
}
