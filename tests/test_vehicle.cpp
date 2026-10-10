#include "Vehicle.h"
#include <cassert>
#include <iostream>

int main()
{
    Vehicle car("ABC-123", "Toyota Corolla", 2020, 65000);

    assert(car.getPlate() == "ABC-123");
    assert(car.getModel() == "Toyota Corolla");
    assert(car.getYear() == 2020);
    assert(car.getMileage() == 65000);

    car.setMileage(70000);
    assert(car.getMileage() == 70000);

    std::cout << "Vehicle tests passed successfully!\n";

    return 0;
}