//
// Created by Keshav Bhandari on 2/8/24.
//

/**
 * @file utils.cpp
 * @brief Utility functions for Sudoku board management and file system operations.
 *
 * Implements:
 * - Memory deallocation for Sudoku boards
 * - Folder creation for data storage
 * - Filename formatting for puzzle and solution files
 *
 * @author Keshav Bhandari
 * @date February 8, 2025
 */

#include "../include/utils.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <sys/stat.h>
#include <iomanip>
#include <sstream>

using namespace std;

/**
 * @brief Deallocates memory for a dynamically allocated 9x9 Sudoku board.
 * @param BOARD Pointer to the 2D board to deallocate.
 * @param rows Number of rows in the board (default 9).
 *
 * - Check if BOARD is nullptr.
 * - Iterate through each row and deallocate using delete[].
 * - Deallocate the array of row pointers using delete[].
 * - Note: Setting BOARD to nullptr here does not affect the caller's pointer.
 */
void deallocateBoard(int** BOARD, const int& rows) {
    if (!BOARD) return;
    for (int i = 0; i < rows; ++i) {
        delete[] BOARD[i];
    }
    delete[] BOARD;
    // Note: BOARD is a local pointer, cannot set caller's pointer to nullptr here.
}

/**
 * @brief Creates a folder at the specified path if it does not exist.
 *
 * Checks if the folder already exists and creates it if it doesn't. Logs
 * success or failure messages to the console.
 *
 * @param folderPath The path where the folder should be created.
 */
void createFolder(const std::string& folderPath) {
    if (!std::filesystem::exists(folderPath)) {
        if (std::filesystem::create_directory(folderPath)) {
            std::cout << "Folder created successfully: " << folderPath << std::endl;
        } else {
            std::cerr << "Failed to create folder: " << folderPath << std::endl;
        }
    } else {
        std::cout << "Folder already exists: " << folderPath << std::endl;
    }
}

/**
 * @brief Initializes the folder structure for Sudoku data storage.
 *
 * Creates a base `data/` directory along with `data/puzzles/` and
 * `data/solutions/` subdirectories for storing generated puzzles and their solutions.
 */
void initDataFolder() {
    createFolder("data/");
    createFolder("data/puzzles/");
    createFolder("data/solutions/");
}

/**
 * @brief Generates a formatted filename with zero-padded index.
 *
 * Constructs a filename using a zero-padded index, a destination path, and a prefix.
 * The filename follows the pattern: `destination/XXXXprefix.txt`, where `XXXX` is the
 * zero-padded index (e.g., `0001puzzle.txt`).
 *
 * @param index The numerical index to include in the filename.
 * @param destination The directory where the file will be saved.
 * @param prefix The filename prefix (e.g., "puzzle" or "solution").
 * @return A formatted string representing the complete file path.
 */
string getFileName(const int& index, const string& destination, const string& prefix) {
    string index_str = to_string(index);
    string index_fill = string(4 - index_str.length(), '0');
    string filename = destination + index_fill + index_str + prefix + ".txt";
    return filename;
}
