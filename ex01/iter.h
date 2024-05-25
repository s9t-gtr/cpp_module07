#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T>
void func(T elem){
   std::cout << elem << std::endl; 
}

template <typename T, typename F>
void iter(T *array, size_t len, F func){
    for(int i=0;i<len;i++){
        func(array[i]);
    }
}




#endif