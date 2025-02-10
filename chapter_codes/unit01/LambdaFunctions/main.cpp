/**
 * @file    lambda_examples.cpp
 * @author  Keshav Bhandari
 * @course  CS2308 - Foundations of Programming
 * @date    2025-01-30
 *
 * @brief   Demonstrates the use of lambda functions in C++ with different use cases.
 *
 * 
 * This program showcases various ways to use lambda functions, including:
 * - Sorting a C-style array using lambda as a comparator
 * - Capturing variables by value and by reference in lambda functions
 * - Using a lambda function to modify an external variable
 * - Passing a lambda function as an argument to another function
 *
 * The program primarily focuses on how lambda functions can make code more
 * concise and readable while demonstrating key features of C++ functional programming.
 */

#include <iostream>
#include <algorithm>
#include <functional>

int main() {
    // Declare a fixed-size array
    int numbers[] = {5, 2, 9, 1, 5, 6};
    const int size = sizeof(numbers) / sizeof(numbers[0]); // Calculate the size of the array

    /**
     * @brief Sorts the array in ascending order using a lambda function.
     *
     * The lambda function takes two integers (a and b) and returns true if
     * 'a' should appear before 'b', ensuring an increasing order.
     */
    std::sort(std::begin(numbers), std::end(numbers), [](int a, int b) {
        return a < b; // Sorting condition for ascending order
    });

    std::cout << "Sorted in Ascending Order: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    /**
     * @brief Sorts the array in descending order using a lambda function.
     *
     * The lambda function takes two integers (a and b) and returns true if
     * 'a' should come after 'b', ensuring a decreasing order.
     */
    std::sort(std::begin(numbers), std::end(numbers), [](int a, int b) {
        return a > b; // Sorting condition for descending order
    });

    std::cout << "Sorted in Descending Order: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // Capturing a variable by value (multiplier)
    int multiplier = 3;

    /**
     * @brief Captures the variable 'multiplier' by value and multiplies an input by it.
     *
     * The captured value is fixed at the time of lambda creation and does not change.
     *
     * @param num Integer input to be multiplied.
     * @return The result of num * multiplier.
     */
    auto multiply = [multiplier](int num) {
        return num * multiplier; // Uses a captured variable inside the lambda
    };

    std::cout << "Multiply 4 by " << multiplier << ": " << multiply(4) << "\n";

    // Capturing a variable by reference (counter)
    int counter = 0;

    /**
     * @brief Captures 'counter' by reference and modifies its value.
     *
     * Since 'counter' is captured by reference, any changes made inside the
     * lambda persist outside its scope.
     */
    auto increment = [&counter]() {
        counter++; // Modifies the external variable 'counter'
    };

    increment(); // Increment counter
    increment(); // Increment counter again
    std::cout << "Counter after two increments: " << counter << "\n";

    /**
     * @brief Function that applies a transformation function to each element of an array.
     *
     * @param arr The integer array to modify.
     * @param size The size of the array.
     * @param func A lambda function (or any callable function) that takes an integer
     *             and returns a transformed integer.
     */
    auto applyFunction = [](int arr[], int size, std::function<int(int)> func) {
        for (int i = 0; i < size; i++) {
            arr[i] = func(arr[i]); // Apply the function to each element of the array
        }
    };

    /**
     * @brief Doubles each element in the array using a lambda function.
     */
    applyFunction(numbers, size, [](int num) { return num * 2; });

    std::cout << "Doubled numbers: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
