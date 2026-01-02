#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdexcept>

class PmergeMe
{
    private:
        std::vector<int> _vectorData;
        std::deque<int> _dequeData;
        double _vectorTime;
        double _dequeTime;
        
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        
        void mergeInsertSortVector(std::vector<int> &data);
        std::vector<int> createPairsVector(std::vector<int> &data, std::vector<int> &pend, int &straggler);
        std::vector<size_t> generateJacobsthalSequence(size_t n);
        void binaryInsertVector(std::vector<int> &main, int value, size_t endPos);
        void mergeInsertSortDeque(std::deque<int> &data);
        std::deque<int> createPairsDeque(std::deque<int> &data, std::deque<int> &pend, int &straggler);
        void binaryInsertDeque(std::deque<int> &main, int value, size_t endPos);
        bool isValidNumber(const std::string &str);
        void validateInput(int argc, char **argv);
        // Main methods
        void sort();
        void displayResults(const std::vector<int> &original);
        
        // Getters
        const std::vector<int>& getVectorData() const;
        const std::deque<int>& getDequeData() const;
        double getVectorTime() const;
        double getDequeTime() const;
};

#endif
