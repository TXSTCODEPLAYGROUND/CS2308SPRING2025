#include <iostream>
using namespace std;
#include <cmath>
int main(){

    // *
    // **
    // ***
    // ****
    // *****

    // int n;
    // cin >> n;
    // int i = 1;    
    // for (int j=0; j < n; j++){
    //     for(int i=0;i<j+1;i++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // 1
    // 22
    // 333
    // 4444
    // 55555

    // int n;
    // cin >>n;
    // int number;
    // for (int j=0; j<n; j++){
    //     for(int i=0; i<j+1; i++){
    //         cout << j+1;
    //     }
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // A 
    // BB 
    // CCC 
    // DDDD 
    // EEEEE

    // int n;
    // cin >> n;
    // char ch = 'A';
    // for(int j=0; j<n;j++){
    //     for(int i=0; i<j+1;i++){
    //         cout << ch;
    //     }
    //     ch +=1;
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // 1
    // 12
    // 123
    // 1234

    // int n;
    // cin >> n;
    // for(int i=0; i<n; i++){
    //     int num = 1;
    //     for(int j=0; j<i+1; j++){
    //         cout << num + j;
    //     }
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // 1
    // 21
    // 321
    // 4321
    // 54321

    // whenever you need to do a backward pattern, change the i thing, eg: instead of int i=0; i < 5; i++ do i=5; i>0; i--

    // int n;
    // cin >>n;

    // for (int j=0; j<n; j++){
    //     for (int i=j+1; i>=1; i--){
    //         cout << i;
    //     }
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // FLOYD'S TRIANGLE PATTERN
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10

    // int n;
    // cin >> n;

    // int counter = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout << counter << " ";
    //         counter++;
    //     }
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // A
    // B C
    // D E F
    // G H I J K 

    // int n;
    // cin >> n;
    // char ch= 'A';

    // for (int i=0; i<n; i++){
    //     for (int j=0; j< i+1; j++){
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

// ------------------------------------------------------------

    // A
    // B A
    // C B A 
    // D C B A

    // int n;
    // cin >> n;
    // for(int i=0; i<n; i++){
    //     char ch='A';
    //     ch = ch + i;
    //     for(int j= i+1; j > 0; j--){
    //         cout << ch << " ";
    //         ch--;
    //     }
    //     cout << endl;
    // }


    return 0;
}