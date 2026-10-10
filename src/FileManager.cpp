#include "FileManager.h"
#include <fstream>
#include <sstream>

FileManager& FileManager::instance() {
    static FileManager manager;
    return manager;
}

bool FileManager::saveVehicles(const std::vector<Vehicle>& vehicles, const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;
    for (const auto& v : vehicles) {
        out << v.getPlate() << ',' << v.getModel() << ',' << v.getYear() << ',' << v.getMileage() << '\n';
    }
    return true;
}

bool FileManager::loadVehicles(std::vector<Vehicle>& vehicles, const std::string& filename) const {
    std::ifstream in(filename);
    if (!in) return false;
    vehicles.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string plate, model, yearText, mileageText;
        if (std::getline(ss, plate, ',') && std::getline(ss, model, ',') &&
            std::getline(ss, yearText, ',') && std::getline(ss, mileageText)) {
            try {
                vehicles.emplace_back(plate, model, std::stoi(yearText), std::stoi(mileageText));
            } catch (...) {}
        }
    }
    return true;
}

bool FileManager::saveRecords(const std::vector<MaintenanceRecord>& records, const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;
    for (const auto& r : records) {
        out << r.getPlate() << ',' << r.getServiceType() << ',' << r.getDate() << ','
            << r.getMileage() << ',' << r.getCost() << ',' << r.getNextDueMileage() << '\n';
    }
    return true;
}

bool FileManager::loadRecords(std::vector<MaintenanceRecord>& records, const std::string& filename) const {
    std::ifstream in(filename);
    if (!in) return false;
    records.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string plate, service, date, mileageText, costText, nextDueText;
        if (std::getline(ss, plate, ',') && std::getline(ss, service, ',') &&
            std::getline(ss, date, ',') && std::getline(ss, mileageText, ',') &&
            std::getline(ss, costText, ',') && std::getline(ss, nextDueText)) {
            try {
                records.emplace_back(plate, service, date, std::stoi(mileageText),
                                     std::stod(costText), std::stoi(nextDueText));
            } catch (...) {}
        }
    }
    return true;
}
