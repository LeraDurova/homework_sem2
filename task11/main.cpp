#include "Student.hpp"
#include "Teacher.hpp"
#include "Group.hpp"
#include "FileManager.hpp"
#include <iostream>
#include <vector>

void printSeparator(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {

    Student* s1 = new Student("Ivanov",   1001);
    Student* s2 = new Student("Petrova",  1002);
    Student* s3 = new Student("Sidorov",  1003);
    Student* s4 = new Student("Kozlova",  1004);

    s1->addGrade(4.5);
    s1->addGrade(5.0);
    s1->addGrade(4.0);

    s2->addGrade(3.0);
    s2->addGrade(2.5);
    s2->addGrade(3.5);

    s3->addGrade(5.0);
    s3->addGrade(4.5);
    s3->addGrade(5.0);

    s4->addGrade(2.0);
    s4->addGrade(1.5);
    s4->addGrade(2.5);


    Teacher* t1 = new Teacher("Smirnova", "Mathematics");
    Teacher* t2 = new Teacher("Belov",    "Physics");


    printSeparator("Teachers (polymorphism)");
    std::vector<Person*> people = { t1, t2 };
    for (Person* p : people) p->print();


    Group group("IT-21");
    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(s3);
    group.addStudent(s4);

    printSeparator("Initial group list");
    group.printAll();


    printSeparator("After sorting");
    group.sortByAverage();
    group.printAll();


    printSeparator("After filtering (threshold 3.0)");
    group.filterByThreshold(3.0);
    group.printAll();


    printSeparator("Save to file");
    FileManager::saveGroup("group.bin", group);


    printSeparator("Load from file");
    Group loadedGroup("Loaded");
    std::vector<Student*> loadedStudents;
    if (FileManager::loadGroup("group.bin", loadedGroup, loadedStudents)) {
        loadedGroup.printAll();
    }


    printSeparator("Statistics (original data)");
    int excellent = 0, risk = 0;
    Student* allStudents[] = { s1, s2, s3, s4 };
    for (Student* s : allStudents) {
        if (s->calcAverage() >= 4.5) excellent++;
        if (s->calcAverage() < 3.0) risk++;
    }
    std::cout << "Excellent (>= 4.5): " << excellent << "\n";
    std::cout << "At risk of expulsion (< 3.0): " << risk << "\n";


    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete t1;
    delete t2;

    for (Student* s : loadedStudents) {
        delete s;
    }

    return 0;
}
