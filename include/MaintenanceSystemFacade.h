#pragma once

#include "VehicleManager.h"

/** @brief Provides the menu-driven user interface (Facade pattern). */
class MaintenanceSystemFacade {
public:
    /** @brief Loads data and runs the interactive menu until the user exits. */
    void run();

private:
    /** @brief Manages vehicle and maintenance data for the interface. */
    VehicleManager manager_;

    /** @brief Displays the available menu commands. */
    void printMenu() const;
    /** @brief Prompts for vehicle details, validates them, and adds a vehicle. */
    void addVehicle();
    /** @brief Prompts for service details, validates them, and adds a record. */
    void addMaintenance();
    /** @brief Prompts for a plate and displays the matching vehicle. */
    void searchVehicle() const;
    /** @brief Prompts for a plate and displays its service history. */
    void showHistory() const;
    /** @brief Prompts for replacement vehicle details and updates a vehicle. */
    void editVehicle();
    /** @brief Prompts for a plate and removes its vehicle and service records. */
    void removeVehicle();
};