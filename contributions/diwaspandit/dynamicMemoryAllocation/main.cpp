#include <iostream>
using namespace std;

//OneDArray function
int* OneDArray(int size) {
    int* arr = new int[size]; // Allocates memory on the heap

    // Initialize array
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    return arr;  
}

//TwoDArray function
int** TwoDArray(int rows, int cols) {
    int** arr = new int*[rows]; // Allocates memory on the heap

    // Initialize array
    for (int i = 0; i < rows; i++) {
        arr[i] = OneDArray(cols);
    }

    return arr;  
}

//ThreeDArray function
int*** ThreeDArray(int rows, int cols, int depth) {
    int*** arr = new int**[rows]; // Allocates memory on the heap

    // Initialize array
    for (int i = 0; i < rows; i++) {
        arr[i] = TwoDArray(cols, depth);
    }

    return arr;  
}

//function to print 1D array
void printOneDArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//function to print 2D array
void printTwoDArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printOneDArray(arr[i], cols);
    }
}

//function to print 3D array
void printThreeDArray(int*** arr, int rows, int cols, int depth) {
    for (int i = 0; i < rows; i++) {
        printTwoDArray(arr[i], cols, depth);
    }
}

//delete 2D array
void deleteTwoDArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

//delete 3D array
void deleteThreeDArray(int*** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        deleteTwoDArray(arr[i], cols);
    }
    delete[] arr;
}


//main function
int main(){
    int rows = 2, cols = 3, depth = 4;

    //1D array
    int* arr1D = OneDArray(rows);
    cout << "1D Array: ";
    printOneDArray(arr1D, rows);
    cout << endl;

    //2D array
    int** arr2D = TwoDArray(rows, cols);
    cout << "2D Array: " << endl;
    printTwoDArray(arr2D, rows, cols);
    cout << endl;

    //3D array
    int*** arr3D = ThreeDArray(rows, cols, depth);
    cout << "3D Array: " << endl;
    printThreeDArray(arr3D, rows, cols, depth);
    cout << endl;

    //Memory Cleanup
    deleteThreeDArray(arr3D, rows, cols);

    return 0;
}


