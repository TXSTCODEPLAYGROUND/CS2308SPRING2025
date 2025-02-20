#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    double arr[] = {7.23, 9.1, 3.39, 2.1, 5.6, 19.3, 28.9, 8.29};
    int size = std::size(arr);

    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]){std::swap(arr[j], arr[j + 1]);}
        }
    }

    for (double element : arr) {std::cout << element << " ";}

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.