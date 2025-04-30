//
// Created by ASUS on 2/8/2025.
//

#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int> list) {
  for (int i = 1; i < list.size(); i++) {
    int temp = list[i];
    int position = i - 1;
    while (position >= 0 && list[position] >= temp) {
      list[position + 1] = list[position];
      position--;
    }
    list[position + 1] = temp;
  }
  return list;
}

std::vector<int> getInput() {
  std::vector<int> list;
  int input;
  char cont;

  do {
    std::cout << "Enter number to be sorted: ";
    std::cin >> input;
    list.push_back(input);

    std::cout << "Do you want to continue (y/n): ";
    std::cin >> cont;
  } while (cont != 'n');  // Check character, not the integer input

  return list;
}

int main() {
  std::vector<int> list = getInput();
  for (int i : list){
    std::cout<<i<<" ";
  }
  std::cout<<std::endl;
  std::vector<int> sortedList = insertionSort(list);
  for (int i : sortedList) {
    std::cout<<i<<" ";
  }

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.