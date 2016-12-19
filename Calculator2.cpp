// Calculator2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
using namespace std;
double sum(double a, double b)
{
	return a + b;
}
double sub(double a, double b)
{
	return a - b;
}

double pow1(double a, double b)
{
	return a*b;
}
double * dev(double a, double b)
{
	if (b != 0)
	{
		double *p = new double;
		*p = a / b;
		return p;
	}
	else return nullptr;
}
double involution(double a, int c)
{
	double a1 = 1;
	if (c>0)
		for (int i = 0; i < c; i++)
			a1 = a1*a;
	if (c<0)
		for (int i = 0; i < (-c); i++)
			a1 = a1 / a;
	return a1;
}

double *sqrt1(double a)
{
	double c = 0, res = a;
	if (a > 0)
	{
		double *r = new double;
		if (a != 1 && a != 0)
		{
			while (c - res > 0.00001 || c - res < -0.00001)
			{
				c = res;
				res = (c + a / res) / 2;
			}
			*r = res;
		}
		else if (a == 1) *r = 1;
		else if (a == 0) *r = 0;
		return r;
	}
	else return nullptr;
}
double absolut(double a)
{
	return ((a >= 0) ? a : -a);
}
double roundp(double a)
{
	if (a < 0)
		a = -absolut(a);
	return a;
}

int main() {
	double a, b;
	int c;
	cout << "Enter value a\n ";
	cin >> a;
	cout << "Enter value b\n ";
	cin >> b;
	cout << "Enter value c\n ";
	cin >> c;
	cout << roundp(sum(a, b)) << endl;
	cout << roundp(sub(a, b)) << endl;
	cout << roundp(pow1(a, b)) << endl;
	double * res = dev(a, b);
	if (res != nullptr)
		cout << "a / b = " << *res << endl;
	else
		cout << "a/0 -> error" << endl;
	delete res;
	double *r = sqrt1(a);
	if (r) cout << "a^0.5=" << *sqrt1(a) << endl;
	else cout << "a < 0 -> error" << endl;
	delete r;
	cout << roundp(involution(a, b)) << endl;

	system("pause");
}
