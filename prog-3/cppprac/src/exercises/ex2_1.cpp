#include <iostream>
#include <numbers>

void calcSurfaceAndVolumeOfSphere(const double &r, double &surface, double &volume) {
    surface = 4.0 * std::numbers::pi * r * r;
    volume = (4.0 / 3.0) * std::numbers::pi * r * r * r;
}

void calcSurfaceAndVolumeOfSpherePointers(const double r, double *surface, double *volume) {
    *surface = 4 * std::numbers::pi * r * r;
    *volume = (4 / 3) * std::numbers::pi * r * r * r;
}

void doTheMath() {
    double volume, surface;
    std::cout << "Surface pointer address: " << &surface << "\n";
    std::cout << "Radius\t\tSurface Area\tVolume\n";
    for (double r = 0.5; r < 5; r += 0.5) {
        calcSurfaceAndVolumeOfSpherePointers(r, &surface, &volume);
        std::cout << r << "\t\t\t" << surface << "\t\t\t" << volume << "\n";
    }
}
