#include <iostream>
using namespace std;
struct Student {
    string name;
    string ID;
    Student(const string& n, const string& i) : name(n), ID(i) {
        cout << "Creating Student: "<< name << endl;
    }
    void display() const {
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->ID << endl;
    }
    ~Student() {
        cout << "Deleting Student: "<< this->name << endl;
    }
};

int main() {
    Student student("John", "A001");
    Student* pstudent = new Student("Jack", "B001");

    student.display();
    pstudent->display();
    // Why we need following?
    delete pstudent;
}

