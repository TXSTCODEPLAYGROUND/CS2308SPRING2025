/**
 * @file    lambda_examples.cpp
 * @author  Kimberly Stuart
 * @course  CS2308 - Foundations of Programming
 * @date    2025-02-11
 *
 * @brief   Demonstrates the use of lambda functions in C++ with different use cases.
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
#include <vector>

// Function to print vector elements using a simple for-loop
void printVector(const std::vector<int>& vec, const std::string& message){
    std::cout << message << ": ";
    for(int num : vec){
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// Function to apply a simple transformation (e.g., multiply each number by 2)
void doubleNumbers(std::vector<int>& vec){
    for(int& num : vec){
        num *= 2; // Double each number directly in the loop
    }
}

int main() {

    // Using std::vector instead of raw arrays for easier management
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // Sorting the vector in ascending order using a lambda function
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a < b; });
    printVector(numbers, "Sorted in Ascending Order");

    // Sorting the vector in decending order using a lambda function
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
    printVector(numbers, "Sorted in Descending Order");

    // Lambda function capturing a value (multiplier)
    int multiplier = 3;
    auto multiply = [multiplier](int num){
        return num * multiplier;
    };

    std::cout << "Multiply 4 by " << multiplier << ": " << multiply(4) << "\n";

    // Lambda function capturing a reference (counter)
    int counter = 0;
    auto increment = [&counter](){
        counter++;
    };

    increment();
    increment();
    std::cout << "Counter after two increments: " << counter << "\n";

    // Apply transformation (double each number)
    doubleNumbers(numbers);
    printVector(numbers, "Doubled Numbers");

    return 0;
}
