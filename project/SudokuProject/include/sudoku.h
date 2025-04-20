/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <tuple>

/**
 * @brief Checks if placing k at (r, c) is valid.
 */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
 * @brief Solves the Sudoku board using simple backtracking.
 */
bool solveBoard(int** BOARD, const int& r, const int& c);

/**
 * @brief Finds the next empty cell using MRV heuristic.
 * @return (row, col, number of valid options)
 */
std::tuple<int, int, int> findNextCell(int** BOARD);

/**
 * @brief Solves Sudoku using backtracking and MRV heuristic.
 */
bool solveBoardEfficient(int** BOARD);

/**
 * @brief Dispatches to efficient or basic solver.
 * @param efficient If true, uses MRV solver.
 */
bool solve(int** board, const bool& efficient = true);

#endif
