#include "Menu.h"
using namespace std;

Menu::~Menu() {
	Item* pit; 
	for ( size_t i = 0; i < this->items.size(); i++ )
	{
		pit = this->items[i];
		if( pit != nullptr) delete pit;
	}		
/* 	for each (pit in this->items)
	{
		if( pit != nullptr) delete pit;
	}*/
};

int Menu::AddLine(const string ALine, Item* AItem, const bool AQuit) {
	this->lines.push_back(ALine);
	this->items.push_back(AItem);
	if (AQuit) this->QuitID = this->lines.size();
	return this->lines.size();
};

int Menu::Popup() {
	int i, res;
	while (true) {
		i = this->Select(true);
		if (i == this->getQuitID()) break;
		if (i == -1) continue;
		res = this->Execute(i);
	}
	return 0;
}
void Menu::Show(const bool AClear) {
	if (AClear) std::system("cls");
	cout << "============================" << endl;
	cout << ' ' << this->Title << endl;
	cout << "============================" << endl;
	string lStr;
	int i = 0;
	for ( size_t j = 0; j < this->lines.size(); j++ )
	{
		cout << i + 1 << ". " << this->lines[ j ] << endl;
		i++;
	}
 	// for each (lStr in this->lines)
	// {
		// cout << i + 1 << ". " << lStr << endl;
		// i++;
	// }
 
};

int Menu::Select(const bool AClear) {
	this->Show(AClear);
	int retval;
	cout << "Enter you choice:";
	cin >> retval;
	retval = this->Check(retval);
	return retval; }

int Menu::Execute(const int AId){
	Item* pit = this->items[AId - 1];
	int res;
	if (pit != nullptr)
		res = pit->operator()();
	else
		res = -1;
	return res;
}

int Menu::getQuitID() { return this->QuitID; }
void Menu::setQuitID(const int AId) { this->QuitID = AId;  }
