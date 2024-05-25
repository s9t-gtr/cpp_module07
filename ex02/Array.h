#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <exception>

template <typename T>
class Array{
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& other);

        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
    public:
        void outputElements() const;
        unsigned int size() const;
    private:
        void setValue(T& val1, T& val2);
        const unsigned int array_size;
        T *array;
};

/*==============================================
            Orthodox Canonical Form
==============================================*/
template <typename T>
Array<T>::Array(){
    std::cout << "Array: Default constructor called" << std::endl;
    array = new T();
}

template <typename T>
Array<T>::Array(unsigned int n): array_size(n){
    std::cout << "Array: argument n constructor called" << std::endl;
    array = new T[n]();
    //std::cout << *array << std::endl;
}

template <typename T>
Array<T>::~Array(){
    std::cout << "Array: Destructor called" << std::endl;
    delete [] array;
}

template <typename T>
Array<T>::Array(const Array<T>& other): array_size(other.size()), array(new T[other.size()]){
    std::cout << "Array: copy constructor called" << std::endl;
    if(this != &other){
        *this = other;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
    if(this != &other){
        try{
            T *p = new T[other.size()](); 
            for(unsigned int i = 0; i < other.size(); i++){
                p[i] = other.array[i];
            }
            const_cast<unsigned int&>(array_size) = other.size();
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
T& Array<T>::operator[](unsigned int index){
    if(array_size <= index)
        throw std::out_of_range("Error: operator[] throw out_of_range");
    return array[index];
}       

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
    if(array_size <= index)
        throw std::out_of_range("Error: operator[] throw out_of_range");
    return array[index];
}       

/*==============================================
            member functions
==============================================*/
template <typename T>
unsigned int Array<T>::size() const{
    return array_size;
}

/*==============================================
            utils function
==============================================*/
template <typename T>
void Array<T>::outputElements() const{
    for(size_t i = 0; i < array_size; i++)
        std::cout << array[i] << " "; 
    std::cout << std::endl;
}


#endif
