#include <complex>

double f(double x) {
    return std::exp(-x * x);
}

double integral(double a, double b, int chunks) {
    double dx = (b - a) / chunks;
    double totalArea = 0.0;

    for (int i = 0; i < chunks; i++) {
        double x = a + i * dx;
        totalArea += f(x) * dx;
    }

    return totalArea;
}
