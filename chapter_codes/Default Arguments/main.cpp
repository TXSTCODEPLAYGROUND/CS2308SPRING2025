#include <iostream>
//original function with default variables
double area_of_circle(double pi = 3.14, int r = 1) {
    return pi * r * r;
}
//overloaded function with reversed variable order
double area_of_circle(int r, double pi = 3.14) {
    return 3.14*r*r;
}
int main(){
    double a = area_of_circle();
    //First possible solution to changing second default: typing out default value of pi
    double b = area_of_circle(3.14, 2);
    //Second possible solution, in case of different variable typings you can overload the function and switch the variable order
    //This allows you to type a value for a either r or pi without changing the default for the other
    double c = area_of_circle(2);
    std::cout << "Circle a has area " << a <<
        "\nMeanwhile circle b has an area of " << b <<
            "\nWhich is the same as circle c's area " << c << std::endl;
    return 0;
};
