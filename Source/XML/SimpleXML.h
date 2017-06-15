#pragma once
#include "Item.h"
class SimpleXML :
	public Item
{
public:
	SimpleXML();
	virtual ~SimpleXML();
	virtual int Execute();
};

