#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();

    for(int i=0; i<=n-2;i++){
        int minIdx = i;
        for(int j=i+1; j<=n-1; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector<int> arr = {3,2,7,4,10,1};
    selectionSort(arr);

    return 0;
}