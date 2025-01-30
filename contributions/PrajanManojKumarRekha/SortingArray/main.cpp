#include <iostream>
#include <algorithm>
using namespace std;

//Using the library algorithm in order to sort an array!
int main(){

    int arr[]={5,6,9,1,11,2};
    int Size = sizeof(arr)/sizeof(arr[0]); //This line is used to find a unknown size of the array.

    sort(arr,arr+Size,greater<int>()); /*This specific greater<int>() helps comparing
    the two integers and finding which is the greater one! just like a>b */
    /* You can also use lesser<int>() for ascending order and if its another data type you can use
     greater<>()*/

    for(int i=0;i<Size;i++){cout<<arr[i]<<",";
    }
    cout<<"\b \b";



    return 0;
}
