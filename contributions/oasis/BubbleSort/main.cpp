#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<=n-1;i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector<int> arr = {3,2,7,4,10,1};
    bubbleSort(arr);

    return 0;
}