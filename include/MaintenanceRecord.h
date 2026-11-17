#pragma once
#include <string>

/** @brief Stores the details of a maintenance service for a vehicle. */
class MaintenanceRecord {
public:
    /** @brief Constructs a record with default-initialized values. */
    MaintenanceRecord() = default;
    /** @brief Constructs a maintenance record.
     *  @param plate Vehicle registration plate.
     *  @param serviceType Description of the performed service.
     *  @param date Service date as supplied by the user.
     *  @param mileage Odometer reading at service.
     *  @param cost Service cost.
     *  @param nextDueMileage Odometer reading for the next scheduled service.
     */
    MaintenanceRecord(std::string plate, std::string serviceType, std::string date,
                      int mileage, double cost, int nextDueMileage);

    /** @brief Returns the associated vehicle plate. @return Vehicle plate. */
    const std::string& getPlate() const;
    /** @brief Returns the service description. @return Service type. */
    const std::string& getServiceType() const;
    /** @brief Returns the stored service date. @return Date text. */
    const std::string& getDate() const;
    /** @brief Returns the mileage at service. @return Service mileage in km. */
    int getMileage() const;
    /** @brief Returns the service cost. @return Stored cost. */
    double getCost() const;
    /** @brief Returns the next service mileage. @return Next due mileage in km. */
    int getNextDueMileage() const;

private:
    std::string plate_;
    std::string serviceType_;
    std::string date_;
    int mileage_ = 0;
    double cost_ = 0.0;
    int nextDueMileage_ = 0;
};
