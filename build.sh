#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Create or clean the build directory
if [ -d "$BUILD_DIR" ]; then
    echo "🔄 Cleaning existing build directory..."
    rm -rf "$BUILD_DIR"
fi

mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

# Run CMake and Make
echo "⚙️ Running CMake..."
cmake ..

echo "🔨 Compiling with make..."
make -j$(nproc)  # Use all available CPU cores

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
else
    echo "❌ Build failed!"
    exit 1
fi
