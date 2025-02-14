#include <iostream>
#include "utils.h"

int add(int x, int y){          //WRITE FUNCTIONS IN AN ORGANIZED MANNER IN UTILS FILE
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

void output_message(std::string message){
    std::cout << message << std::endl;
}