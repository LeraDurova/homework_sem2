#pragma once

#include "Group.hpp"
#include <string>

class FileManager {
public:
    static bool saveGroup(const std::string& filename, const Group& group);
    static bool loadGroup(const std::string& filename, Group& group, std::vector<Student*>& allocatedStudents);
};
