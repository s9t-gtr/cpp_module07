#ifndef __ITER_HPP
# define __ITER_HPP

#include <iostream>

template <typename T>
void func(T elem){
   std::cout << elem << std::endl; 
}

template <typename T1, typename T2, typename T3>
void iter(T1 *array, T2 len, T3 (*f)(T1 elem)){
    for(int i=0;i<len;i++){
        f(array[i]);
    }
}


#endif