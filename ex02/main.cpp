#include <iostream>
#include "Array.hpp"

#define EMPTY_LINE std::cout << std::endl;
static unsigned int ARRAY_SIZE = 5;

__attribute__((destructor))
static void destructor() {
    system("leaks -q ex02");
}

int main(int, char**)
{
    srand(time(NULL));
    Array<int> numbers(ARRAY_SIZE);
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
        numbers[i] = std::rand();
    EMPTY_LINE
    {// copy constructor and operator= test
        {
             std::cout << "---------------- base array ----------------" << std::endl; 
             numbers.outputElements();
             EMPTY_LINE

             std::cout << "---------------- assign init ----------------" << std::endl; 
             Array<int> assign = numbers;
             assign.outputElements();
             EMPTY_LINE

             std::cout << "---------------- copy init ----------------" << std::endl; 
             Array<int> copy(assign);
             copy.outputElements();
             EMPTY_LINE
             
             assign[assign.size() - 1] = 0;
             copy[copy.size() - 1] = 5;

             std::cout << "---------------- fixd assign array ----------------" << std::endl; 
             assign.outputElements();
             EMPTY_LINE
             std::cout << "---------------- fixd copy array ----------------" << std::endl; 
             copy.outputElements();
             EMPTY_LINE
             std::cout << "---------------- base array(not change) ----------------" << std::endl; 
             numbers.outputElements();
             EMPTY_LINE
        }
        {//different size assign test
            Array<int> big(ARRAY_SIZE + 5); 
            Array<int> small(1); 
            
            for (unsigned int i = 0; i < ARRAY_SIZE+5; i++)
            {
                big[i] = std::rand();
                small[0] = std::rand();
            }

            std::cout << "---------------- big array ----------------" << std::endl;
            big.outputElements();
            big = numbers;
            std::cout << "---------------- after assign ----------------" << std::endl;
            big.outputElements();
            EMPTY_LINE

            std::cout << "---------------- small array ----------------" << std::endl;
            small.outputElements();
            small = numbers;
            std::cout << "---------------- after assign ----------------" << std::endl;
            small.outputElements();
            EMPTY_LINE
        }
        
    }
    {//compare mirror
        int* mirror = new int[ARRAY_SIZE];

        for (unsigned int i = 0; i < ARRAY_SIZE; i++)
        {
            int value = std::rand();
            numbers[i] = value;
            mirror[i] = value;
        }

         for (unsigned int i = 0; i < ARRAY_SIZE; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        delete [] mirror;
    }

    EMPTY_LINE
    {// out of range test
        std::cout << "---------------- out of range test ----------------" << std::endl;
        try{
            numbers[-2] = 0;
        }catch(const std::exception& e){
            std::cerr << e.what() << std::endl;;
        }
        try{
            numbers[ARRAY_SIZE] = 0;
        }catch(const std::exception& e){
            std::cerr << e.what() << std::endl;;
        }
    }
    EMPTY_LINE

    {//const instance
        std::cout << "---------------- const instance ----------------" << std::endl;
        {//samples
            std::cout << "  -------------- samples --------------  " << std::endl;
            int* ints = new int[ARRAY_SIZE]();
            for(unsigned int i = 0; i < ARRAY_SIZE; i++){
                ints[i] = i+5;
            }
            { //const array init test
                std::cout << "    ------------ const array init ------------    " << std::endl;
                const int* const_ints(ints);//success
                std::cout << "expect: " << std::endl;
                for(unsigned int i = 0; i < ARRAY_SIZE; i++){
                    std::cout << ints[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "actual: " << std::endl;
                for(unsigned int i = 0; i < ARRAY_SIZE; i++){
                    std::cout << const_ints[i] << " ";
                }
                std::cout << std::endl;
            }
            { //const array init by const array test
                std::cout << "    ------------ const array init by const array ------------    " << std::endl;
                const int* const_ints(ints);
                const int* const_ints2(const_ints);//success
                //or
                //const int* const_ints2 = const_ints;//success
                std::cout << "expect: " << std::endl;
                for(unsigned int i = 0; i < ARRAY_SIZE; i++){
                    std::cout << ints[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "actual: " << std::endl;
                for(unsigned int i = 0; i < ARRAY_SIZE; i++){
                    std::cout << const_ints2[i] << " ";
                }
                std::cout << std::endl;
            }
            {//const array element test
                //const int* const_ints(ints);
                //const int* const_ints2(const_ints);
                //const_ints[0] = const_ints2[5];//fail
                //const_ints[0] = ints[0];//fail
            }
            delete [] ints;
        }
        EMPTY_LINE
        {//Array<T> const instance
            std::cout << "  -------------- Array<T> --------------  " << std::endl;
            Array<int> nums(ARRAY_SIZE);
            const Array<int> const_numbers(ARRAY_SIZE);
            for(unsigned int i=0;i<nums.size();i++)
                nums[i] = i*5;
            {
                std::cout << "    ------------ const array init ------------    " << std::endl;
                const Array<int> const_numbers = nums;//success
                //or
                //const Array<int> const_numbers(nums);//success
                std::cout << "expect: " << std::endl;
                const_numbers.outputElements();
                std::cout << "actual: " << std::endl;
                const_numbers.outputElements();
            }
            {
                std::cout << "    ------------ const array init by const array ------------    " << std::endl;
                const Array<int> const_numbers(nums);

                //const Array<int> const_numbers2(const_numbers);
                //or
                const Array<int> const_numbers2 = const_numbers;
                std::cout << "expect: " << std::endl;
                const_numbers.outputElements();
                std::cout << "actual: " << std::endl;
                const_numbers2.outputElements();
            }
            {
                //const Array<int> const_numbers(nums);
                //const_numbers[0] = 0;//fail
                //const_numbers[0] = numbers[0];//fail  
            }

            EMPTY_LINE
        }
        
    }

    return 0;
}
