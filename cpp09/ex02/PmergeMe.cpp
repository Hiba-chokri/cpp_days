#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        
    }
    return *this;
}

bool PmergeMe::isValidNumber(const std::string &str) {
    if (str.empty()) 
        return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::validateInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::invalid_argument("Invalid number: " + arg);
        int num;
        std::stringstream ss(arg);
        ss >> num;
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
}

void PmergeMe::createPairsVector(std::vector<int> &data, int &straggler, bool &hasStraggler)
{
    _vectorPairs.clear();
    hasStraggler = false;

    size_t i = 0;
    size_t size = data.size();

    while (i + 1 < size)
    {
        _vectorPairs.push_back(
            std::make_pair(data[i], data[i + 1])
        );
        i += 2;
    }

    if (i < size)
    {
        straggler = data[i];
        hasStraggler = true;
    }
}

void PmergeMe::sortPairsVector()
{
    for (size_t i = 0; i < _vectorPairs.size(); ++i)
    {
        if (_vectorPairs[i].first < _vectorPairs[i].second)
        {
            std::swap(
                _vectorPairs[i].first,
                _vectorPairs[i].second
            );
        }
    }
}

void PmergeMe::recursiveSortVector()
{
    if (_vectorPairs.size() <= 1)
        return;
    std::vector<int> largerElements;
    for (size_t i = 0; i < _vectorPairs.size(); ++i)
    {
        largerElements.push_back(_vectorPairs[i].first);
    }
    mergeInsertSortVector(largerElements);
    std::vector<std::pair<int, int> > reorderedPairs;
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < _vectorPairs.size(); ++j)
        {
            if (_vectorPairs[j].first == largerElements[i])
            {
                reorderedPairs.push_back(_vectorPairs[j]);
                _vectorPairs[j].first = -1;
                break;
            }
        }
    }
    _vectorPairs = reorderedPairs;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &data)
{
    if (data.size() <= 1)
        return;

    int straggler = -1;
    bool hasStraggler = false;

    createPairsVector(data, straggler, hasStraggler);
    sortPairsVector();
    recursiveSortVector();
    buildChainsVector();
    insertPendVector(straggler, hasStraggler);
    data = _vectorMainChain;
}

void PmergeMe::buildChainsVector()
{
    _vectorMainChain.clear();
    _vectorPendChain.clear();

    for (size_t i = 0; i < _vectorPairs.size(); ++i)
        _vectorMainChain.push_back(_vectorPairs[i].first);
    for (size_t i = 0; i < _vectorPairs.size(); ++i)
        _vectorPendChain.push_back(_vectorPairs[i].second);
}

void PmergeMe::insertPendVector(int straggler, bool hasStraggler)
{
    if (_vectorPendChain.empty())
    {
        if (hasStraggler)
        {
            binaryInsertVector(_vectorMainChain, straggler, _vectorMainChain.size());
        }
        return;
    }
    int firstPend = _vectorPendChain[0];

    _vectorMainChain.insert(_vectorMainChain.begin(), firstPend);
    if (_vectorPendChain.size() > 1)
    {
        std::vector<size_t> insertionOrder = generateInsertionOrder(_vectorPendChain.size() - 1);
        for (size_t i = 0; i < insertionOrder.size(); ++i)
        {
            size_t pendIndex = insertionOrder[i] + 1;
            if (pendIndex < _vectorPendChain.size())
            {
                int valueToInsert = _vectorPendChain[pendIndex];
                size_t pairedMainPos = pendIndex + 1;
                size_t searchLimit = pairedMainPos < _vectorMainChain.size() 
                                      ? pairedMainPos 
                                      : _vectorMainChain.size();
                
                binaryInsertVector(_vectorMainChain, valueToInsert, searchLimit);
            }
        }
    }
    if (hasStraggler)
        binaryInsertVector(_vectorMainChain, straggler, _vectorMainChain.size());
}

void PmergeMe::binaryInsertVector(std::vector<int> &main, int value, size_t maxPos)
{
    if (maxPos > main.size())
        maxPos = main.size();

    size_t left = 0;
    size_t right = maxPos;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (main[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    main.insert(main.begin() + left, value);
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendSize)
{
    std::vector<size_t> result;
    
    if (pendSize == 0)
        return result;
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendSize);
    size_t previousJacob = 1;

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        size_t currentJacob = jacobsthal[i];
        if (currentJacob > pendSize)
            currentJacob = pendSize;
        for (size_t j = currentJacob; j > previousJacob; --j)
            result.push_back(j - 1);
        previousJacob = currentJacob;
        if (currentJacob >= pendSize)
            break;
    }
    return result;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    
    if (n == 0)
        return jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    size_t index = 2;
    while (true)
    {
        size_t next = jacobsthal[index - 1] + 2 * jacobsthal[index - 2];
        if (next > n)
            break;
        jacobsthal.push_back(next);
        ++index;
    }
    std::vector<size_t> result;
    for (size_t i = 2; i < jacobsthal.size(); ++i)
        result.push_back(jacobsthal[i]);
    return result;
}

void PmergeMe::sort()
{
    // Sort using vector
    if (!_vectorData.empty())
    {
        std::vector<int> dataCopy = _vectorData;
        mergeInsertSortVector(dataCopy);
        _vectorData = dataCopy;
    }

    // Sort using deque (TODO: implement deque version)
    // if (!_dequeData.empty())
    // {
    //     std::deque<int> dataCopy = _dequeData;
    //     mergeInsertSortDeque(dataCopy);
    //     _dequeData = dataCopy;
    // }
}

void PmergeMe::displayResults(const std::vector<int> &original)
{
    // This can be used for more detailed output if needed
    (void)original; // Suppress unused parameter warning for now
}