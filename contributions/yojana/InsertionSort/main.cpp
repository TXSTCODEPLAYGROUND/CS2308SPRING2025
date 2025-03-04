#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];//storing the value of current element
        int prev = i-1; //storing the index of previous element
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];//shifting the value of previous to right
            prev--;
        }
        arr[prev+1]=curr;
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}

int main(){
    int n=5;
    int arr[]={1,3,4,6,7};
    insertionSort(arr, n);
    display(arr, n);
}