#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool isSwap=false;
        //optimized version if the array is already sorted, can stop bubble sort
        for(int j=0; j<n-i-1; j++){
            //n-i-1 as n-i-1 comparisions are done in every iterations(if i =0, n-1 comparisions, if i=1, n-2 comparisions and so on )
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
                //true if any swapping is done
            }

        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ",";
    }
    cout << endl;

}

int main(){
    int n=5;
    int arr[]= {4,1,5,2,3};

        bubbleSort(arr,n);
        printArray(arr, n);
        return 0;
}