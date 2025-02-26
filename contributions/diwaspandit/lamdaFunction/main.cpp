#include <iostream>
using namespace std;

// main function
int main(){
    
    // lambda function to add two numbers
    auto add = [](int a, int b){
        return a+b;
    };

    cout << add(5, 6) << endl;
    return 0;
}