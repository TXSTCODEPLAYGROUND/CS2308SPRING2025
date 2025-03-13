#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& arr, int low, int high){
    int i =  low;
    int j = high;
    int pivot = arr[low];

    while(j>=i){
        while(arr[i] <= pivot && i<=high){
            i++;
        }

        while(arr[j] > pivot && j > low){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[low], arr[j]);
    int partIdx = j;
    return j;
}

void quicksort(vector<int>& arr, int low, int high){
    if(low<high){
        int partIdx = partition(arr,low,high);
        quicksort(arr, low, partIdx - 1);
        quicksort(arr, partIdx + 1, high);
    }
}

int main(){
    vector<int> arr = {4,3,1,7,2,5,9};
    int low = 0; 
    int high = arr.size() - 1;

    quicksort(arr, low, high);
    
    for(int i=0; i<= high; i++){
        cout << arr[i] << " ";
    }
    return 0;
}