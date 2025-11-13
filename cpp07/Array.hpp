#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>


template <typename T> 
class Array
{
    private:
        T* arr;
        unsigned int size;
    public:
        Array() : arr(NULL), size(0)
        {
            std::cout<<"array cdefault constructor"<<std::endl;
        }
        Array(unsigned int n) : arr(new T[n]), size(n)
        Array(const Array& other)
        {
            size = other.size;
            arr = new T[size];
            for (unsigned int i = 0; i < size; ++i)
                arr[i] = other.arr[i];
        }
        Array& operator=(const Array& other){
            if (this != &other)
            {
                delete[] arr;
                size = other.size;
                arr = new T[size];
                for (unsigned int i = 0; i < size; ++i)
                arr[i] = other.arr[i];

            }
            return *this;
        }
        ~Array()
        {
            std::cout << "destructor called"<<std::endl;
            delete[] arr;
        }
        T& operator[](unsigned int index) {
            if (index >= size)
                throw std::out_of_range("Index out of range");
            return arr[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

    unsigned int size() const {
        return size;
    }
};


#endif