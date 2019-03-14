#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define MAX_STR_LEN 40
typedef char String[MAX_STR_LEN + 1];
#define DestroyString ClearString
class SString {
private:
	int length;
	String str;
public:
	SString(); 
	Status StrAssign(char *chars);
	void StrCopy(const SString &S);
	Status StrEmpty();
	int StrCompare(const SString &S);
	int StrLength();
	void ClearString();
	Status Concat(SString L, SString &S);
	Status SubString(SString &Sub, int pos, int len);
	int Index(SString S, int pos);
	Status StrInsert(SString &S, int pos);
	Status StrDelete(int pos, int len);
	Status Replace(SString &S, SString &T);
	void StrPrint();
};
#endif
