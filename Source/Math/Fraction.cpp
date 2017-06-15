#include <string>
#include <sstream>
using namespace std;
#include "Fraction.h"

const Fraction & Fraction::Simplify(){
	int p = this->n, q = this->d;
	if (q < p) swapInt(q, p);
	int  gcd = GCD(q, p);
	if (gcd > 1)
	{
		this->n /= gcd;
		this->d /= gcd;
	}
	return *this;
}

string Fraction::toString(){ 
	stringstream s;
	s << this->n << '/' << this->d;
	return s.str();
}

const Fraction & Fraction::operator= (const Fraction &f){
	this->n = f.n;
	this->d = f.d;
	return *this;
}

const Fraction Fraction::AddAux(const Fraction &f, const char op){
	Fraction a(*this), b(f), retVal;
	a.Simplify();
	b.Simplify();
	int lcm = LCM(a.d, b.d);
	if (op == '+')
		retVal.n = (a.n * (lcm / a.d) + b.n * (lcm / b.d));
	else
		retVal.n = (a.n * (lcm / a.d) - b.n * (lcm / b.d));
	retVal.d = lcm;
	return retVal.Simplify();
}

const Fraction Fraction::operator+ (const Fraction &f){
	return this->AddAux(f, '+');
}
const Fraction Fraction::operator- (const Fraction &f){
	return this->AddAux(f, '-');
}
const Fraction Fraction::operator* (const Fraction &f){
	Fraction retval(this->n * f.n, this->d * f.d);
	return retval.Simplify();
}
const Fraction Fraction::operator/ (const Fraction &f){
	Fraction retval(this->n * f.d, this->d * f.n);
	return retval.Simplify();
}

void Fraction::swapInt(int &a, int &b)
{
	int r = a;
	a = b;
	b = r;
}

int Fraction::GCD(int x, int y){
	if (y == 0)  // base case, the programs stops if y reaches 0.
		return x;     //it returns the GCD
	else
		return GCD(y, x%y); //if y doesn't reach 0 then recursion continues
}
int Fraction::LCM(int x, int y){
	if (y < x) 
		Fraction::swapInt(x, y);
	return (x*y) / GCD(x, y);
}
