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

    // Собираем средние баллы
    std::vector<double> averages;
    for (int i = 0; i < N; i++) {
        averages.push_back(studentAverage(grades[i]));
    }

    // Подсчёт статистики ДО фильтрации
    int excellent = 0, risk = 0;
    for (double avg : averages) {
        if (avg >= 4.5) excellent++;
        if (avg < 3.0) risk++;
    }

    double threshold;
    std::cout << "Enter threshold grade for removal: ";
    std::cin >> threshold;

    // Erase-remove idiom с лямбдой
    averages.erase(
        std::remove_if(averages.begin(), averages.end(),
            [threshold](double avg) { return avg < threshold; }),
        averages.end()
    );

    std::cout << "\nAfter filtering (removed students below " << threshold << "):\n";
    std::cout << "Students remaining: " << averages.size() << "\n";
    for (size_t i = 0; i < averages.size(); i++) {
        std::cout << "  Student " << (i + 1) << ": " << averages[i] << "\n";
    }

    std::cout << "\nStatistics from original data:\n";
    std::cout << "  Excellent (>= 4.5): " << excellent << "\n";
    std::cout << "  At risk of expulsion (< 3.0): " << risk << "\n";

    return 0;
}
