#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define DestroyString ClearString
#define MAX_LINE 25
#define LINE_LEN 75
#define NAME_LEN 20
class SString {
private:
	int length;
	char *str;
public:
	SString(); 
	void Init();
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
	char* StrGet();
};
class Text {
private:
	SString t[MAX_LINE];
	char str[LINE_LEN];
	char FileName[NAME_LEN];
	FILE*p;
	int LineLength;
public:
	Text();
	void Open();//打开文件，将文件内容读入t中
	void List();
	void Insert();
	void Delete();
	void Copy();
	void Modify();
	void Search();
	void Replace();
	void Save();
};
#endif
