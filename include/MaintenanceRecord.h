#pragma once
#include <string>

class MaintenanceRecord {
public:
    MaintenanceRecord() = default;
    MaintenanceRecord(std::string plate, std::string serviceType, std::string date,
                      int mileage, double cost, int nextDueMileage);

    const std::string& getPlate() const;
    const std::string& getServiceType() const;
    const std::string& getDate() const;
    int getMileage() const;
    double getCost() const;
    int getNextDueMileage() const;

private:
    std::string plate_;
    std::string serviceType_;
    std::string date_;
    int mileage_ = 0;
    double cost_ = 0.0;
    int nextDueMileage_ = 0;
};
