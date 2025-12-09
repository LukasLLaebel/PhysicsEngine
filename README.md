# PhysicsEngine

A 2D physics engine built with C and [raylib](https://www.raylib.com/) for real-time physics simulation and visualization.

## About

This project is a physics engine implementation using raylib for rendering.  The engine is designed to simulate physical interactions and behaviors in 2D space.

## Building

This project uses CMake and automatically fetches raylib from GitHub during the build process.
```bash
```
```
```
```bash
# Clone the repository
git clone https://github.com/LukasLLaebel/PhysicsEngine.git
cd PhysicsEngine

# Create build directory
mkdir build
cd build

# Configure and build
cmake .. -G Ninja 
# run
ninja
./PhysicsEngine
```
```
```
```
```


## Running

After building, run the executable:

```bash
# From the build directory
./PhysicsEngine
```

## Project Structure

```bash
PhysicsEngine/
├── sources/        # Source code files
│   ├── main.c      # Main application entry point
│   ├── objects.c   # Physics object implementations
│   └── objects.h   # Physics object definitions
├── assets/         # Assets (images, textures, etc.)
├── CMakeLists.txt  # CMake build configuration
└── README. md       # This file
```

## Asset Handling

The project uses the `ASSETS_PATH` macro to locate assets.  By default, this is set to an absolute path for development. 

To distribute your application, modify line 33 in `CMakeLists.txt`:

```cmake
# Development (absolute path)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

# Release (relative path - uncomment for distribution)
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets/")
```

## Development

The project uses C99 standard and includes LSP support through `compile_commands.json` for better IDE integration.


## Dependencies

- [raylib](https://github.com/raysan5/raylib) - Automatically fetched and built via CMake
