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
        
        std::vector<std::pair<int, int> > _vectorPairs;     
        std::vector<int> _vectorMainChain;
        std::vector<int> _vectorPendChain;                 
    
        std::deque<std::pair<int, int> > _dequePairs;    
        std::deque<int> _dequeMainChain;        
        std::deque<int> _dequePendChain;            
        
        void mergeInsertSortVector(std::vector<int> &data);
        void createPairsVector(std::vector<int> &data, int &straggler, bool &hasStraggler);
        void sortPairsVector();
        void recursiveSortVector();
        void buildChainsVector();
        void insertPendVector(int straggler, bool hasStraggler);
        void binaryInsertVector(std::vector<int> &main, int value, size_t maxPos);

        void mergeInsertSortDeque(std::deque<int> &data);
        void createPairsDeque(std::deque<int> &data, int &straggler, bool &hasStraggler);
        void sortPairsDeque();
        void recursiveSortDeque();
        void buildChainsDeque();
        void insertPendDeque(int straggler, bool hasStraggler);
        void binaryInsertDeque(std::deque<int> &main, int value, size_t maxPos);
        
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
    
        std::vector<size_t> generateJacobsthalSequence(size_t n);
        std::vector<size_t> generateInsertionOrder(size_t pendSize);
        void sort();
        void displayResults(const std::vector<int> &original);
        const std::vector<int>& getVectorData() const;
        const std::deque<int>& getDequeData() const;
        bool isValidNumber(const std::string &str);
        void validateInput(int argc, char **argv);
};

#endif
