#include "MaintenanceRecord.h"
#include <utility>

MaintenanceRecord::MaintenanceRecord(std::string plate, std::string serviceType, std::string date,
                                     int mileage, double cost, int nextDueMileage)
    : plate_(std::move(plate)), serviceType_(std::move(serviceType)), date_(std::move(date)),
      mileage_(mileage), cost_(cost), nextDueMileage_(nextDueMileage) {}

const std::string& MaintenanceRecord::getPlate() const { return plate_; }
const std::string& MaintenanceRecord::getServiceType() const { return serviceType_; }
const std::string& MaintenanceRecord::getDate() const { return date_; }
int MaintenanceRecord::getMileage() const { return mileage_; }
double MaintenanceRecord::getCost() const { return cost_; }
int MaintenanceRecord::getNextDueMileage() const { return nextDueMileage_; }
