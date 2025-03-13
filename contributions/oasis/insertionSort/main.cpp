#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();

    for(int i=1; i<=n-1; i++){
        int j = i;
        while(j>0 && arr[j-1]> arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector<int> arr = {3,2,7,4,10,1};
    insertionSort(arr);

    return 0;
}