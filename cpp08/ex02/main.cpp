#include "MutantStack.hpp"

int main()
{
    std::cout << "----- BASIC TESTS -----" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n----- ITERATOR TESTS -----" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Forward iteration:" << std::endl;
    for (; it != ite; ++it)
        std::cout << *it << std::endl;

    std::cout << "\nReverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << std::endl;
    }

    std::cout << "\n----- CONST ITERATOR TEST -----" << std::endl;

    const MutantStack<int> constStack = mstack;

    for (MutantStack<int>::const_iterator cit = constStack.begin();
         cit != constStack.end(); ++cit)
    {
        std::cout << *cit << std::endl;
    }

    std::cout << "\n----- COPY & ASSIGNMENT TESTS -----" << std::endl;

    MutantStack<int> copyStack(mstack);   // copy constructor
    MutantStack<int> assignedStack;       // empty
    assignedStack = mstack;               // assignment operator

    std::cout << "Copy stack size: " << copyStack.size() << std::endl;
    std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;

    std::cout << "Contents of assigned stack:" << std::endl;
    for (MutantStack<int>::iterator it2 = assignedStack.begin();
         it2 != assignedStack.end(); ++it2)
    {
        std::cout << *it2 << std::endl;
    }

    std::cout << "\n----- STD::STACK COMPATIBILITY TEST -----" << std::endl;

    std::stack<int> normalStack(mstack);   // stack from mutantstack

    std::cout << "Top of normal std::stack: " << normalStack.top() << std::endl;

    return 0;
}