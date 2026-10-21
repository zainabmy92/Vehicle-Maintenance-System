#include <gtest/gtest.h>

#include "Vehicle.h"
#include "VehicleManager.h"

#include <iostream>
#include <sstream>
#include <string>

TEST(VehicleTest, InitialState) {
    Vehicle vehicle("ABC-123", "Toyota Corolla", 2020, 65000);

    EXPECT_EQ(vehicle.getPlate(), "ABC-123");
    EXPECT_EQ(vehicle.getModel(), "Toyota Corolla");
    EXPECT_EQ(vehicle.getYear(), 2020);
    EXPECT_EQ(vehicle.getMileage(), 65000);
}

TEST(VehicleManagerTest, EditVehicle) {
    VehicleManager manager;
    ASSERT_TRUE(manager.addVehicle(Vehicle("ABC-123", "Toyota Corolla", 2020, 65000)));

    ASSERT_TRUE(manager.editVehicle("ABC-123", "Hyundai Tucson", 2022, 70000));

    const Vehicle* updated = manager.findVehicle("ABC-123");
    ASSERT_NE(updated, nullptr);
    EXPECT_EQ(updated->getModel(), "Hyundai Tucson");
    EXPECT_EQ(updated->getYear(), 2022);
    EXPECT_EQ(updated->getMileage(), 70000);
}

TEST(VehicleManagerTest, ListVehiclesOutput) {
    VehicleManager manager;
    ASSERT_TRUE(manager.addVehicle(Vehicle("ABC-123", "Toyota Corolla", 2020, 65000)));

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    manager.listVehicles();
    std::cout.rdbuf(originalBuffer);

    const std::string text = output.str();
    EXPECT_NE(text.find("ABC-123"), std::string::npos);
    EXPECT_NE(text.find("Toyota Corolla"), std::string::npos);
    EXPECT_NE(text.find("65000"), std::string::npos);
}
