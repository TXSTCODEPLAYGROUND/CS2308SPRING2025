#include <iostream>
using namespace std;

int main(){
    // int n;
    // cin >>n;
    // int counter = 1;
    // for(int j=0;j<n;j++){
    //     for(int i=1;i<=n;i++){
    //         cout << counter << " ";
    //         counter++;
    //     }
    //     cout << endl;
    // }
    int n;
    cin >> n;
    char ch = 'A';
    for (int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            cout << ch << " ";
            ch += 1;
        }
        cout << endl;
    }
    return 0;
}