#include <cmath>

/**
 * @brief Checks if a number is prime.
 *
 * This function determines whether a given integer is a prime number.
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 *
 * @param num The integer to check for primality.
 * @return true if the number is prime, false otherwise.
 */
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

/**
 * @brief Checks if a number is a right-truncated prime.
 *
 * This function determines whether a given integer is a right-truncated prime number.
 * A right-truncated prime is a prime number that remains prime when the rightmost digits are successively removed.
 *
 * @param num The integer to check for right-truncated primality.
 * @return true if the number is a right-truncated prime, false otherwise.
 */
bool isRTPrime(int num)
{
    while (num > 0)
    {
        if (!isPrime(num))
            return false;
        num /= 10;
    }
    return true;
}

/**
 * @brief Checks if a number is a left-truncated prime.
 *
 * This function determines whether a given integer is a left-truncated prime number.
 * A left-truncated prime is a prime number that remains prime when the leftmost digits are successively removed.
 *
 * @param num The integer to check for left-truncated primality.
 * @return true if the number is a left-truncated prime, false otherwise.
 */
bool isLTPrime(int num)
{
    int digits = log10(num);
    while (num > 0)
    {
        if (!isPrime(num))
            return false;
        num %= static_cast<int>(pow(10, digits--));
    }
    return true;
}

/**
 * @brief Checks if a number is an Emirp prime.
 *
 * This function determines whether a given integer is an Emirp prime number.
 * An Emirp prime is a prime number that results in a different prime number when its digits are reversed.
 *
 * @param num The integer to check for Emirp primality.
 * @return true if the number is an Emirp prime, false otherwise.
 */
bool isEmirp(int num)
{
    if (!isPrime(num))
        return false;

    int reversedNum = 0, originalNum = num;
    while (num > 0)
    {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }

    return reversedNum != originalNum && isPrime(reversedNum);
}