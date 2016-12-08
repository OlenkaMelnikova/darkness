// My_List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Inventory 
{
	char item[40];
	char retail[13];
	double cost; 
	
};

struct List 
{
	Inventory inventory; 
	List *pNext;
};


void addFirst(List *& pF, List* p) 
{
	p->pNext = pF;
	pF = p;
}

List * delFirst(List *&pF) 
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;

}

bool add(List *&pF, List * pZad, List *p)
{
	
	if (pZad == pF) 
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF; 
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false; 
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}

List * del(List*& pF, List *p) 
{
	if (pF == 0) return 0;
	if (pF == p) 
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF; 
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0; 
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF)); 
}

int main(int argc, char* argv[])
{
	List *pF = 0;
	List *p;
	
	char choice; 
	do
	{
		p = (List *)malloc(sizeof(List)); 

		printf("\nitem: ");
		fflush(stdin); gets_s(p->inventory.item, 39);
		printf("retail=");
		fflush(stdin); gets_s(p->inventory.retail,12);
		printf("cost=");
		fflush(stdin); scanf_s("%lf", &p->inventory.cost);
		
	
		addFirst(pF, p); 
		printf("For continue press Y or y else any key! ");
		choice = _getche(); 
	} while (choice == 'Y' || choice == 'y');
	
	for (List *pi = pF; pi; pi = pi->pNext) 
		printf("\n%s %s %s cost=%.2f", pi->inventory.item,pi->inventory.retail, pi->inventory.cost);

	
	for (List *pi = pF; pi->pNext;)
	{
		double min = pi->inventory.cost;
		List *pmin = pi;
		for (List *pj = pi->pNext; pj; pj = pj->pNext)
			if (pj->inventory.cost<min)
			{
				min = pj->inventory.cost;
				pmin = pj;
			}
		if (pi != pmin) 
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi = pi->pNext;
	}
	printf("\nSrting:");
	for (List *pi = pF; pi; pi = pi->pNext) 
		printf("\n%s %s %s cost=%.2f", pi->inventory.item, pi->inventory.retail, pi->inventory.cost);
	printf("\nFor exit press any key ");
	system("pause");
	return 0;
}



