#include "iter.h"

int main(){
    char char_array[] = {'a','b','c','d','e'};
    int int_array[] = {2147483647,21474836,0,-21474836,-2147483648};
    size_t size_t_array[] = {0,2,3,4,4294967295};
    int unsigned uint_array[] = {0,2,5,2147483647,4294967295};
    long long ll_array[] = {0,2,5,2147483647,4294967295};
    float float_array[] = {0, 2.f, 5.2f, 0.03f, 4};
    double double_array[] = {0, 2.0, 5.2, 0.03, 4};
    std::string string_array[] = {"aiu","kaki","sasi","tati","nani"};
    
    std::cout << "=================== char ===================" <<std::endl;
    iter(char_array, 5, func<char>);

    std::cout << "=================== int ===================" <<std::endl;
    iter(int_array, 5, func<int>);

    std::cout << "=================== size_t ===================" <<std::endl;
    iter(size_t_array, 5, func<size_t>);
    
    std::cout << "=================== unsigned int ===================" <<std::endl;
    iter(uint_array, 5, func<unsigned int>);

    std::cout << "=================== long long ===================" <<std::endl;
    iter(ll_array, 5, func<long long>);

    std::cout << "=================== float ===================" <<std::endl;
    iter(float_array, 5, func<float>);

    std::cout << "=================== double ===================" <<std::endl;
    iter(double_array, 5, func<double>);
    
    std::cout << "=================== string ===================" <<std::endl;
    iter(string_array, 5, func<std::string>);
    std::cout << std::endl;
}