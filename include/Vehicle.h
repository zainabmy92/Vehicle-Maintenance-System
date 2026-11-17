#pragma once
#include <string>

/** @brief Represents a vehicle and its current odometer reading. */
class Vehicle {
public:
    /** @brief Constructs a vehicle with default-initialized values. */
    Vehicle() = default;
    /** @brief Constructs a vehicle.
     *  @param plate Vehicle registration plate.
     *  @param model Vehicle model name.
     *  @param year Vehicle model year.
     *  @param mileage Current odometer reading in km.
     */
    Vehicle(std::string plate, std::string model, int year, int mileage);

    /** @brief Returns the registration plate. @return Plate identifier. */
    const std::string& getPlate() const;
    /** @brief Returns the vehicle model. @return Model name. */
    const std::string& getModel() const;
    /** @brief Returns the vehicle year. @return Model year. */
    int getYear() const;
    /** @brief Returns the odometer reading. @return Mileage in km. */
    int getMileage() const;

    /** @brief Updates the model name. @param model New model name. */
    void setModel(const std::string& model);
    /** @brief Updates the vehicle year. @param year New model year. */
    void setYear(int year);
    /** @brief Updates the odometer reading. @param mileage New mileage in km. */
    void setMileage(int mileage);

private:
    std::string plate_;
    std::string model_;
    int year_ = 0;
    int mileage_ = 0;
};