#include "FileManager.hpp"
#include <iostream>
#include <fstream>
#include <cstring>



static const char SIGNATURE[4] = {'G', 'R', 'P', 'S'};

bool FileManager::saveGroup(const std::string& filename, const Group& group) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Error: could not open file for writing: " << filename << "\n";
        return false;
    }

    file.write(SIGNATURE, 4);

    int nameLen = (int)group.getName().size();
    file.write(reinterpret_cast<const char*>(&nameLen), sizeof(int));
    file.write(group.getName().c_str(), nameLen);

    int studentCount = (int)group.getStudents().size();
    file.write(reinterpret_cast<const char*>(&studentCount), sizeof(int));

    for (Student* s : group.getStudents()) {
        int sNameLen = (int)s->getName().size();
        file.write(reinterpret_cast<const char*>(&sNameLen), sizeof(int));
        file.write(s->getName().c_str(), sNameLen);

        int bookNumber = s->getRecordBook().getNumber();
        file.write(reinterpret_cast<const char*>(&bookNumber), sizeof(int));

        const std::vector<double>& grades = s->getRecordBook().getGrades();
        int gradeCount = (int)grades.size();
        file.write(reinterpret_cast<const char*>(&gradeCount), sizeof(int));
        file.write(reinterpret_cast<const char*>(grades.data()), sizeof(double) * gradeCount);
    }

    file.close();
    std::cout << "Group saved to file \"" << filename << "\"\n";
    return true;
}

bool FileManager::loadGroup(const std::string& filename, Group& group,
                            std::vector<Student*>& allocatedStudents) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Error: could not open file for reading: " << filename << "\n";
        return false;
    }

    char sig[4];
    file.read(sig, 4);
    if (std::memcmp(sig, SIGNATURE, 4) != 0) {
        std::cout << "Error: invalid file format (wrong signature)\n";
        return false;
    }

    int nameLen;
    file.read(reinterpret_cast<char*>(&nameLen), sizeof(int));
    std::string groupName(nameLen, '\0');
    file.read(&groupName[0], nameLen);

    int studentCount;
    file.read(reinterpret_cast<char*>(&studentCount), sizeof(int));

    std::cout << "Loading group \"" << groupName << "\", students: " << studentCount << "\n";

    for (int i = 0; i < studentCount; i++) {
        int sNameLen;
        file.read(reinterpret_cast<char*>(&sNameLen), sizeof(int));
        std::string sName(sNameLen, '\0');
        file.read(&sName[0], sNameLen);

        int bookNumber;
        file.read(reinterpret_cast<char*>(&bookNumber), sizeof(int));

        int gradeCount;
        file.read(reinterpret_cast<char*>(&gradeCount), sizeof(int));

        Student* s = new Student(sName, bookNumber);
        for (int j = 0; j < gradeCount; j++) {
            double grade;
            file.read(reinterpret_cast<char*>(&grade), sizeof(double));
            s->addGrade(grade);
        }

        allocatedStudents.push_back(s);
        group.addStudent(s);
    }

    file.close();
    return true;
}
