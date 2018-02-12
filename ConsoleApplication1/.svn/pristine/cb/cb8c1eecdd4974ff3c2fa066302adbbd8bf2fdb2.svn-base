#pragma once
#include <math.h>
#include <conio.h>
#include <iostream>
#include <typeinfo>
#include "ClassComplex.h"
static char* CONTINUE = "\nДЛЯ ПРОДОЛЖЕНИЯ НАЖМИТЕ ЛЮБУЮ КЛАВИШУ...  ESC - ВЫХОД";
using namespace std;
template <class T>
class MyVektor
{
protected:
	T *a;
	int size;
public:
	MyVektor<T>() {};
	MyVektor<T>(int size)
	{
		if (size == 1)
		{
			delete a;
			a = new T;
		}
		else
		{
			delete[] a;
			a = new T[size];
		}
		this->size = size;
		ini(a, size);
	}
	MyVektor<T>(const MyVektor<T>&init)
	{
		this->size = init.size;
		if (this->size == 1)
		{
			this->a = new T(*init.a);
		}
		else
		{
			this->a = new T[size];
			for (int i = 0; i < this->size; i++)
				this->a[i] = init.a[i];
		}
	}
	~MyVektor()
	{
		if (size == 1)
			delete a;
		else
			delete[] a;
	}
	void ini(T* a, int size)
	{
		if (size == 1)
		{
			cout << "\nВведите элемент: ";
			Input(*a);
		}
		else
			if ((size > 1) && (size <= 10))
			{
				for (int i = 0; i < size; i++)
				{
					cout << "\nВведите элемент массива " << "[" << i << "]: ";
					Input(a[i]);
				}
			}
			else
			{
				if ((size > 10) && (size <= 1000))
				{
					for (int i = 0; i < size; i++)
						a[i] = rand() % 10 + 1;
				}
			}
	}
	void Input(T& k)
	{
		cout << "\nВведите значение типа " << typeid(k).name() << ":";
		while (!(cin >> k))
		{
			cout << "\n Ошибка ввода, введите ещё раз: ";
			cin.clear();
			while (cin.get() != '\n') continue;
		}
	}
	MyVektor<T> operator = (MyVektor<T>& right)
	{
		size = right.size;
		if (size == 1)
		{
			a = new T(right.a[0]);
		}
		else
		{
			a = new T[size];
			for (int i = 0; i <size; i++)
				a[i] = right.a[i];
		}
		return *this;
	}
	MyVektor<T> operator - (MyVektor<T>& right)
	{
		MyVektor x(*this);
		if (right.size == 1)
			for (int i = 0; i<size; i++)
				x.a[i] = x.a[i] - *right.a;
		else
			if (size == 1)
				*x.a = *x.a - right.a[0];
			else
				if (x > right)
					for (int i = 0; i < right.size; i++)
						x.a[i] = x.a[i] - right.a[i];
				else
					if (x < right)
						for (int i = 0; i<x.size; i++)
							x.a[i] = x.a[i]  - right.a[i];
					else
						for (int i = 0; i<x.size; i++)
							x.a[i] = x.a[i] - right.a[i];
		return x;
	}
	MyVektor<T> operator - (int koef)
	{
		MyVektor x(*this);
		for (int i = 0; i<x.size; i++)
			x.a[i] = x.a[i] - koef;
		return x;
	}
	MyVektor<T> operator / (MyVektor<T>& right)
	{
		MyVektor x(*this);
		if (right.size == 1)
			for (int i = 0; i < size; i++)
				if (*right.a == 0) throw "Деление на ноль!";
				else
					x.a[i] = x.a[i] / *right.a;
		else
			if (size == 1)
				if (right.a[0] == 0) throw "Деление на ноль!";
				else
					*x.a = *x.a / right.a[0];
			else
				if (x > right)
					for (int i = 0; i<right.size; i++)
						if (right.a[i] == 0) throw "Деление на ноль!";
						else
							x.a[i] = x.a[i] / right.a[i];
				else
					if (x < right)
						for (int i = 0; i<x.size; i++)
							if (right.a[i] == 0) throw "Деление на ноль!";
							else
								x.a[i] = x.a[i] / right.a[i];
					else
						for (int i = 0; i<x.size; i++)
							if (right.a[i] == 0) throw "Деление на ноль!";
							else
								x.a[i] = x.a[i] / right.a[i];
		return x;
	}
	MyVektor<T> operator * (MyVektor<T>& right)
	{
		MyVektor x(*this);
		if (right.size == 1)
			for (int i = 0; i<size; i++)
				x.a[i] = x.a[i] * *right.a;
		else
			if (size == 1)
				*x.a = *x.a * right.a[0];
			else
				if (x > right)
					for (int i = 0; i<right.size; i++)
						x.a[i] = x.a[i] * right.a[i];
				else
					if (x < right)
						for (int i = 0; i<x.size; i++)
							x.a[i] = x.a[i] * right.a[i];
					else
						for (int i = 0; i<x.size; i++)
							x.a[i] = x.a[i] * right.a[i];
		return x;
	}
	MyVektor<T> operator * (int koef)
	{
		MyVektor x(*this);
		for (int i = 0; i<x.size; i++)
			x.a[i] = x.a[i] * koef;
		return x;
	}
	friend bool operator < (MyVektor<T>& left, MyVektor<T>& right)
	{
		if (left.size < right.size)
			return true;
		else
			return false;
	}
	friend bool operator > (MyVektor<T>& left, MyVektor<T>& right)
	{
		if (left.size > right.size)
			return true;
		else
			return false;
	}
	friend bool operator == (MyVektor<T>& left, MyVektor<T>& right)
	{
		if ((left.size) == (right.size))
			return true;
		else
			return false;
	}
	friend ostream& operator << (ostream& s, const MyVektor<T>& v)
	{
		if (v.size == 1)
		{
			s << "\nЭлемент " << ": " << *v.a << endl;
		}
		else
		{
			s << "\nМасив " << ": ";
			for (int i = 0; i < v.size; i++)
			{
				s << " " << v.a[i];
			}
			s << endl;
		}
		return s;
	}
};