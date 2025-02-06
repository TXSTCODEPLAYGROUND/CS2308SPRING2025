#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> vec; //size is 0
    vec = {1,2,3,4,5};

    vector<char> letters(4,'a'); // This will create a vector of size 4 and all elements will be 'a'
    for (char i : letters){
        cout << i << endl;
    }

    for (int i : vec){ // This is like for apple in apples (in python)
        cout << i << endl;
    }

    // VECTOR FUNCTONS:
    cout << vec.size() << endl; // Prints size of the vector
    vec.push_back(5); //Appends 5 in the end
    vec.pop_back(); // Removes the last element of the vector 
    vec.front(); // gets the first element
    vec.back(); // gets last value
    vec.at(5); // equivalent to vec[i] THIS WILL CHECK BOUNDS!
    vec.insert(vec.begin()+2,99); //Inseting in a spcific position

    
    return 0;
} 