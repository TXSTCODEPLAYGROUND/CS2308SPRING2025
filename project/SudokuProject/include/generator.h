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
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

 /**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
int** getEmptyBoard();
/**
 * @brief Creates a dynamically allocated 9 by 9 2-D array initialized at zero
 *
 * Creates an array of 9 int* pointers with board pointing to the first row of the 2-D array.
 * The loop runs 9 times, once for each row and initializes all 9 values to zero.
 *
 * @return board, the empty 9 by 9 2-D array
 */

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
std::vector<int> getShuffledVector();
/**
 * @brief Creates a vector with numbers 1 to 9. Apply a shuffling algorithm to randomize the order.
 *
 *ask about use of the shuffle function and ofc ask about #include statements
 *
 * @return the shuffled vector
 */
/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
void fillBoardWithIndependentBox(int** BOARD);
/**
 * @brief fills 3 by 3 boxes with shuffled numbers 1 through 9
 *
 * Creates a shuffled vector for nums when it is used to iterate 3 by 3 BOARDS and then the function
 * is used three times for the top left, middle, and right bottom squares of a 9 by 9 board.
 */
/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
void deleteRandomItems(int** BOARD, const int& n);
/**
 * @brief sets n to be in the bounds of the 9 by 9 and deletes random items
 *
 * Creates a vector deleted which stores the values dictated by index which turns non zero entries into null
 * or zero values.
 *
 * @return BOARD with the deleted items
 */
/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
int** generateBoard(const int& empty_boxes);
/**
     * @brief Generates a solvable Sudoku board with a specified number of empty cells.
     *
     *  creates helper functions in the correct order to:
     *   1. Initialize an empty board.
     *   2. Fill the diagonal 3x3 boxes.
     *   3. Solve the board to complete it.
     *   4. Randomly delete cells to create a playable puzzle.
     *
     * @param empty_boxes The number of cells to be emptied in the generated puzzle.
     * @return int** A dynamically allocated 9x9 Sudoku board with 'empty_boxes' empty cells.
     */

#endif // GENERATOR_H
