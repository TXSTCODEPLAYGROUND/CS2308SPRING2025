/**
 * @file utils.h
 * @brief Utility functions for Sudoku board management and file system operations.
 *
 * This header file provides utility functions to:
 * - Allocate and deallocate dynamic Sudoku boards.
 * - Manage folders for storing Sudoku puzzles and solutions.
 * - Generate formatted filenames for Sudoku puzzles.
 *
 * These utilities are designed to support file I/O operations, board memory management,
 * and folder structure initialization for Sudoku puzzle generation and solving projects.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 8, 2025
 */

#ifndef SUDOKUPROJECT_UTILITY_H
#define SUDOKUPROJECT_UTILITY_H

#include <string>
using namespace std;

/**
 * @brief Deallocates memory for a dynamically allocated 9x9 Sudoku board.
 * @param BOARD Pointer to the 2D board to deallocate.
 * @param rows Number of rows in the board (default 9).
 */
void deallocateBoard(int** BOARD, const int& rows = 9);

void createFolder(const string& folderPath);
void initDataFolder();
string getFileName(const int& index, const string& destination, const string& prefix);

#endif //SUDOKUPROJECT_UTILITY_H
