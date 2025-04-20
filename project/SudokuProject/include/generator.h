/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * @author Keshav Bhandari
 * @date February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

/**
 * @brief Creates an empty 9x9 Sudoku board initialized with zeros.
 * @return int** Dynamically allocated 9x9 board.
 */
int** getEmptyBoard();

/**
 * @brief Generates a vector of numbers 1-9 in random order.
 * @return std::vector<int> Shuffled numbers 1-9.
 */
std::vector<int> getShuffledVector();

/**
 * @brief Fills the three diagonal 3x3 boxes with random numbers.
 * @param BOARD The Sudoku board to modify.
 */
void fillBoardWithIndependentBox(int** BOARD);

/**
 * @brief Randomly clears cells in a Sudoku board.
 * @param BOARD The Sudoku board to modify.
 * @param n Number of cells to clear (1-81).
 */
void deleteRandomItems(int** BOARD, const int& n);

/**
 * @brief Generates a solvable Sudoku puzzle.
 * @param empty_boxes Number of cells to leave empty (1-81).
 * @return int** Generated Sudoku board.
 */
int** generateBoard(const int& empty_boxes);

#endif
