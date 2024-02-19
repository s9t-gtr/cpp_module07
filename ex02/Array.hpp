#ifndef __ARRAY_HPP_
# define __ARRAY_HPP_

#include <iostream>

template <typename T>
class Array{
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& other);

        Array& operator=(const Array& other);
        T& operator[](int index);
    public:
        int size() const;
    private:
        T *array;
};

/*==============================================
            Orthodox Canonical Form
==============================================*/
template <typename T>
Array<T>::Array(){
    std::cout << "Array: Default constructor called" << std::endl;
    array = new T[1];
}

template <typename T>
Array<T>::Array(unsigned int n){
    std::cout << "Array: argument n constructor called" << std::endl;
    array = new T[n];
}

template <typename T>
Array<T>::~Array(){
    std::cout << "Array: Destructor called" << std::endl;
    delete [] array;
}

template <typename T>
Array<T>::Array(const Array& other): array(NULL){
    std::cout << "Array: copy constructor called" << std::endl;
    if(this != &other){
        *this = other;
    }
}

template <typename T>
size_t sizeOther(T *array);

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
    if(this != &other){
        try{
            T *p = new T[sizeOther(other.array)];
            if(array != NULL)
                delete [] array;
            array = p;
        }catch(std::bad_alloc&){
            std::cerr << "Error: new failed" << std::endl;
        }                       
    }
    return *this;
}

/*==============================================
            subject instructions
==============================================*/
template <typename T>
T& Array<T>::operator[](int index){
    if(index < 0 || size() < index - 1)
        throw std::exception();
    return array[index];
}       

/*==============================================
            member functions
==============================================*/
template <typename T>
int Array<T>::size() const{
    size_t i = 0;
    while(array[i])
        i++;
    return i;
}

/*==============================================
            utils function
==============================================*/
template <typename T>
size_t sizeOther(T *array){
    size_t i = 0;
    while(array[i])
        i++;
    return i;
}

#endif