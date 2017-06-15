#pragma once
#include "Item.h"
class XMLItem : public Item
{
public:
	XMLItem();
	virtual ~XMLItem();
	virtual int Execute();
};

