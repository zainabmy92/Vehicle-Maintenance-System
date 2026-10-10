#pragma once
#include "VehicleManager.h"

class MaintenanceSystemFacade {
public:
    void run();

private:
    VehicleManager manager_;

    void printMenu() const;
    void addVehicle();
    void addMaintenance();
    void searchVehicle() const;
    void showHistory() const;
    void removeVehicle();
};
