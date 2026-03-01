#include <iostream>
#include <vector>
#include <algorithm>

double studentAverage(const std::vector<double>& grades) {
    double sum = 0;
    for (double g : grades) sum += g;
    return sum / grades.size();
}

int main() {
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


    std::vector<std::pair<int, double>> indexed;
    for (int i = 0; i < N; i++) {
        indexed.push_back({i, studentAverage(grades[i])});
    }


    std::sort(indexed.begin(), indexed.end(),
        [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

    std::cout << "\nSorted student list (descending average):\n";
    for (const auto& p : indexed) {
        std::cout << "  Student " << (p.first + 1) << ": average = " << p.second << "\n";
    }


    double threshold = 3.5;
    int countAbove = 0;
    std::for_each(indexed.begin(), indexed.end(),
        [threshold, &countAbove](const std::pair<int, double>& p) {
            if (p.second >= threshold) countAbove++;
        });

    std::cout << "\nStudents with grade >= " << threshold << ": " << countAbove << "\n";


    double totalSum = 0;
    std::for_each(indexed.begin(), indexed.end(),
        [&totalSum](const std::pair<int, double>& p) {
            totalSum += p.second;
        });
    std::cout << "Overall average: " << totalSum / N << "\n";

    return 0;
}
