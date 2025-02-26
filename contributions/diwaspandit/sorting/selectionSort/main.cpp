#include <iostream>
using namespace std;


// Selection Sort Function
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int smallestIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
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

    selectionSort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}