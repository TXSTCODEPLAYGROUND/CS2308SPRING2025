#include <iostream>
#include <random>

/**
 * @brief Generates a random integer in the given range.
 * @param low Minimum possible value (default: 0).
 * @param high Maximum possible value (default: 10).
 * @return Randomly generated integer.
 */
int randNum(int low = 0, int high = 10) {
    std::random_device rd;  // Seed for randomness
    std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<> dis(low, high);
    return dis(gen);
}

/**
 * @brief Creates a dynamically allocated 1D array and fills it with random values.
 * @param size Size of the array.
 * @return Pointer to the dynamically allocated 1D array.
 */
int* create1DArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = randNum();
    return arr;
}

/**
 * @brief Creates a dynamically allocated 2D array using an array of pointers.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return Pointer to the dynamically allocated 2D array.
 */
int** create2DArray(int rows, int cols) {
    int** array2d = new int*[rows];
    for (int i = 0; i < rows; i++)
        array2d[i] = create1DArray(cols);
    return array2d;
}

/**
 * @brief Creates a dynamically allocated 3D array using pointers to pointers.
 * @param depth Number of depth layers.
 * @param rows Number of rows per depth.
 * @param cols Number of columns per row.
 * @return Pointer to the dynamically allocated 3D array.
 */
int*** create3DArray(int depth, int rows, int cols) {
    int*** array3d = new int**[depth];
    for (int i = 0; i < depth; i++)
        array3d[i] = create2DArray(rows, cols);
    return array3d;
}

/**
 * @brief Displays a 1D array.
 * @param arr Pointer to the 1D array.
 * @param size Size of the array.
 */
void display(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}

int main() {
    int* onedarray = create1DArray(5);
    int** twodarray = create2DArray(3, 3);
    int*** threedarray = create3DArray(2, 3, 3);

    std::cout << "---1D---" << std::endl;
    display(onedarray, 5);

    std::cout << "---2D---" << std::endl;
    display(twodarray[0], 3);
    display(twodarray[1], 3);
    display(twodarray[2], 3);

    std::cout << "---3D---" << std::endl;
    display(threedarray[0][0], 3);
    display(threedarray[0][1], 3);
    display(threedarray[0][2], 3);
    std::cout << std::endl;
    display(threedarray[1][0], 3);
    display(threedarray[1][1], 3);
    display(threedarray[1][2], 3);

    return 0;
}