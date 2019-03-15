#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#include "FunctionList.h"
#define DestroyString ClearString
#define MaxKeyNum 25
#define MaxLineLen 52
#define MaxNoIdx 10
class SString {
public:
	int length;
	char *str;
public:
	SString(); 
	void StrInit();
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
};


class WordListType {//临时存放书名关键词以及存放非索引词的结构；
public:
	char *item[MaxKeyNum];
	int length;
public:
	void ExtractKeyword(int &BookNo);
	void GetWord(int i, SString &wd);
	WordListType();
};


class IdxTermType {//索引项
public:
	SString keyword;
	LinkList bnolist;
public:
	IdxTermType();
};


class IdxListType {//索引表
private:
	IdxTermType item[MaxKeyNum];
	int length;
public:
	IdxListType();
	bool Locate(SString wd,int &pos);
	void InsertNewKey(int i, SString wd);
	void InsertBook(int pos, int bno);
	void InsIdxList(int bno);
	void PutText(FILE *p);
};

#endif
