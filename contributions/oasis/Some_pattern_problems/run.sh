#!/bin/bash

# Only if you are using Visual Studio Code (if you are using CLion don't worry about this file)
# You might need to change the executable path based on the location of the project executable

echo " ░▒▓██████▓▒░ ░▒▓███████▓▒░      ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░░▒▓██████▓▒░  "
echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                    ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
echo "░▒▓█▓▒░      ░▒▓█▓▒░                    ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
echo "░▒▓█▓▒░       ░▒▓██████▓▒░        ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  "
echo "░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
echo "░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ "
echo " ░▒▓██████▓▒░░▒▓███████▓▒░       ░▒▓████████▓▒░▒▓███████▓▒░░▒▓████████▓▒░░▒▓██████▓▒░  "

# Remove existing build directory if it exists
[[ -d ./cmake-build-debug ]] && rm -rf ./cmake-build-debug

# Create build directory and compile the project
mkdir -p ./cmake-build-debug
cmake -B ./cmake-build-debug
cmake --build ./cmake-build-debug

echo "----------------------------------------"
echo "------------COMPILATION DONE------------"
echo "----------------------------------------"

# Get the parent folder name
PROJECT_NAME=$(basename "$PWD")
echo "Project Name: $PROJECT_NAME"

# Define build path based on environment
if [[ -n "$GITHUB_ACTIONS" ]]; then
    STATIC_PATH="/home/runner/work/CS2308SPRING2025/CS2308SPRING2025"
    DYNAMIC_PATH="${PWD#*$STATIC_PATH}"
    BUILD_PATH="$STATIC_PATH$DYNAMIC_PATH/cmake-build-debug"
else
    BUILD_PATH="cmake-build-debug/"
fi

# Determine OS and run the executable accordingly
OS="$(uname)"
echo "Build path: $BUILD_PATH"
echo "Files in build path:"
ls -lah "$BUILD_PATH"
if [[ "$OS" == "Linux" || "$OS" == "Darwin" ]]; then
    if [[ -f "$BUILD_PATH/$PROJECT_NAME" ]]; then
        "$BUILD_PATH/$PROJECT_NAME"
    else
        echo "Error: Executable not found in $BUILD_PATH"
        exit 1
    fi
elif [[ $OS =~ MINGW || $OS =~ CYGWIN || $OS =~ MSYS ]]; then
    if [[ -f "$BUILD_PATH/Debug/$PROJECT_NAME.exe" ]]; then
        "$BUILD_PATH/Debug/$PROJECT_NAME.exe"
    else
        echo "Error: Executable not found in $BUILD_PATH/Debug"
        exit 1
    fi
else
    echo "Unsupported OS: $OS"
    exit 1
fi
