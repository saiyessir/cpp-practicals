#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Common interface for all vehicle types.
class Vehicle {
public:
    virtual void showDetails() const = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void showDetails() const override {
        cout << "Created a Car: Four-wheeler vehicle.\n";
    }
};

class Bike : public Vehicle {
public:
    void showDetails() const override {
        cout << "Created a Bike: Two-wheeler vehicle.\n";
    }
};

// Factory creates the requested vehicle and returns it through the interface.
class VehicleFactory {
public:
    static unique_ptr<Vehicle> createVehicle(const string& type) {
        if (type == "car") {
            return make_unique<Car>();
        }
        if (type == "bike") {
            return make_unique<Bike>();
        }
        return nullptr;
    }
};

int main() {
    cout << "VEHICLE FACTORY DEMONSTRATION\n";

    unique_ptr<Vehicle> vehicle1 = VehicleFactory::createVehicle("car");
    if (vehicle1) {
        vehicle1->showDetails();
    }

    unique_ptr<Vehicle> vehicle2 = VehicleFactory::createVehicle("bike");
    if (vehicle2) {
        vehicle2->showDetails();
    }

    unique_ptr<Vehicle> vehicle3 = VehicleFactory::createVehicle("car");
    if (vehicle3) {
        cout << "Second car request: ";
        vehicle3->showDetails();
    }

    return 0;
}
