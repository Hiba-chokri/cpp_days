#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sys/time.h>  // For gettimeofday

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

double getTimeInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Error: No input provided" << std::endl;
            std::cerr << "Usage: ./PmergeMe [positive integers...]" << std::endl;
            return 1;
        }

        // Create and validate
        PmergeMe sorter;
        sorter.validateInput(argc, argv);

        // Get original data
        std::vector<int> original = sorter.getVectorData();

        // Display "Before"
        displayVector(original, "Before: ");

        // Time vector sort only
        std::vector<int> vectorCopy = sorter.getVectorData();
        double start_vector = getTimeInMicroseconds();
        sorter.mergeInsertSortVector(vectorCopy);
        double end_vector = getTimeInMicroseconds();
        double time_vector = end_vector - start_vector;

        // Display "After" using the sorted vector
        displayVector(vectorCopy, "After:  ");

        // Time deque sort only
        std::deque<int> dequeCopy = sorter.getDequeData();
        double start_deque = getTimeInMicroseconds();
        sorter.mergeInsertSortDeque(dequeCopy);
        double end_deque = getTimeInMicroseconds();
        double time_deque = end_deque - start_deque;

        // Display timing for both containers
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << original.size() 
                  << " elements with std::vector : " 
                  << time_vector << " us" << std::endl;
        std::cout << "Time to process a range of " << original.size() 
                  << " elements with std::deque  : " 
                  << time_deque << " us" << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}