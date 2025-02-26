#include <iostream>
#include <vector>
using namespace std;

int main(){
    //vector integers
    vector<int> num;

    //pushing elements into vector
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    //printing elements of vector
    cout << "Elements of vector: ";
    for(int i=0; i<num.size();i++){
        cout << num[i] << " ";
    }
    cout << endl;

    //access elements of vector
    cout << "Element at index 1: " << num.at(1) << endl;

    //modifying elements of vector
    num[1] = 4;
    cout << "Modified element at index 1: " << num.at(1) << endl;

    // remove last element
    num.pop_back();
    cout << "Elements of vector after removing last element: ";
    for(int i=0; i<num.size();i++){
        cout << num[i] << " ";
    }
    cout << endl;

    //insert element at specific position
    num.insert(num.begin()+1, 5);
    cout << "Elements of vector after inserting element at index 1: ";
    for(int i=0; i<num.size();i++){
        cout << num[i] << " ";
    }
    cout << endl;

    //erase element at specific position
    num.erase(num.begin()+1);
    cout << "Elements of vector after erasing element at index 1: ";
    for(int i=0; i<num.size();i++){
        cout << num[i] << " ";
    }
    cout << endl;

    //clear all elements of vector
    num.clear();
    cout << "Elements of vector after clearing all elements: ";
    for(int i=0; i<num.size();i++){
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}