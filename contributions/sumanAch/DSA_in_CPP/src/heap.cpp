#include <iostream>
using namespace std;;

class MinHeap{
    public:
        int arr[100];
        int size;
        MinHeap(){
            arr[0] = -1;
            size = 0; 
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index / 2;
                if(arr[parent]>arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i = 1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

class MaxHeap{

    public:
        int arr[100];
        int size;
        MaxHeap(){
            arr[0] = -1;
            size = 0; 
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index / 2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i = 1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
       
};


int main(){
    cout<<"..................Implementing Max heap........................."<<endl;
    MaxHeap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(50);
    h1.insert(5);
    h1.insert(2);
    h1.insert(40);
    h1.insert(30);
    h1.print();
    cout<<".................Implementing Min Heap............................."<<endl;
    MinHeap h2;
    h2.insert(10);
    h2.insert(20);
    h2.insert(50);
    h2.insert(5);
    h2.insert(2);
    h2.insert(40);
    h2.insert(30);
    h2.print();
    return 0;
}