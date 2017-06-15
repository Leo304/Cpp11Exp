#include "FractionItem.h"
#include "Fraction.h"
#include "Menu.h"

#include <iostream>
using namespace std;

FractionItem::FractionItem()
{
}


FractionItem::~FractionItem()
{
}

int FractionItem::Execute() {
	cout << "Fraction calculator" << endl << "-------------------------" << endl << endl;
	cout << "Enter nominator and denominator of the first fraction:";
	int d, n;
	cin >> n >> d;
	Fraction a(n, d);
	cout << "Enter nominator and denominator of the second fraction:";
	cin >> n >> d;
	Fraction b(n, d);
	cout << "Enter a sign of operation[+,-,* or /]: ";
	char op;
	cin >> op;
	Fraction c;
	bool done = true;
	switch (op){
		case '+': 
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
		case '*':
			c = a * b;
			break;
		case '/':
			c = a / b;
			break;
		default:
			cout << "Unknown operation " << op << endl;
			done = false;
			break;
	}
	if (done)
		cout << "Result: " << a.toString() << op << b.toString() << '=' << c.toString() << endl;
#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#endif	
	return 0;
}


