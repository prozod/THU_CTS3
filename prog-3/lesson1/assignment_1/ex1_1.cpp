#include <cmath>
#include <iostream>

double f(double x) { return exp(-x * x); }

double integral(double a, double b, int n) {
  double totalArea = 0.0;
  double width = (b - a) / n;

  for (int i = 0; i < n; ++i) {
    double midPoint = a + (i + 0.5) * width;
    totalArea += f(midPoint) * width;
  }

  return totalArea;
}

void integration_test(double from, double to, int chunks) {
  double result = integral(from, to, chunks);
  std::cout << "integration res: " << result << std::endl;
}
