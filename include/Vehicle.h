#pragma once
#include <string>

class Vehicle {
public:
    Vehicle() = default;
    Vehicle(std::string plate, std::string model, int year, int mileage);

    const std::string& getPlate() const;
    const std::string& getModel() const;
    int getYear() const;
    int getMileage() const;
    void setMileage(int mileage);

private:
    std::string plate_;
    std::string model_;
    int year_ = 0;
    int mileage_ = 0;
};
