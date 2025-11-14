#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>


template <typename T> 
class Array
{
    private:
        T* arr;
        unsigned int _size;
    public:
        Array() : arr(NULL), _size(0)
        {
            std::cout<<"array cdefault constructor"<<std::endl;
        }
        Array(unsigned int n) : arr(new T[n]), _size(n){}
        Array(const Array& other)
        {
            _size = other._size;
            arr = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                arr[i] = other.arr[i];
        }
        Array& operator=(const Array& other){
            if (this != &other)
            {
                delete[] arr;
                _size = other._size;
                arr = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
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
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return arr[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

    unsigned int size() const {
        return _size;
    }
};


#endif