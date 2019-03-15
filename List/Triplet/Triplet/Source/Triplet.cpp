// Triplet.cpp : Defines the entry point for the console application.



#include "stdafx.h"
#include "iostream"
#include "Test.h"
#include "Mytriplet.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Triplet T;
	Elemtype m;
	Status i;
	InitTriplet(T, 4, 2, -1);
	cout << "The element is:" << T[0] << ends << T[1] << ends << T[2] << endl;

	Get(T, 2, m);
	cout << "The second element is:" << m << endl;

	Put(T, 2, 0);
	cout << "Now,the element is:" << T[0] << ends << T[1] << ends << T[2] << endl;

	i=IsAscending(T);
	cout << "After Ascending test,result is:" << i << "(1 for ture,0 for false)" << endl;

	i=IsDescending(T);
	cout << "After Descending test,result is:" << i << "(1 for ture,0 for false)" << endl;

	i = Max(T, m);
	cout << "The max is:" << m << endl;

	i = Min(T, m);
	cout << "The min is:" << m << endl;
	return 0;
}

