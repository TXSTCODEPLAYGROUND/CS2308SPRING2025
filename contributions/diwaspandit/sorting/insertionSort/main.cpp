#include <iostream>
using namespace std;

// Insertion Sort Function
void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int prev= i-1;
        while(prev>=0 && arr[prev]>current){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
    }
}

// Print Array Function
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Main Function
int main(){
    int arr[]= {8, 5, 2, 6, 9, 3, 1, 4, 0, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}