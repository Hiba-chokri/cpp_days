#ifndef HARL_H
#define HARL_H

#include <iostream.h>
#include <string.h>

class Harl {
    private :
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        void complain( std::string level );
}