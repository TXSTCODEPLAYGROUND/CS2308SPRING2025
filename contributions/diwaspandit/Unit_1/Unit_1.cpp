
// Lamda Function
#include <iostream>
using namespace std;

int main(){
    // lamda function t oadd two numbers
    auto add= [] (int a, int b) -> int {
        return a+b;
    };

    int result = add(10, 20);

    cout << "Result: " << result << endl;

    return 0;
}



