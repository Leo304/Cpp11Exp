#include <iostream>
#include "Menu.h"
#include "ArrayItem.h"
#include "ReferenceItem.h"
#include "XMLItem.h"
#include "FractionItem.h"
#include "LRoundItem.h"
//#include "APDFLItem.h"

using namespace std;

int main(void)
{
	Menu lMainMenu( "Main Menu" );
	lMainMenu.AddLine("Array", new ArrayItem() );
	lMainMenu.AddLine("References", new ReferenceItem() );
    lMainMenu.AddLine("APDFL", nullptr /*new APDFLItem()*/);
	lMainMenu.AddLine("XML", new XMLItem());
	lMainMenu.AddLine("Fraction calculator", new FractionItem());
    lMainMenu.AddLine("Investigation lround", new LRoundItem());
	lMainMenu.AddLine("Quit", nullptr, true);
	int res = lMainMenu.Popup();
#if defined(_WIN32) || defined(_WIN64)
	std::system("pause");
#endif	
	return 0;
}