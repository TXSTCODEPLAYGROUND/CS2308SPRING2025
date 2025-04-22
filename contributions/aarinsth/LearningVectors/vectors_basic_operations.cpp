// This is a program regarding performing of basic operations using vectors
#include <iostream>
#include <vector>


int main() {

    std::vector<int> numbers; // Create an empty vector

    // Adding elements to a vector
    numbers.push_back(10); // Add 10 to the vector
    numbers.push_back(20); // Add 20 to the vector
    numbers.push_back(30); // Add 30 to the vector

    // Newer versions of C++ compilers also support initialization of vectors in the following way:
    // (By adding value already during declaration)
    //  std::vector<int> numbers = {10, 20, 30};

    int vectorSize = numbers.size(); //Find number of elements

    // Traversing through the vector numbers to fetch values
    for (int i=0; i<vectorSize; i++) {
        std::cout << "Vector Index: " << i << ", ";
        std::cout << "Element: " << numbers[i] << std::endl;
    }

}