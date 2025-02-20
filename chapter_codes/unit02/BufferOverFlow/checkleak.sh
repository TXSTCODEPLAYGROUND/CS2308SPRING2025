export MallocStackLogging=1
clang++ --std=c++20 -g main.cpp -o leaktest
leaks --atExit -- ./leaktest 3
export MallocStackLogging=0
rm leaktest