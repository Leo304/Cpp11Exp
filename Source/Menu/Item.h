#pragma once
#include <string>

class Item
{
protected:
	virtual int Execute() = 0;
	void pause();
public:
	Item();
	int operator()() { return Execute(); }
	virtual ~Item();
};

typedef Item* pItem;


