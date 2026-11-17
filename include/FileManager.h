#pragma once
#include "MaintenanceRecord.h"
#include "Vehicle.h"
#include <string>
#include <vector>

/** @brief Provides CSV persistence through a single shared instance (Singleton pattern). */
class FileManager {
public:
    /** @brief Returns the shared file manager instance.
     *  @return Reference to the singleton FileManager.
     */
    static FileManager& instance();

    /** @brief Writes vehicle data to a CSV file.
     *  @param vehicles Vehicles to write.
     *  @param filename Destination CSV file path.
     *  @return true if the file was opened and written; false if opening failed.
     */
    bool saveVehicles(const std::vector<Vehicle>& vehicles, const std::string& filename) const;
    /** @brief Reads vehicles from a CSV file into the supplied collection.
     *  @param vehicles Collection replaced by parsed vehicles after the file opens.
     *  @param filename Source CSV file path.
     *  @return true if the file opened; false otherwise. Malformed rows are skipped.
     */
    bool loadVehicles(std::vector<Vehicle>& vehicles, const std::string& filename) const;
    /** @brief Writes maintenance records to a CSV file.
     *  @param records Maintenance records to write.
     *  @param filename Destination CSV file path.
     *  @return true if the file was opened and written; false if opening failed.
     */
    bool saveRecords(const std::vector<MaintenanceRecord>& records, const std::string& filename) const;
    /** @brief Reads maintenance records from a CSV file.
     *  @param records Collection replaced by parsed records after the file opens.
     *  @param filename Source CSV file path.
     *  @return true if the file opened; false otherwise. Malformed rows are skipped.
     */
    bool loadRecords(std::vector<MaintenanceRecord>& records, const std::string& filename) const;

    /** @brief Prevents copying the singleton instance. */
    FileManager(const FileManager&) = delete;
    /** @brief Prevents assigning the singleton instance. */
    FileManager& operator=(const FileManager&) = delete;

private:
    /** @brief Restricts construction to the class itself. */
    FileManager() = default;
};
