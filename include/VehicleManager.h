#pragma once

#include "MaintenanceRecord.h"
#include "Vehicle.h"

#include <string>
#include <vector>

/** @brief Manages vehicles, service records, and CSV persistence. */
class VehicleManager {
public:
    /** @brief Loads vehicle and maintenance collections from their CSV files. */
    void load();
    /** @brief Saves vehicle and maintenance collections to their CSV files. */
    void save() const;

    /** @brief Adds a vehicle if its plate is not already registered.
     *  @param vehicle Vehicle to add.
     *  @return true if added; false if the plate already exists.
     */
    bool addVehicle(const Vehicle& vehicle);
    /** @brief Adds a service record for an existing vehicle.
     *  Also increases the vehicle mileage if the service mileage is higher.
     *  @param record Maintenance record to add.
     *  @return true if the vehicle exists and the record is added; false otherwise.
     */
    bool addMaintenance(const MaintenanceRecord& record);

    /** @brief Finds a vehicle by registration plate.
     *  @param plate Registration plate to search for.
     *  @return Pointer to the matching vehicle, or nullptr if not found.
     */
    Vehicle* findVehicle(const std::string& plate);
    /** @brief Finds a vehicle without allowing modification.
     *  @param plate Registration plate to search for.
     *  @return Pointer to the matching vehicle, or nullptr if not found.
     */
    const Vehicle* findVehicle(const std::string& plate) const;

    /** @brief Updates the model, year, and mileage of an existing vehicle.
     *  @param plate Registration plate identifying the vehicle.
     *  @param newModel Replacement model name.
     *  @param newYear Replacement model year.
     *  @param newMileage Replacement odometer reading in km.
     *  @return true if the vehicle was found and updated; false otherwise.
     */
    bool editVehicle(const std::string& plate,
                     const std::string& newModel,
                     int newYear,
                     int newMileage);

    /** @brief Removes a vehicle and all of its maintenance records.
     *  @param plate Registration plate identifying the vehicle.
     *  @return true if a vehicle was removed; false if no vehicle matched.
     */
    bool removeVehicle(const std::string& plate);

    /** @brief Prints all registered vehicles to standard output. */
    void listVehicles() const;
    /** @brief Prints service records for a given vehicle.
     *  @param plate Registration plate whose history is requested.
     */
    void showMaintenanceHistory(const std::string& plate) const;
    /** @brief Prints scheduled services due within a mileage threshold.
     *  Only services with nonnegative remaining mileage are shown.
     *  @param thresholdKm Maximum remaining distance in km (default: 1000).
     */
    void showUpcomingMaintenance(int thresholdKm = 1000) const;

private:
    std::vector<Vehicle> vehicles_;
    std::vector<MaintenanceRecord> records_;

    /** @brief CSV path used for vehicle persistence. */
    const std::string vehicleFile_ = "data/vehicles.csv";
    /** @brief CSV path used for maintenance record persistence. */
    const std::string recordFile_ = "data/maintenance.csv";
};