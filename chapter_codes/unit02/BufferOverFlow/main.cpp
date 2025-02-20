#include <iostream>
#include <cstring>
using namespace std;

void bufferOverflowExample() {
    char password[8];  // Buffer to store a password (size 8, including null terminator)
    char *hack = nullptr;

    // Initialize password with some value
    strcpy(password, "secret");

    cout << "Password before overflow: " << password << endl;

    // Unsafe pointer manipulation
    hack = password; // Point hack to the password buffer

    // Buffer overflow: Writing beyond the allocated memory for password
    strcpy(hack, "longpasswordthatbreaks"); // Overwrites adjacent memory

    // Now accessing password might lead to undefined behavior
    cout << "Password after overflow: " << password << endl;

    // Adjacent memory might have been corrupted silently
    cout << "Pointer hack value: " << hack << endl;
}

int main() {
    bufferOverflowExample();
    return 0;
}