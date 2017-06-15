#pragma once
#include "Item.h"
class LRoundItem :
    public Item
{
protected:
    virtual int Execute();
public:
    static long lround_pdfl(double x) { return static_cast<long>(x + 0.5); }
};

