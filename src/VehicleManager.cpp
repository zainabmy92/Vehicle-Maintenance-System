#include "VehicleManager.h"
#include "FileManager.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

void VehicleManager::load() {
    FileManager::instance().loadVehicles(vehicles_, vehicleFile_);
    FileManager::instance().loadRecords(records_, recordFile_);
}

void VehicleManager::save() const {
    FileManager::instance().saveVehicles(vehicles_, vehicleFile_);
    FileManager::instance().saveRecords(records_, recordFile_);
}

bool VehicleManager::addVehicle(const Vehicle& vehicle) {
    if (findVehicle(vehicle.getPlate())) return false;
    vehicles_.push_back(vehicle);
    return true;
}

bool VehicleManager::addMaintenance(const MaintenanceRecord& record) {
    Vehicle* vehicle = findVehicle(record.getPlate());
    if (!vehicle) return false;
    records_.push_back(record);
    if (record.getMileage() > vehicle->getMileage()) vehicle->setMileage(record.getMileage());
    return true;
}

Vehicle* VehicleManager::findVehicle(const std::string& plate) {
    auto it = std::find_if(vehicles_.begin(), vehicles_.end(), [&](const Vehicle& v) {
        return v.getPlate() == plate;
    });
    return it == vehicles_.end() ? nullptr : &(*it);
}

const Vehicle* VehicleManager::findVehicle(const std::string& plate) const {
    auto it = std::find_if(vehicles_.begin(), vehicles_.end(), [&](const Vehicle& v) {
        return v.getPlate() == plate;
    });
    return it == vehicles_.end() ? nullptr : &(*it);
}

bool VehicleManager::removeVehicle(const std::string& plate) {
    auto oldSize = vehicles_.size();
    vehicles_.erase(std::remove_if(vehicles_.begin(), vehicles_.end(), [&](const Vehicle& v) {
        return v.getPlate() == plate;
    }), vehicles_.end());
    if (vehicles_.size() == oldSize) return false;
    records_.erase(std::remove_if(records_.begin(), records_.end(), [&](const MaintenanceRecord& r) {
        return r.getPlate() == plate;
    }), records_.end());
    return true;
}

void VehicleManager::listVehicles() const {
    if (vehicles_.empty()) {
        std::cout << "No vehicles found.\n";
        return;
    }
    std::cout << "\n--- Vehicles ---\n";
    for (const auto& v : vehicles_) {
        std::cout << "Plate: " << v.getPlate()
                  << " | Model: " << v.getModel()
                  << " | Year: " << v.getYear()
                  << " | Mileage: " << v.getMileage() << " km\n";
    }
}

void VehicleManager::showMaintenanceHistory(const std::string& plate) const {
    bool found = false;
    std::cout << "\n--- Maintenance History: " << plate << " ---\n";
    for (const auto& r : records_) {
        if (r.getPlate() == plate) {
            found = true;
            std::cout << r.getDate() << " | " << r.getServiceType()
                      << " | " << r.getMileage() << " km"
                      << " | Cost: " << std::fixed << std::setprecision(2) << r.getCost()
                      << " | Next due: " << r.getNextDueMileage() << " km\n";
        }
    }
    if (!found) std::cout << "No maintenance records found.\n";
}

void VehicleManager::showUpcomingMaintenance(int thresholdKm) const {
    bool found = false;
    std::cout << "\n--- Upcoming Maintenance (within " << thresholdKm << " km) ---\n";
    for (const auto& r : records_) {
        const Vehicle* v = findVehicle(r.getPlate());
        if (!v) continue;
        int remaining = r.getNextDueMileage() - v->getMileage();
        if (remaining >= 0 && remaining <= thresholdKm) {
            found = true;
            std::cout << r.getPlate() << " | " << r.getServiceType()
                      << " | due in " << remaining << " km\n";
        }
    }
    if (!found) std::cout << "No maintenance is due soon.\n";
}
