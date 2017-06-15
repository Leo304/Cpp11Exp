#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

#pragma once
class Menu
{
private:
	string Title;
	vector<string> lines;
	vector<Item*> items;
	int QuitID;
	void Show(const bool AClear = true);
	int Check(const unsigned AId) {
		return ((AId >= 1) && (AId <= this->lines.size()) ? AId : -1);
	}
	int Select(const bool AClear = true);
	int Execute(const int AId);
	int getQuitID();
	void setQuitID(const int AId);
	void setTitle(const string ATitle) { this->Title = ATitle; }
public:
	Menu( const string ATitle ) {
		this->Title = ATitle;
		this->lines.clear();
		this->items.clear();
		this->QuitID = -1;
	}
	int AddLine(const string ALine, Item* AItem, const bool AQuit = false);
	int Popup();
	~Menu();
};

