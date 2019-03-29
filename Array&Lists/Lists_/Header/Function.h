#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define DestroyString ClearString
#define MAX_SIZE 100

enum ElemTag { ATOM, LIST, HEAD };


class SString {
public:
	int length;
	char *str;
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
};


void sever(SString &str, SString &hstr);
void visit(AtomType elem);

class GLNode;
typedef GLNode GList;

class GLNode {
public:
	ElemTag tag;
	union {
		AtomType atom;
		GLNode *head;
		};
	GLNode *next;
public:
	GLNode();
	void CreateGList(char* FileName);
	void CreateListSub(SString str);
	void DestroyGList();
	void CopyGList(GList &R);
	int GListLength();
	int GListDepth();
	Status GListEmpty();
	GList GetHead();
	GList GetTail();
	void InsertFirst_GL(GList elem);
	void DeleteFirst_GL(GList &elem);
	void Traverse_GL(void(*func)(AtomType atom));

};
#endif

