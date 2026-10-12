#pragma once

#include "MaintenanceRecord.h"
#include "Vehicle.h"

#include <string>
#include <vector>

class VehicleManager {
public:
    void load();
    void save() const;

    bool addVehicle(const Vehicle& vehicle);
    bool addMaintenance(const MaintenanceRecord& record);

    Vehicle* findVehicle(const std::string& plate);
    const Vehicle* findVehicle(const std::string& plate) const;

    bool editVehicle(const std::string& plate,
                     const std::string& newModel,
                     int newYear,
                     int newMileage);

    bool removeVehicle(const std::string& plate);

    void listVehicles() const;
    void showMaintenanceHistory(const std::string& plate) const;
    void showUpcomingMaintenance(int thresholdKm = 1000) const;

private:
    std::vector<Vehicle> vehicles_;
    std::vector<MaintenanceRecord> records_;

    const std::string vehicleFile_ = "data/vehicles.csv";
    const std::string recordFile_ = "data/maintenance.csv";
};