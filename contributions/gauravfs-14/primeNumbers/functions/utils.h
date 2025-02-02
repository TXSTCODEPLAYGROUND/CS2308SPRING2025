#include "functions.cpp"

#ifndef UTILS_H
#define UTILS_H

/**
 * Checks if a number is prime
 * @param num The number to check
 * @return true if the number is prime, false otherwise
 */
bool isPrime(int num);

/**
 * Checks if a number is a right-truncated prime
 * @param num The number to check
 * @return true if the number is a right-truncated prime, false otherwise
 */
bool isRTPrime(int num);

/**
 * Checks if a number is a left-truncated prime
 * @param num The number to check
 * @return true if the number is a left-truncated prime, false otherwise
 */
bool isLTPrime(int num);

#endif