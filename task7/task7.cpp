#include <iostream>
#include <vector>
#include <string>

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
    std::vector<double> grades;

public:
    explicit Student(const std::string& name) : Person(name) {}

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

    void print() const override {
        std::cout << "Student: " << name << ", average: " << calcAverage() << "\n";
    }
};

class Teacher : public Person {
private:
    std::string subject;

public:
    Teacher(const std::string& name, const std::string& subject)
        : Person(name), subject(subject) {}

    void print() const override {
        std::cout << "Teacher: " << name << ", subject: " << subject << "\n";
    }
};

int main() {
    std::vector<Person*> people;

    Student* s1 = new Student("Ivanov");
    s1->addGrade(4.0);
    s1->addGrade(5.0);

    Student* s2 = new Student("Petrov");
    s2->addGrade(3.0);
    s2->addGrade(2.5);

    Teacher* t1 = new Teacher("Smirnova", "Mathematics");
    Teacher* t2 = new Teacher("Kozlov",   "Physics");

    people.push_back(s1);
    people.push_back(s2);
    people.push_back(t1);
    people.push_back(t2);

    std::cout << "All participants:\n";
    for (Person* p : people) {
        p->print();
    }

    for (Person* p : people) {
        delete p;
    }

    return 0;
}
