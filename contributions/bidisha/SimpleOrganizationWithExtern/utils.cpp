//
// Created by Bidisha Shrestha on 2/2/25.
//
#include <math.h>

/**
 * @brief Checks if a given number is prime.
 * @param num The integer to check.
 * @return true if num is prime, otherwise false.
 */
bool isPrime(int num) {
    if (num <= 2 || num %2 == 0) return num == 2;
    for (int i = 3; i * i <= static_cast<int>(sqrt(num)); i += 2) { // Skip even numbers, check divisibility
        if (num % i == 0) return false;
    }
    return true;
}