#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fraction
{
	int n;
	int d;
	const Fraction AddAux(const Fraction &, const char);
public:
	Fraction(){ n = 0; d = 1; }
	Fraction(int n, int d){ this->n = n; this->d = d; };
	Fraction(const Fraction &f){ n = f.n; d = f.d; }
	int getN() { return n; }
	int getD() { return d; }
	void setN(const int n){ this->n = n; }
	void setD(const int d){ this->d = d;  }
	string toString();
	const Fraction & operator= (const Fraction &);
	const Fraction operator+ (const Fraction &);
	const Fraction operator- (const Fraction &);
	const Fraction operator* (const Fraction &);
	const Fraction operator/ (const Fraction &);
	const Fraction & Simplify();
	virtual ~Fraction(){ cout << "Destructor: " << this->toString() << endl; }
	static void swapInt(int &, int &);
	static int GCD(int, int);
	static int LCM(int, int);
};

