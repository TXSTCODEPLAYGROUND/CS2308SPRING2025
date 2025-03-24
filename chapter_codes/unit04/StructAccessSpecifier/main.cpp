#include <iostream>
#include <vector>
using namespace std;
struct Person{
    private:
        string name, ssn, pin, phone;
        bool validate();
        Person(string s, string p)
              :ssn(s), pin(p) {}
    public:
        vector<string> hobbies;
        Person(string n, string s, string p)
              :name(n), ssn(s), pin(p) {}
        string getSSN();
        string getPhone();
        void updatePhone(string const&);
};

bool Person::validate(){
    string pin;
    cout << "Enter pin: ";
    cin >> pin;
    return pin == this->pin;
}

string Person::getSSN(){
    if(validate()) return this->ssn;
    else return "000-00-000";
    }

string Person::getPhone(){
    if(validate()) return this->phone;
    else return "000-000-0000";
}

void Person::updatePhone(string const& phone){
    if(validate()){
        this->phone = phone;
        cout << "Phone Updated" << endl;
    }else
            cerr << "Error!! User not validated" << endl;
}

int main(){
    // This is you who created the instance, you know your pin
    Person person("Keshav", "xxx-yy-zzzz", "1234");
    // Lets get ssn
    cout << person.getSSN() << endl;
}