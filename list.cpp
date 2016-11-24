// list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

int main()
{
	list<int>lst;
	int j;

	for (j = 0; j < 22; j++) lst.push_back(rand());
	cout << "Original Content:\n" ;
	list<int>::iterator p = lst.begin();
	while (p != lst.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl<< endl;
	lst.sort();
	cout << "Orderd Content:\n";
	p = lst.begin();
	while (p != lst.end()){
		cout << *p << " ";
		p++;
	}
	return 0;
}
