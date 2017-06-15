#include "XMLItem.h"
#include "SimpleXML.h"
#include "SF39732Xml.h"
#include "Menu.h"


XMLItem::XMLItem()
{
}


XMLItem::~XMLItem()
{
}

int XMLItem::Execute()
{
	Menu lPopupMenu("XML Menu");
	lPopupMenu.AddLine("Simple XML", new SimpleXML() );
	lPopupMenu.AddLine("PDFA conformance verification", new SF39732Xml() );
	lPopupMenu.AddLine("TBD...", nullptr);
	lPopupMenu.AddLine("Quit", nullptr, true);
	int res = lPopupMenu.Popup();
#if defined(_WIN32) || defined(_WIN64)
	std::system("pause");
#endif	
	return 0;
}

