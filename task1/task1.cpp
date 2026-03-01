#include <iostream>

double calcAverage(double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

double findMax(double* arr, int n) {
    double max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

double findMin(double* arr, int n) {
    double min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

int countAboveThreshold(double* arr, int n, double threshold) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > threshold) count++;
    return count;
}

int main() {
    int N;
    std::cout << "Enter number of students: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Error: number of students must be > 0\n";
        return 1;
    }

    double* grades = new double[N];

    for (int i = 0; i < N; i++) {
        while (true) {
            std::cout << "Student " << (i + 1) << " grade (0-5): ";
            std::cin >> grades[i];
            if (grades[i] >= 0 && grades[i] <= 5) break;
            std::cout << "Invalid grade. Enter a value from 0 to 5.\n";
        }
    }

    std::cout << "\nAverage grade: " << calcAverage(grades, N) << "\n";
    std::cout << "Maximum grade: " << findMax(grades, N) << "\n";
    std::cout << "Minimum grade: " << findMin(grades, N) << "\n";

    double threshold;
    std::cout << "Enter threshold grade: ";
    std::cin >> threshold;
    std::cout << "Students above threshold: " << countAboveThreshold(grades, N, threshold) << "\n";

    delete[] grades;
    return 0;
}
