#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include "easyfind.hpp"

int main()
{
   // VECTOR TEST
     std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::cout << "Testing vector:" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // LIST TEST 
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    std::cout << "\nTesting list:" << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found: " << *it << std::endl;
        
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // //  DEQUE TEST
    std::deque<int> dq;
    dq.push_back(4);
    dq.push_back(8);
    dq.push_back(12);

    std::cout << "\nTesting deque:" << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(dq, 8);
        std::cout << "Found: " << *it << std::endl;    // should print "8 found"
   
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        std::deque<int>::iterator it = easyfind(dq, 99); 
        std::cout << "Found: " << *it << std::endl; // should throw
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
