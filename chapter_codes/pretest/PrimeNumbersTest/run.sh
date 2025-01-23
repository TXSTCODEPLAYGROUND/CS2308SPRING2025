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

# Determine OS and run the executable accordingly,
# If following does not work, run only line 27 or 30, require some modification
OS="$(uname)"
if [[ "$OS" == "Linux" || "$OS" == "Darwin" ]]; then
    # Mac or Linux
    ./cmake-build-debug/"$PROJECT_NAME"
elif [[ "$OS" == "MINGW"* || "$OS" == "CYGWIN"* || "$OS" == "MSYS"* ]]; then
    # Windows (Git Bash, Cygwin, MSYS)
    ./cmake-build-debug/Debug/"$PROJECT_NAME".exe
else
    echo "Unsupported OS: $OS"
fi
