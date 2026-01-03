#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
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

const std::vector<int>& PmergeMe::getVectorData() const
{
    return _vectorData;
}

const std::deque<int>& PmergeMe::getDequeData() const
{
    return _dequeData;
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

void PmergeMe::createPairsVector(std::vector<int> &data, std::vector<std::pair<int, int> > &pairs, int &straggler, bool &hasStraggler)
{
    pairs.clear();
    hasStraggler = false;

    size_t i = 0;
    size_t size = data.size();

    while (i + 1 < size)
    {
        pairs.push_back(
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

void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
        {
            std::swap(
                pairs[i].first,
                pairs[i].second
            );
        }
    }
}

void PmergeMe::recursiveSortVector(std::vector<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].first);
    }
    mergeInsertSortVector(largerElements);
    std::vector<std::pair<int, int> > reorderedPairs;
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == largerElements[i])
            {
                reorderedPairs.push_back(pairs[j]);
                pairs[j].first = -1;
                break;
            }
        }
    }
    pairs = reorderedPairs;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &data)
{
    if (data.size() <= 1)
        return;

    int straggler = -1;
    bool hasStraggler = false;
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> mainChain;
    std::vector<int> pendChain;

    createPairsVector(data, pairs, straggler, hasStraggler);
    sortPairsVector(pairs);
    recursiveSortVector(pairs);
    buildChainsVector(pairs, mainChain, pendChain);
    insertPendVector(mainChain, pendChain, straggler, hasStraggler);
    data = mainChain;
}

void PmergeMe::buildChainsVector(const std::vector<std::pair<int, int> > &pairs, std::vector<int> &mainChain, std::vector<int> &pendChain)
{
    mainChain.clear();
    pendChain.clear();

    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        pendChain.push_back(pairs[i].second);
}

void PmergeMe::insertPendVector(std::vector<int> &mainChain, const std::vector<int> &pendChain, int straggler, bool hasStraggler)
{
    if (pendChain.empty())
    {
        if (hasStraggler)
        {
            binaryInsertVector(mainChain, straggler, mainChain.size());
        }
        return;
    }
    
    int firstPend = pendChain[0];
    mainChain.insert(mainChain.begin(), firstPend);
    
    if (pendChain.size() > 1)
    {
        std::vector<size_t> insertionOrder = generateInsertionOrder(pendChain.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); ++i)
        {
            size_t pendIndex = insertionOrder[i] + 1;
            if (pendIndex < pendChain.size())
            {
                int valueToInsert = pendChain[pendIndex];
                binaryInsertVector(mainChain, valueToInsert, mainChain.size());
            }
        }
    }
    if (hasStraggler)
        binaryInsertVector(mainChain, straggler, mainChain.size());
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
    size_t previousJacob = 0;

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
    
    // Insert any remaining indices not covered by Jacobsthal
    for (size_t i = previousJacob; i < pendSize; ++i)
        result.push_back(i);
    
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
    for (size_t i = 1; i < jacobsthal.size(); ++i)
        result.push_back(jacobsthal[i]);
    return result;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &data)
{
    if (data.size() <= 1)
        return;

    int straggler = -1;
    bool hasStraggler = false;
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> mainChain;
    std::deque<int> pendChain;

    createPairsDeque(data, pairs, straggler, hasStraggler);
    sortPairsDeque(pairs);
    recursiveSortDeque(pairs);
    buildChainsDeque(pairs, mainChain, pendChain);
    insertPendDeque(mainChain, pendChain, straggler, hasStraggler);
    data = mainChain;
}

void PmergeMe::createPairsDeque(std::deque<int> &data, std::deque<std::pair<int, int> > &pairs, int &straggler, bool &hasStraggler)
{
    pairs.clear();
    hasStraggler = false;

    size_t i = 0;
    size_t size = data.size();

    while (i + 1 < size)
    {
        pairs.push_back(
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

void PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
        {
            std::swap(
                pairs[i].first,
                pairs[i].second
            );
        }
    }
}

void PmergeMe::recursiveSortDeque(std::deque<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].first);
    }
    mergeInsertSortDeque(largerElements);
    std::deque<std::pair<int, int> > reorderedPairs;
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == largerElements[i])
            {
                reorderedPairs.push_back(pairs[j]);
                pairs[j].first = -1;
                break;
            }
        }
    }
    pairs = reorderedPairs;
}

void PmergeMe::buildChainsDeque(const std::deque<std::pair<int, int> > &pairs, std::deque<int> &mainChain, std::deque<int> &pendChain)
{
    mainChain.clear();
    pendChain.clear();

    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);
    for (size_t i = 0; i < pairs.size(); ++i)
        pendChain.push_back(pairs[i].second);
}

void PmergeMe::insertPendDeque(std::deque<int> &mainChain, const std::deque<int> &pendChain, int straggler, bool hasStraggler)
{
    if (pendChain.empty())
    {
        if (hasStraggler)
        {
            binaryInsertDeque(mainChain, straggler, mainChain.size());
        }
        return;
    }
    
    int firstPend = pendChain[0];
    mainChain.insert(mainChain.begin(), firstPend);
    
    if (pendChain.size() > 1)
    {
        std::vector<size_t> insertionOrder = generateInsertionOrder(pendChain.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); ++i)
        {
            size_t pendIndex = insertionOrder[i] + 1;
            if (pendIndex < pendChain.size())
            {
                int valueToInsert = pendChain[pendIndex];
                binaryInsertDeque(mainChain, valueToInsert, mainChain.size());
            }
        }
    }
    if (hasStraggler)
        binaryInsertDeque(mainChain, straggler, mainChain.size());
}

void PmergeMe::binaryInsertDeque(std::deque<int> &main, int value, size_t maxPos)
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

void PmergeMe::sort()
{
    // Sort using vector
    if (!_vectorData.empty())
    {
        std::vector<int> dataCopy = _vectorData;
        mergeInsertSortVector(dataCopy);
        _vectorData = dataCopy;
    }

    // Sort using deque
    if (!_dequeData.empty())
    {
        std::deque<int> dataCopy = _dequeData;
        mergeInsertSortDeque(dataCopy);
        _dequeData = dataCopy;
    }
}

void PmergeMe::displayResults(const std::vector<int> &original)
{
    // This can be used for more detailed output if needed
    (void)original; // Suppress unused parameter warning for now
}