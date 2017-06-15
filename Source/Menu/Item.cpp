#include <iostream>
#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

void Item::pause()
{
	std::cout << "Paused, press ENTER to continue." << std::endl;
	std::cin.get();	
}
