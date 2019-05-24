#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
#define DestroyString ClearString
#define MAX_SIZE 100

enum ElemTag { ATOM, LIST };
enum Visited { VISITED, UNVISITED };

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

class GLNode {
public:
	ElemTag tag;
	Visited status;
	union {
		AtomType atom;
		struct {
			GLNode *head, *tail;
		}ptr;
	};
	GLNode();
};
void print(GLNode *p);
class GList {
private:
	GLNode *head;
	void _CreateList(SString str,GLNode *&p);
	void _DestroyGList(GLNode *&node);
	void _Traverse_GL(GLNode *node, void(*func)(GLNode *p));
public:
	GList();
	void MarkList();
	void CreateGList(char* FileName);
	void DestroyGList();
	void Traverse_GL(void func(GLNode*elem));
};
#endif

