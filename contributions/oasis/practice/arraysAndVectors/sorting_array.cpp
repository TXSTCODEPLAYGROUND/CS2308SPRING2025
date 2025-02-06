#include <iostream>
using namespace std;

void sort(int arr[]){
    int tempval;
    for(int i=0; i<4; i++){
        if(arr[i]>arr[i+1]){
            tempval = arr[i+1];
            arr[i+1]= arr[i];
            arr[i] = tempval;
        }
    }
}

int main(){
    int arr[5] = {5,3,4,2,1};
    for (int i=0; i<=4; i++){
        sort(arr);
    }

    for (int i=0; i<=4; i++){
        cout << arr[i];
    }
    return 0;
}