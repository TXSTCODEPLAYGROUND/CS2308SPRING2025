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

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>
#include <tuple>

/**
 * TODO: Provide appropriate Documentation, see other examples provided within the projects
 */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
 * TODO: Provide appropriate Documentation, see other examples provided within the projects
 */
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);

// ========================= Efficient Solutions ==========================

/**
 * @brief Finds the next empty cell using Minimum Remaining Value heuristic.
 * @param BOARD The Sudoku board
 * @return tuple<int,int,int> (row, col, number of options)
 */
std::tuple<int, int, int> findNextCell(int** BOARD);

/**
 * @brief Solves Sudoku using backtracking with MRV heuristic
 * @param BOARD The Sudoku board
 * @return true if solved successfully
 */
bool solveBoardEfficient(int** BOARD);

/**
 * @brief Chooses between basic and efficient solvers
 * @param board The Sudoku board
 * @param efficient Whether to use efficient solver
 * @return true if solved successfully
 */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H
