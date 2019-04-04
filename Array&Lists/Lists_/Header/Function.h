#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define DestroyString ClearString
#define MAX_SIZE 100

enum ElemTag { ATOM, LIST };


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

class GLNode {
public:
	ElemTag tag;
	union {
		AtomType atom;
		GLNode *head;
	};
	GLNode *next;
	GLNode();
};
class GList{
private:
	GLNode *head;
	void _CreateGList(GLNode *&node,SString str);
	void _DestroyGList(GLNode *&node);
	void _CopyGList(GLNode *sre, GLNode *&des);
	int _GListDepth(GLNode *node);
	void _Traverse_GL(GLNode * node, void(*func)(AtomType elem));
public:
	GList();
	void CreateGList(char* FileName);
	void DestroyGList();
	void CopyGList(GList &L);
	void GetHead(GList &L);
	void GetTail(GList &L);
	int GListLength();
	int GListDepth();
	Status GListEmpty();
	void InsertFirst_GL(GList &L);
	void DeleteFirst_GL(GList &L);
	void Traverse_GL(void (*func)(AtomType elem));
};
#endif

