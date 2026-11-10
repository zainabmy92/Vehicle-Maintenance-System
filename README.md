
# Vehicle Maintenance System

A C++ command-line application developed for the Production Software Engineering course at Széchenyi István University.

The system manages vehicle information and maintenance records using a simple menu-driven interface.

## Features

- Add, list, search, edit, and remove vehicles.
- Add maintenance records and view maintenance history.
- View upcoming maintenance.
- Save and load data using CSV files.
- Validate user input.

## Build and Run

From the project directory:

```bash
./build.sh
./_start.sh
```

## Testing

The project includes three GoogleTest unit tests.

Run the tests with:

```bash
ctest --test-dir build --output-on-failure
```

## Documentation

The project includes Doxygen documentation.

Generate it using:

```bash
doxygen Doxyfile
```

Open `build/docs/html/index.html` to view the generated documentation.

## Author

Zainab Mohammed  
Neptun Code: IL4QED  
Széchenyi István University
