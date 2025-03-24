#include <iostream>
#include <vector>
using namespace std;

struct Person{
    string name, ssn, pin, phone;
    Person(string na, string ss, string pi, string ph):
           name(na), ssn(ss), pin(pi), phone(ph) {}
    void showData() const{
        cout << " Name: " << this->name << endl;
        cout << "  SSN: " << this->ssn << endl;
        cout << "  PIN: " << this->pin << endl;
        cout << "Phone: " << this->phone << endl;
    }
};

int main(){
    // You logged into CreditCard Website and added your credential
    // As of server is running in background
    // Following is you signing up
    Person person("Me", "123-45-6789", "1234", "1234567890");
    // Assume HACKER, has control after sometime and following is the
    // hacker or someone who is not you
    // Question... Can they do following?
    // Question... read your credentials..
    cout << "Accessing credentials..." << endl;
    cout << person.name << endl; // yes they can
    cout << person.ssn << endl; // yes they can and so on...
    // Can they temper your data
    cout << "Printing all credentials..." << endl;
    person.ssn = "xxx-yy-zzzz"; // yes they can
    // Print all credentials
    person.showData();
}