#include "iter.hpp"

int main(){
    int int_array[] = {1,2,3,4,5};
    char char_array[] = {'a','b','c','d','e'};
    std::string string_array[] = {"aiu","kaki","sasi","tati","nani"};
    
    std::cout << "=================== int ===================" <<std::endl;
    iter(int_array, 5, func<int>);
    
    std::cout << "=================== char ===================" <<std::endl;
    iter(char_array, 5, func<char>);
    
    std::cout << "=================== string ===================" <<std::endl;
    iter(string_array, 5, func<std::string>);
    std::cout << std::endl;
}