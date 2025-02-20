#include <iostream>
using namespace std;

inline int add(int a=10, int b=50) {
    return a+b;
}
int main() {
    //Function calling and changing parameter only for second paramenter.
    cout<<add(a=10,b=50);
    /*Only way to change the second parameter is to pass the first parameter
    with the same value*/
    return 0;


}


