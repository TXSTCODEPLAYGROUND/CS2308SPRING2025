#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
  
    //TOP PART 
    for(int i=0; i<n; i++){
        //Stars starting
        for (int j=0; j<i+1; j++){
            cout <<"*";
        }
        //spaces for between
        for(int j=0; j<n-i-1;j++){
            cout<< "  ";
            
        }
        //stars ending
        for(int j=0; j<i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
 
    //BOTTOM PART
    for(int i=0; i<n;i++){
        //First Line
        if(i==0){
            for(int j=0; j<n*2; j++){
                cout << "*";
            }
            cout << endl;
        }
        //Rest of the lines
        if(i!=0){
            //Stars
            for(int j=0; j<n-i; j++){
                cout <<"*";
            }
            //Spaces
            for(int j=0; j<i; j++){
                cout <<"  ";
            }

            for(int j=0; j<n-i;j++){
                cout<< "*";
            }
            cout << endl;
        }      
    }
    return 0;
}
        
    