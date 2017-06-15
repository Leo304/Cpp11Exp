#pragma once
#include "Item.h"
class FractionItem: public Item
{
protected:
	virtual int Execute(); 
public:
	FractionItem();
	virtual ~FractionItem();
};

