#include "MaintenanceSystemFacade.h"
#include "MaintenanceRecord.h"
#include "Vehicle.h"
#include <iostream>
#include <limits>
#include <string>

namespace {
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
}

void MaintenanceSystemFacade::printMenu() const {
    std::cout << "\n===== VEHICLE MAINTENANCE SYSTEM =====\n"
              << "1. Add vehicle\n"
              << "2. List vehicles\n"
              << "3. Add maintenance record\n"
              << "4. Show maintenance history\n"
              << "5. Show upcoming maintenance\n"
              << "6. Search vehicle\n"
              << "7. Remove vehicle\n"
              << "8. Save data\n"
              << "0. Exit\n"
              << "Choose an option: ";
}

void MaintenanceSystemFacade::run() {
    manager_.load();
    int choice = -1;
    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Invalid input.\n";
            continue;
        }
        clearInput();
        switch (choice) {
            case 1: addVehicle(); break;
            case 2: manager_.listVehicles(); break;
            case 3: addMaintenance(); break;
            case 4: showHistory(); break;
            case 5: manager_.showUpcomingMaintenance(); break;
            case 6: searchVehicle(); break;
            case 7: removeVehicle(); break;
            case 8: manager_.save(); std::cout << "Data saved.\n"; break;
            case 0: manager_.save(); std::cout << "Data saved. Goodbye!\n"; break;
            default: std::cout << "Unknown option.\n";
        }
    }
}

void MaintenanceSystemFacade::addVehicle() {
    std::string plate, model;
    int year, mileage;
    std::cout << "Plate number: "; std::getline(std::cin, plate);
    std::cout << "Model: "; std::getline(std::cin, model);
    std::cout << "Year: ";
    if (!(std::cin >> year)) { clearInput(); std::cout << "Invalid year.\n"; return; }
    std::cout << "Current mileage (km): ";
    if (!(std::cin >> mileage)) { clearInput(); std::cout << "Invalid mileage.\n"; return; }
    clearInput();
    if (manager_.addVehicle(Vehicle(plate, model, year, mileage))) std::cout << "Vehicle added.\n";
    else std::cout << "A vehicle with this plate already exists.\n";
}

void MaintenanceSystemFacade::addMaintenance() {
    std::string plate, type, date;
    int mileage, nextDue;
    double cost;
    std::cout << "Vehicle plate: "; std::getline(std::cin, plate);
    std::cout << "Service type (Oil/Brakes/Tires/Inspection/...): "; std::getline(std::cin, type);
    std::cout << "Date (YYYY-MM-DD): "; std::getline(std::cin, date);
    std::cout << "Mileage at service: ";
    if (!(std::cin >> mileage)) { clearInput(); std::cout << "Invalid mileage.\n"; return; }
    std::cout << "Cost: ";
    if (!(std::cin >> cost)) { clearInput(); std::cout << "Invalid cost.\n"; return; }
    std::cout << "Next due mileage: ";
    if (!(std::cin >> nextDue)) { clearInput(); std::cout << "Invalid mileage.\n"; return; }
    clearInput();
    if (manager_.addMaintenance(MaintenanceRecord(plate, type, date, mileage, cost, nextDue)))
        std::cout << "Maintenance record added.\n";
    else
        std::cout << "Vehicle not found.\n";
}

void MaintenanceSystemFacade::searchVehicle() const {
    std::string plate;
    std::cout << "Plate number: "; std::getline(std::cin, plate);
    const Vehicle* v = manager_.findVehicle(plate);
    if (!v) { std::cout << "Vehicle not found.\n"; return; }
    std::cout << "Found: " << v->getPlate() << " | " << v->getModel()
              << " | " << v->getYear() << " | " << v->getMileage() << " km\n";
}

void MaintenanceSystemFacade::showHistory() const {
    std::string plate;
    std::cout << "Plate number: "; std::getline(std::cin, plate);
    manager_.showMaintenanceHistory(plate);
}

void MaintenanceSystemFacade::removeVehicle() {
    std::string plate;
    std::cout << "Plate number to remove: "; std::getline(std::cin, plate);
    if (manager_.removeVehicle(plate)) std::cout << "Vehicle and its records removed.\n";
    else std::cout << "Vehicle not found.\n";
}
