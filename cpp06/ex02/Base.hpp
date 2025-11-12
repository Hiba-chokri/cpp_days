#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <stdint.h>
#include <cstdlib>

class Base
{
    public:
    virtual ~Base();

};

void identify(Base* p);
Base * generate(void);
void identify(Base& p);

#endif 