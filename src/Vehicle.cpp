#include "Vehicle.h"
#include <utility>

Vehicle::Vehicle(std::string plate, std::string model, int year, int mileage)
    : plate_(std::move(plate)), model_(std::move(model)), year_(year), mileage_(mileage) {}

const std::string& Vehicle::getPlate() const { return plate_; }
const std::string& Vehicle::getModel() const { return model_; }
int Vehicle::getYear() const { return year_; }
int Vehicle::getMileage() const { return mileage_; }
void Vehicle::setMileage(int mileage) { mileage_ = mileage; }
