#include <iostream>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        bool swapped = false;
        for (int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
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

    bubbleSort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}