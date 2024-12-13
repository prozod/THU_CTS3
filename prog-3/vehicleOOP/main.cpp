#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

class Vehicle {
public:
  std::string name;

  Vehicle(std::string name) { this->name = name; }

  virtual double getFuelEfficiency() const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Vehicle &obj) {
    os << "Vehicle: " << obj.name << std::endl;
    os << "Fuel Efficiency: " << std::setprecision(2) << std::fixed
       << obj.getFuelEfficiency() << " km/l" << std::endl;
    return os;
  }

  virtual ~Vehicle() {};
};

class Car : public Vehicle {
public:
  double engineSize;
  double weightKg;

  Car(double engSize, double weight, std::string name)
      : Vehicle(name), engineSize(engSize), weightKg(weight) {}

  double getFuelEfficiency() const override {
    return 100 / (engineSize * (weightKg / 1000));
  };
};

class Bike : public Vehicle {
public:
  double engineCC;

  Bike(double engineCC, std::string name) : Vehicle(name), engineCC(engineCC) {}

  double getFuelEfficiency() const override { return 200 / engineCC; };
};

int main() {
  Vehicle *c1 = new Car(2.0, 1000.0, "Loganu ca Golanu");
  Vehicle *b1 = new Bike(150.0, "Trotineta ca tanti Geta");

  std::vector<Vehicle *> vehicles;
  vehicles.push_back(c1);
  vehicles.push_back(b1);

  for (const auto &vehicle : vehicles) {
    std::cout << *vehicle;
  }

  for (auto &vehicle : vehicles) {
    delete vehicle;
  }

  return 0;
}
