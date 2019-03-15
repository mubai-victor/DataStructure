#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define DestroyString ClearString
#define CHUNK_SIZE 4
#define BLANK '#'
struct Chunk {
	char ch[CHUNK_SIZE];
	Chunk *next;
};
class SString {
private:
	int length;
	Chunk *head, *tail;
public:
	SString(); 
	Status StrAssign(char *chars);
	Status ToChars(char *&chars)const;
	Status StrCopy(const SString &S);
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
