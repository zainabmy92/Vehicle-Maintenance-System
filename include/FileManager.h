#pragma once
#include "MaintenanceRecord.h"
#include "Vehicle.h"
#include <string>
#include <vector>

class FileManager {
public:
    static FileManager& instance();

    bool saveVehicles(const std::vector<Vehicle>& vehicles, const std::string& filename) const;
    bool loadVehicles(std::vector<Vehicle>& vehicles, const std::string& filename) const;
    bool saveRecords(const std::vector<MaintenanceRecord>& records, const std::string& filename) const;
    bool loadRecords(std::vector<MaintenanceRecord>& records, const std::string& filename) const;

    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

private:
    FileManager() = default;
};
