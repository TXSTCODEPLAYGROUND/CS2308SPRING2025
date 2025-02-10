#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
/**
 * @brief Checks if a given number is prime.
 * @param num The integer to check.
 * @return true if num is prime, otherwise false.
 * 
 */
bool isPrime(int num) {
    if (num <= 2 || num %2 == 0) return num == 2;
    for (int i = 3; i * i <= static_cast<int>(sqrt(num)); i += 2) { // Skip even numbers, check divisibility
        if (num % i == 0) return false;
    }
    return true;
}

/**
 * @brief Checks if the given number is a right-truncatable prime.
 * @param num The integer to check.
 * @return true if num is a right-truncatable prime, otherwise false.
 */
bool isRTPrime(int num) {
    while (isPrime(num)) num /= 10; // Remove the last digit
    return num == 0;
}

/**
 * @brief Checks if the given number is a right-truncatable prime by recursively checking if its tenth is a right-truncatable prime.
 * @param num The integer to check.
 * @return true if num is a right-truncatable prime, otherwise false.
 */
bool isRTPrimeRecursion(int num) {
    return isPrime(num) ? isRTPrimeRecursion(num/10):num==0;
}

/**
 * @brief Checks if the given number is a left-truncatable prime.
 * @param num The integer to check.
 * @return true if num is a left-truncatable prime, otherwise false.
 */
bool isLTPrime(int num) {
    // TASK: Do you think this is correct?
    int divisor = 1;
    while (divisor <= num) divisor *= 10;
    while (isPrime(num)) {
        divisor /= 10;
        num %= divisor; // Remove the first digit
    }
    return num == 0;
}

/**
 * @brief Counts the number of digits in an integer.
 * @param num The integer.
 * @return The number of digits in num.
 */
int countDigits(int num) {
    // TASK: Can you use this function to write isLTPrimeWithCountDigits function?
    int digitCount = 0;
    while (num > 0) {
        digitCount++; // Increment digit count
        num /= 10; // Remove last digit
    }
    return digitCount;
}

/**
 * @brief Checks if the given number is a left-truncatable prime using logarithm.
 * @param num The integer to check.
 * @return true if num is a left-truncatable prime, otherwise false.
 */
bool isLTPrimeWithLog(int num) {
    // TASK: Can you implement a copy of this with recursion, isLTPrimeWithLogRecursion?
    int digitCount = log10(num) + 1;
    while (digitCount > 0) {
        if (!isPrime(num)) return false;
        num %= static_cast<int>(pow(10, digitCount - 1)); // Remove the leftmost digit
        digitCount--;
    }
    return true;
}

/**
 * @brief Calculates the repeating decimal length for the reciprocal of a prime number.
 * @param primeNum The prime number.
 * @return The length of the repeating decimal sequence.
 */
int countReciprocalRepeat(int primeNum) {
    // TASK! Pen and paper required! Can you tell how this is working/not-working?
    if (!isPrime(primeNum)) return -1; // Return -1 for non-prime input
    int remainder = 1, position = 0;

    for (int i = 0; i < primeNum; ++i) {
        remainder = (remainder * 10) % primeNum;
        position++;
        if (remainder == 1) {
            return position;
        }
    }
    return 0;
}
/**
 * @brief Prints the reciprocal of a prime number with a given precision.
 * @param num The prime number.
 * @param precisionSize The number of decimal places to print.
 */
void printReciprocalWithPrecision(int num, int precisionSize) {
    if (!isPrime(num)) {
        cout << "Not a prime number." << endl;
        return;
    }
    int remainder = 1;
    cout << "With (PrecisionSize: " << precisionSize << ") " << 1 << "/" << num << " = 0.";
    for (int i = 0; i < precisionSize; ++i) {
        remainder *= 10;
        cout << remainder / num;
        remainder %= num;
    }
    cout << endl;
}

int main() {
    int testNum = 17;
    cout << "isPrime(" << testNum << ") = " << isPrime(testNum) << endl;
    cout << "isRTPrime(" << testNum << ") = " << isRTPrime(testNum) << endl;
    cout << "isLTPrime(" << testNum << ") = " << isLTPrime(testNum) << endl;
    cout << "isLTPrimeWithLog(" << testNum << ") = " << isLTPrimeWithLog(testNum) << endl;
    cout << "countDigits(" << testNum << ") = " << countDigits(testNum) << endl;
    int repeatLength = countReciprocalRepeat(testNum);
    cout << "countReciprocalRepeat(" << testNum << ") = " << repeatLength << endl;
    printReciprocalWithPrecision(testNum, 2 * repeatLength);
    return 0;
}

