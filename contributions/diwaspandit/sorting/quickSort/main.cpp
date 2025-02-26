#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int randomIndex = low + rand()% (high - low);
    swap(arr[randomIndex], arr[high]);
    int pivot = arr[high];
    int i= low-1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
}

int main(){

    int arr[]={10, 7, 8, 9, 1, 5};
    int n= sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    
    quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}