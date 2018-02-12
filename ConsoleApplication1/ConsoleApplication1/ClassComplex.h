#pragma once
#include <math.h>
#include <conio.h>
#include <iostream>
#include <complex>
using namespace std;
template <class T>
class NoComplex
{
private:
	T real;
	T im;
public:
	NoComplex(T r = 0, T i = 0)
	{
		real = r;
		im = i;
	}
	NoComplex(NoComplex& right)
	{
		real = right.real;
		im = right.im;
	}
	~NoComplex() {}
	NoComplex operator - (NoComplex& right)
	{
		real -= right.real;
		im -= right.im;
		return *this;
	}
	NoComplex operator * (NoComplex& right)
	{
		real *= right.real;
		im *= right.im;
		return *this;
	}
	NoComplex operator * (int right)
	{
		real *= right;
		return *this;
	}
	NoComplex operator / (NoComplex& right)
	{
		if (right.real==0)
		{
			real = 0;
		}
		else
		real /= right.real;
		if (right.im==0)
		{
			im = 0;
		}
		else
		im /= right.im;
		return *this;
	}
	NoComplex operator - (int right)
	{
		real -= right;
		return *this;
	}
	NoComplex operator = (int right)
	{
		real = right;
		return *this;
	}
	bool operator == (int right)
	{
		if (real == right)
			return true;
		else
			return false;
	}
	friend istream& operator >> (istream& s, NoComplex &right)
	{
		cout << "\nВедите действительную часть: ";
		s >> right.real;
		cout << "\nВедите мнимую часть: ";
		s >> right.im;
		return s;
	}
	friend ostream& operator << (ostream& s, NoComplex &right)
	{
		s << "(" << right.real << ")" << " + I (" << right.im << ")\n";
		return s;
	}
};