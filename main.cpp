#include <iostream>
#include <random>

double f(double x) {
    return x * x;
}

int main() {
    int n = 1000000;
    int count_inside = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; i++) {
        double x = dis(gen);
        double y = dis(gen);
        if (y <= f(x)) {
            count_inside++;
        }
    }

    double integral = static_cast<double>(count_inside) / n;
    std::cout << "Результат численного интегрирования методом Монте-Карло: " << integral << std::endl;

    return 0;
}
