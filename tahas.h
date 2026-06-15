#ifndef tahas_h
#define tahas_h

#include "Hero.h"

class tahas : public hero
{
    private:

        hero *hot_target;

    public:

        tahas() : hero("taha koochike", "healer", 500, 3, "hame dar jaye khod in mantaghe aloode ast !") , hot_target(nullptr) { }
};

#endif