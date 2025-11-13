#include "Array.hpp"
#include <iostream>

int main()
{
    int* a = new int();
    std::cout << *a;

    try {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); ++i)
            arr[i] = i * 10;

        std::cout << "Original array: ";
        for (unsigned int i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        Array<int> copy = arr; // deep copy
        copy[0] = 999;         // modify copy only

        std::cout << "Modified copy: ";
        for (unsigned int i = 0; i < copy.size(); ++i)
            std::cout << copy[i] << " ";
        std::cout << "\n";

        std::cout << "Original still intact: ";
        for (unsigned int i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "Trying invalid index...\n";
        std::cout << arr[10]; // should throw exception
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;

}