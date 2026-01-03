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
#include <sys/time.h>


class PmergeMe
{
    private:
        std::vector<int> _vectorData;
        std::deque<int> _dequeData;
            
        void createPairsVector(std::vector<int> &data, std::vector<std::pair<int, int> > &pairs, int &straggler, bool &hasStraggler);
        void sortPairsVector(std::vector<std::pair<int, int> > &pairs);
        void recursiveSortVector(std::vector<std::pair<int, int> > &pairs);
        void buildChainsVector(const std::vector<std::pair<int, int> > &pairs, std::vector<int> &mainChain, std::vector<int> &pendChain);
        void insertPendVector(std::vector<int> &mainChain, const std::vector<int> &pendChain, int straggler, bool hasStraggler);
        void binaryInsertVector(std::vector<int> &main, int value, size_t maxPos);

        void createPairsDeque(std::deque<int> &data, std::deque<std::pair<int, int> > &pairs, int &straggler, bool &hasStraggler);
        void sortPairsDeque(std::deque<std::pair<int, int> > &pairs);
        void recursiveSortDeque(std::deque<std::pair<int, int> > &pairs);
        void buildChainsDeque(const std::deque<std::pair<int, int> > &pairs, std::deque<int> &mainChain, std::deque<int> &pendChain);
        void insertPendDeque(std::deque<int> &mainChain, const std::deque<int> &pendChain, int straggler, bool hasStraggler);
        void binaryInsertDeque(std::deque<int> &main, int value, size_t maxPos);
        
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
    
        std::vector<size_t> generateJacobsthalSequence(size_t n);
        std::vector<size_t> generateInsertionOrder(size_t pendSize);
        void mergeInsertSortVector(std::vector<int> &data);
        void mergeInsertSortDeque(std::deque<int> &data);
        void sort();
        void displayResults(const std::vector<int> &original);
        const std::vector<int>& getVectorData() const;
        const std::deque<int>& getDequeData() const;
        bool isValidNumber(const std::string &str);
        void validateInput(int argc, char **argv);
};

#endif
