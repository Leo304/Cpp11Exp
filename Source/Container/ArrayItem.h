#pragma once
#include <string>
#include "Item.h"

class ArrayItem: public Item
{
protected:
	virtual int Execute();
};

class NuNu
{
public:
    NuNu() :ID(0), name("N/A"){}
    NuNu(const int aID, const std::string aName) :ID(aID), name(aName){}
private:
    int ID;
    std::string name;
};



