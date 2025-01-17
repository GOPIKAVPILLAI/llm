
#include <iostream>
#include <iomanip>
#include <chrono>

double calculate(unsigned int iterations, double param1, double param2) {
    double result = 1.0;
    for (unsigned int i = 1; i <= iterations; ++i) {
        double j1 = i * param1 - param2;
        result -= 1.0 / j1;
        double j2 = i * param1 + param2;
        result += 1.0 / j2;
    }
    return result;
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    double result = calculate(100000000, 4.0, 1.0) * 4.0;
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << "\n";
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) 
              << elapsed.count() << " seconds\n";

    return 0;
}
