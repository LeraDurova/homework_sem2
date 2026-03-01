#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

#pragma pack(push, 1)
struct FileHeader {
    char signature[4];
    int  version;
    int  studentCount;
};
#pragma pack(pop)

double studentAverage(const std::vector<double>& grades) {
    double sum = 0;
    for (double g : grades) sum += g;
    return sum / grades.size();
}

void saveToFile(const std::string& filename, const std::vector<std::vector<double>>& grades) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Error opening file for writing: " << filename << "\n";
        return;
    }

    FileHeader header;
    std::memcpy(header.signature, "STUD", 4);
    header.version      = 1;
    header.studentCount = (int)grades.size();
    file.write(reinterpret_cast<const char*>(&header), sizeof(header));

    int M = grades.empty() ? 0 : (int)grades[0].size();
    file.write(reinterpret_cast<const char*>(&M), sizeof(M));

    for (const auto& row : grades) {
        file.write(reinterpret_cast<const char*>(row.data()), sizeof(double) * row.size());
    }

    file.close();
    std::cout << "Data saved to file \"" << filename << "\"\n";
}

void loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Error opening file for reading: " << filename << "\n";
        return;
    }

    FileHeader header;
    file.read(reinterpret_cast<char*>(&header), sizeof(header));

    if (std::memcmp(header.signature, "STUD", 4) != 0) {
        std::cout << "Invalid file signature!\n";
        return;
    }

    int M;
    file.read(reinterpret_cast<char*>(&M), sizeof(M));

    std::cout << "\nLoaded from file (version: " << header.version
              << ", students: " << header.studentCount
              << ", subjects: " << M << "):\n";

    for (int i = 0; i < header.studentCount; i++) {
        std::vector<double> row(M);
        file.read(reinterpret_cast<char*>(row.data()), sizeof(double) * M);
        std::cout << "  Student " << (i + 1) << ": average = " << studentAverage(row) << "\n";
    }

    file.close();
}

int main() {
    std::cout << "FileHeader size: " << sizeof(FileHeader) << " bytes\n\n";

    int N, M;
    std::cout << "Enter number of students: ";
    std::cin >> N;
    std::cout << "Enter number of subjects: ";
    std::cin >> M;

    if (N <= 0 || M <= 0) {
        std::cout << "Error: values must be > 0\n";
        return 1;
    }

    std::vector<std::vector<double>> grades(N, std::vector<double>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            while (true) {
                std::cout << "Student " << (i + 1) << ", subject " << (j + 1) << " (0-5): ";
                std::cin >> grades[i][j];
                if (grades[i][j] >= 0 && grades[i][j] <= 5) break;
                std::cout << "Invalid grade.\n";
            }
        }
    }

    saveToFile("grades.bin", grades);
    loadFromFile("grades.bin");

    return 0;
}
