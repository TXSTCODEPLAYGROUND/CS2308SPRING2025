#include <iostream>
using namespace std;

void swap(int &x,int &y){
    int tempval1 = x;
    x = y;
    y = tempval1;
}

int main(){

    int SIZE =9;
    int arr[SIZE] = {1,2,3,4,5,6,7,8,9};
    int start =0;
    int end = SIZE-1;

    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
    for (int i=0; i< SIZE; i++){
        cout << arr[i];
    }
   return 0;
}