#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

void displayVector(const std::vector<int> &vec, const std::string &label)
{
    std::cout << label;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    try
    {
        // Check if we have arguments
        if (argc < 2)
        {
            std::cerr << "Error: No input provided" << std::endl;
            std::cerr << "Usage: ./PmergeMe [positive integers...]" << std::endl;
            return 1;
        }

        // Create PmergeMe object and validate input
        PmergeMe sorter;
        sorter.validateInput(argc, argv);

        // Get the original data (before sorting)
        std::vector<int> original = sorter.getVectorData();

        // Display "Before"
        displayVector(original, "Before: ");

        // Sort the data
        sorter.sort();

        // Display "After"
        displayVector(sorter.getVectorData(), "After:  ");

        // Display timing results (TODO: implement timing in sort())
        // std::cout << std::fixed << std::setprecision(5);
        // std::cout << "Time to process a range of " << original.size() 
        //           << " elements with std::vector : " 
        //           << sorter.getVectorTime() << " us" << std::endl;
        // std::cout << "Time to process a range of " << original.size() 
        //           << " elements with std::deque : " 
        //           << sorter.getDequeTime() << " us" << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}