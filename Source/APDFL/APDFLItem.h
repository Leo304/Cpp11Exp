#pragma once
#include <string>
#include "Item.h"

class APDFLItem: public Item
{
public:
    APDFLItem();
    virtual ~APDFLItem();
    virtual int Execute();
};

