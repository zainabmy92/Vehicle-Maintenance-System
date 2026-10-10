# Vehicle Maintenance Management System

A small C++17 console application for managing vehicles and maintenance records.

## Features
- Add/list/search/remove vehicles
- Add maintenance records
- Show maintenance history
- Show upcoming maintenance within 1000 km
- Save/load data using CSV files
- Demonstrates Facade and Singleton design patterns

## Build with MSYS2 UCRT64
```bash
./build.sh
./_start.sh
```

If scripts are not executable, use:
```bash
bash build.sh
bash _start.sh
```

## Data
The application stores data in:
- `data/vehicles.csv`
- `data/maintenance.csv`
