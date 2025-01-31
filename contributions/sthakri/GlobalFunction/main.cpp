#include <iostream>
using namespace std;

int globalVar= 10;

void justaFunction(){
    //This is a local variable only know to this function.
    int globalVar = 15; //This local variable overrides/shadows the global variable inside this function.
    cout << "Variable within function is " << globalVar <<endl;
}
void changeGlobalvar(){
    globalVar+=1; //As there is no local variable within this function,this will modify the global Variable.
    cout <<"Modified Global Variable is " <<globalVar <<endl;
}

int main() {
    cout <<"Global Variable is " << globalVar << endl;
    justaFunction();
    changeGlobalvar();
    cout <<"After modification Global Variable is " <<globalVar <<endl;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.