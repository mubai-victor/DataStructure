#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define DestroyString ClearString
class SString {
private:
	int length;
	char *str;
	int *next;
public:
	SString(); 
	void StrAssign(char *chars);
	void StrCopy(const SString &S);
	Status StrEmpty();
	int StrCompare(const SString &S);
	int StrLength();
	void ClearString();
	void Concat(SString L, SString &S);
	Status SubString(SString &Sub, int pos, int len);
	int Index(SString S, int pos);
	Status StrInsert(SString &S, int pos);
	Status StrDelete(int pos, int len);
	Status Replace(SString &S, SString &T);
	void StrPrint();
	void GetNext();
	void GetNextval();
	int Index_KMP(SString S, int pos);
	void PrintNext();
};
#endif
