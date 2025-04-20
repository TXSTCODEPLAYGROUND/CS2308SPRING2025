/**
 * @file sudoku_io.h
 * @brief Input/Output utility functions for handling Sudoku puzzles.
 *
 * This header file declares functions for reading, writing, displaying,
 * and managing Sudoku puzzles. It includes utilities to:
 * - Print Sudoku boards to the console with color-coded hints.
 * - Read and write Sudoku puzzles from/to files.
 * - Parse and extract numbers from text representations.
 * - Generate and solve multiple Sudoku puzzles.
 * - Handle file system operations to read puzzle sets from directories.
 *
 * The functions work with a dynamically allocated 9x9 Sudoku board
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

/**
 * @brief Writes the Sudoku board to a file.
 */

#ifndef SUDOKU_IO_H
#define SUDOKU_IO_H

#include <string>
#include <vector>

/**
 * @brief Prints the Sudoku board with optional highlighting.
 */
void printBoard(int** BOARD, const int& r = -1, const int& c = -1, int k = -1);

/**
 * @brief Converts the Sudoku board to a string.
 */
void boardToString(int** BOARD, std::string &content);

/**
 * @brief Writes the Sudoku board to a file in string format.
 */
void writeSudokuToFile(int** BOARD, const std::string& filename);

/**
 * @brief Replaces all occurrences of oldChar with newChar in the given string.
 */
void replaceCharacter(std::string& str, char oldChar, char newChar);

/**
 * @brief Extracts all numerical values from a string (no regex, no cctype).
 */
void extractNumbers(const std::string& input, std::vector<int>& numbers);

/**
 * @brief Fills the Sudoku board using a vector of numbers.
 */
void fillBoard(const std::vector<int>& numbers, int **BOARD);

/**
 * @brief Reads a Sudoku puzzle from a file and returns it as a 2D board.
 */
int** readSudokuFromFile(const std::string& filename);

/**
 * @brief Checks if a given Sudoku board is valid according to Sudoku rules.
 */
bool checkIfSolutionIsValid(int** BOARD);

/**
 * @brief Retrieves all Sudoku puzzle file paths from the specified folder.
 */
std::vector<std::string> getAllSudokuInFolder(const std::string& folderPath);

/**
 * @brief Creates and saves N puzzles, deallocates each board after writing.
 */
void createAndSaveNPuzzles(const int& num_puzzles, const int& complexity_empty_boxes, const std::string& destination, const std::string& prefix);

/**
 * @brief Displays a console-based progress bar.
 */
void displayProgressBar(int current, int total, int barWidth = 50);

/**
 * @brief Solves and saves N puzzles, deallocates each board after writing.
 */
void solveAndSaveNPuzzles(const int &num_puzzles, const std::string& source, const std::string& destination, const std::string& prefix);

/**
 * @brief Performs a deep copy of a given 9x9 Sudoku board.
 */
int** deepCopyBoard(int** original);

/**
 * @brief Compares basic and efficient solvers, deallocates boards after each experiment.
 */
void compareSudokuSolvers(const int& experiment_size, const int& empty_boxes);

#endif
