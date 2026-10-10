cmake_minimum_required(VERSION 3.16)
project(VehicleMaintenanceSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main application
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(vehicle_maintenance ${SOURCES})
target_include_directories(vehicle_maintenance PRIVATE include)

# Testing
enable_testing()

add_executable(test_vehicle
    tests/test_vehicle.cpp
    src/Vehicle.cpp
)

target_include_directories(test_vehicle PRIVATE include)

add_test(
    NAME VehicleTest
    COMMAND test_vehicle
)