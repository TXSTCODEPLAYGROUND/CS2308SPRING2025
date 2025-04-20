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

#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief Deallocates a 2D board.
 * @param BOARD Board to deallocate.
 * @param rows Number of rows in the board.
 */
void deallocateBoard(int** BOARD, const int& rows);

void createFolder(const std::string& folderPath);
void initDataFolder();
std::string getFileName(const int& index, const std::string& destination, const std::string& prefix);

#endif
