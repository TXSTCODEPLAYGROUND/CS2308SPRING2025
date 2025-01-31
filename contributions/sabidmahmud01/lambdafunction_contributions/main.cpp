#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    // Define a lambda function
    auto add = [](int x, int y) {
        return x + y;
    };

    // Call the lambda function
    int result = add(3, 5);
    std::cout << "Result: " << result << std::endl;  // Output: Result: 8

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.