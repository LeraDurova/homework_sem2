#include <iostream>
#include <vector>

double studentAverage(const std::vector<double>& grades) {
    double sum = 0;
    for (double g : grades) sum += g;
    return sum / grades.size();
}

double subjectAverage(const std::vector<std::vector<double>>& grades, int subject) {
    double sum = 0;
    for (const auto& row : grades) sum += row[subject];
    return sum / grades.size();
}

int findBestStudent(const std::vector<std::vector<double>>& grades) {
    int best = 0;
    double bestAvg = studentAverage(grades[0]);
    for (int i = 1; i < (int)grades.size(); i++) {
        double avg = studentAverage(grades[i]);
        if (avg > bestAvg) {
            bestAvg = avg;
            best = i;
        }
    }
    return best;
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
                std::cout << "Invalid grade. Enter a value from 0 to 5.\n";
            }
        }
    }

    std::cout << "\nAverage grade per student:\n";
    for (int i = 0; i < N; i++) {
        std::cout << "  Student " << (i + 1) << ": " << studentAverage(grades[i]) << "\n";
    }

    std::cout << "\nAverage grade per subject:\n";
    for (int j = 0; j < M; j++) {
        std::cout << "  Subject " << (j + 1) << ": " << subjectAverage(grades, j) << "\n";
    }

    int best = findBestStudent(grades);
    std::cout << "\nBest student: #" << (best + 1)
              << " with average grade " << studentAverage(grades[best]) << "\n";

    return 0;
}
