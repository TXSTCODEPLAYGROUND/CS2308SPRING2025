#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

int SIZE = 5, LOW = 10, HIGH = 99;
int PRECISION = log10(HIGH) + 1;
int COUNT = 0;

// SOME HELPER FUNCTIONS

void swapPair(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

string formatIntPrecision(int num, int precision){
    /*
        if num = 23, precision = 3, returns 023
    */
    string num_str = to_string(num);
    return num_str.insert(0, precision - num_str.size(), '0');
}

void displayArray(int* arr, int size, int i, int j, string extrainfo){
   
    cout << endl << "    i  =  ";
    cout << setw(PRECISION+i*(2+PRECISION)) << formatIntPrecision(i, PRECISION) << endl; 
    cout << "arr[ ] = {";
    for (size_t i = 0; i < size; i++){
         cout << formatIntPrecision(arr[i], PRECISION) << ", ";
    }
    cout << "\b\b}" << extrainfo << endl;
    cout << "    j  =  ";
    cout << setw(PRECISION+j*(2+PRECISION)) << formatIntPrecision(j, PRECISION) << endl << endl; 

}

int randIntGenerator(int low, int high) {
    random_device rd;  // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> distribution(low, high); // Define the range
    return distribution(eng); // Generate the random number
}


int* randArr(int size, int low, int high) {
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = randIntGenerator(low, high);
    return arr;
}


void selectionSort(int*arr, int size) {
    int i, j;
    for(i = 0; i < size-1; i++){
        for(j = i+1; j < size; j++){
            COUNT++;
            
            displayArray(arr, SIZE, i, j, "");
            if(arr[i] > arr[j]) swapPair(arr[i], arr[j]);
        }
    }
    displayArray(arr, SIZE, i, j, "");
}

void insertionSort(int*arr, int size) {
    int i, j, key;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            displayArray(arr, SIZE, i, j, " key = "+to_string(key));
            COUNT++;
            arr[j+1] = arr[j];
            --j;
        }
        displayArray(arr, SIZE, i, j, " key = "+to_string(key));
        arr[j+1] = key;
    }
    displayArray(arr, SIZE, i, j, " key = "+to_string(key));
}

void bubbleSort(int* arr, int size) {
    int i, j;
    for(i = 0; i < size - 1; i++){
        for(j = 0 ; j < size - i - 1; j++){
            COUNT++;
            displayArray(arr, SIZE, i, j,"");
            if(arr[j] > arr[j+1]) swapPair(arr[j], arr[j+1]);
        }
    }
    displayArray(arr, SIZE, i, j, "");
}


int qPartition(int* arr, int low, int high){
    int pivot = arr[high];
    int left = low - 1, right = high;
    string info = "low = " + to_string(low) + ", high = " + to_string(high);

    while(true){
        while(arr[++left] < pivot){
            displayArray(arr, SIZE, left, right, info+ " left = " + to_string(left) + ", right = " + to_string(right));
            COUNT++;
        }
        while(arr[--right] > pivot){
            displayArray(arr, SIZE, left, right, info+ " left = " + to_string(left) + ", right = " + to_string(right));
            COUNT++;
        }
        if(left < right){
            COUNT++;
            displayArray(arr, SIZE, left, right, info+ " left = " + to_string(left) + ", right = " + to_string(right));
            swapPair(arr[left], arr[right]);
        }
        else break;
    }
    swapPair(arr[left], arr[high]);
    displayArray(arr, SIZE, left, right, info+ " left = " + to_string(left) + ", right = " + to_string(right));
    return left;
}

void quickSort(int* arr, int low, int high){
    if(low < high){
        int partition = qPartition(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}

void randQuicksort(int* arr, int low, int high){
    if(low < high){
        int rand_pivot = randIntGenerator(low, high);
        swapPair(arr[rand_pivot], arr[high]);
        int partition = qPartition(arr, low, high);
        quickSort(arr,low, partition - 1 );
        quickSort(arr, partition + 1, high);
    }
}

int* copyArr(int* arr, int size){
    int *arr_copy = new int[size];
    for(int i = 0; i < size; i++) arr_copy[i] = arr[i];
    return arr_copy;
}

int main(int argc, char const *argv[]){
    int *arr = randArr(SIZE, LOW, HIGH);
    // Bubble Sort
    cout << "-----------------------" << endl;
    cout << "Algorithm : BUBBLE-SORT"  << endl;
    cout << "-----------------------" << endl;
    COUNT = 0;
    bubbleSort(copyArr(arr, SIZE), SIZE);
    cout << "-- #RUNS = "<< COUNT <<" -----------------------" << endl;
    
    // Insertion
    cout << "-----------------------" << endl;
    cout << "Algorithm : INSERTION-SORT"  << endl;
    cout << "-----------------------" << endl;
    COUNT = 0;
    insertionSort(copyArr(arr, SIZE), SIZE);
    cout << "-- #RUNS = "<< COUNT <<" -----------------------" << endl;

    // Insertion
    cout << "--------------------------" << endl;
    cout << "Algorithm : SELECTION-SORT"  << endl;
    cout << "--------------------------" << endl;
    COUNT = 0;
    selectionSort(copyArr(arr, SIZE), SIZE);
    cout << "-- #RUNS = "<< COUNT <<" -----------------------" << endl;
    
    // Quick Sort
    cout << "-----------------------" << endl;
    cout << "Algorithm : QUICK-SORT"  << endl;
    cout << "-----------------------" << endl;
    COUNT = 0;
    quickSort(copyArr(arr, SIZE), 0, SIZE-1);
    cout << "-- #RUNS = "<< COUNT <<" -----------------------" << endl;

    // Randomized Quick Sort
    cout << "---------------------------" << endl;
    cout << "Algorithm : RandQUICK-SORT"  << endl;
    cout << "---------------------------" << endl;
    COUNT = 0;
    randQuicksort(copyArr(arr, SIZE), 0, SIZE-1);
    cout << "-- #RUNS = "<< COUNT <<" -----------------------" << endl;
    return 0;
}
