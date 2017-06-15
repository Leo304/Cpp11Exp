#include <iostream>
#include "ReferenceItem.h"
using namespace std;

template <typename T>
int f(T& value)
{
	cout << "f) value=" << value << endl;
	return 0;
}

template <typename T>
int g(T&& value)
{
	cout << "g) value=" << value << endl;
	return 0;
}

template <typename T>
int h(T value)
{
	cout << "h) value=" << value << endl;
	return 0;
}

int ReferenceItem::Execute() {
	int x = 27;
	const int cx = x;
	const int& rx = x;
	f(x);
	f(cx);
	f(rx);
	//f(27);
	g(x);
	g(cx);
	g(rx);
	g(27);
	h(x);
	h(cx);
	h(rx);
	h(27);
#ifndef _AIX
	system("pause");
#endif
	return 0;
}



