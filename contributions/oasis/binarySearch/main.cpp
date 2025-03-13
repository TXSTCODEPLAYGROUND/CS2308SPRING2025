#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==target){
        return mid;
    }else if(arr[mid]<target){
        return binarySearch(arr, mid + 1, high , target);
    }else{
        return binarySearch(arr, low, mid - 1 , target);
    }
    
}


int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int n = arr.size();
    int low = 0; 
    int high = n-1;

    int target;
    cin >> target;

    cout << binarySearch(arr, low, high , target);
    return 0;
}