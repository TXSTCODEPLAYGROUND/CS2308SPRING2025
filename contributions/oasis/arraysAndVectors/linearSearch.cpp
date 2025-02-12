#include <iostream>
using namespace std;

int search (int arr[], int n){
    
    for (int i = 0; i < 7; i++){
        if (arr[i] == n){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[7] = {4, 2, 7, 8, 1, 2, 5};
    cout << search(arr, n);
    
    return 0;
}