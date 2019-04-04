#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "stdio.h"

char buf[MAX_SIZE];
using namespace std;
SString::SString()
{
	length = 0;
	str = NULL;
}
void SString::StrAssign(char *chars)
{
	if (str)
		delete[] str;
	int len = strlen(chars);
	if (len == 0) {
		str = NULL;
		length = 0;
		return;
	}
	str = new char[len];
	for (int i = 0; i < len; i++) {
		str[i] = chars[i];
	}
	length = len;
}
void SString::StrCopy(const SString &S)
{
	int len = S.length;
	if (str)
		delete[] str;
	str = new char[len];
	for (int i = 0; i < len; i++) {
		str[i] = S.str[i];
	}
	length = len;
}
Status SString::StrEmpty()
{
	if (length == 0)
		return TRUE;
	else
		return FALSE;
}
int SString::StrCompare(const SString &S)
{
	for (int i = 0, j = 0; i < length&&j < S.length; i++, j++)
		if (str[i] != S.str[j])
			return str[i] - S.str[j];
	return length - S.length;
}
int SString::StrLength()
{
	return length;
}
void SString::ClearString()
{
	length = 0;
	delete[] str;
	str = NULL;//不设置成0容易发生指针倒悬，发生错误。
}
void SString::Concat(SString L, SString &S)
{
	int len = length + L.length;
	if (S.str)
		delete[] S.str;
	int i=0;
	S.str = new char[len];
	for (int i = 0; i < length; i++) {
		S.str[i] = str[i];
	}
	for (int i = length; i < len; i++) {
		S.str[i] = L.str[i - length];
	}
	S.length = len;
}
Status SString::SubString(SString &Sub, int pos, int len)
{// 用Sub返回串S的自第pos个字符起长度为len的子串。
	if (pos<1 || pos>length)
		return ERROR;
	if (Sub.str)
		delete[] Sub.str;
//	char*temp = new char[len];
	Sub.str = new char[len];
	for (int i = 0; i < len; i++) {
		Sub.str[i] = str[i + pos - 1];
	}
	Sub.length = len;
	return OK;
}
int SString::Index(SString S, int pos)// 返回子串S在主串中第pos个字符之后的位置。若不存在，则函数值为0。
// 其中， T非空， 1≤pos≤StrLength(S)。算法4.5
{
	if ((1 > pos) || (pos > length - S.length + 1))
		return 0;	
	SString sub;
	int len = S.length;
	for (int i = pos; i <= length - S.length + 1; i++) {
		SubString(sub, i, len);
		if (sub.StrCompare(S) == 0) {
			sub.DestroyString();
			return i;
		}
//		sub.DestroyString();	
	}
	return 0;
}
Status SString::StrInsert(SString &S, int pos)
{// 初始条件：串S存在， 1≤pos≤StrLength(S)+1
// 操作结果：在串S的第pos个字符之前插入串T。完全插入返回TRUE，部分插入返回FALSE
	if (pos<1 || pos>length + 1)
		return ERROR;
	int len = length + S.length;
	char*temp = new char[len];
	for (int i = 0; i < pos - 1; i++) {
		temp[i] = str[i];
	}
	for (int i = pos - 1; i < pos + S.length - 1; i++) {
		temp[i] = S.str[i - pos + 1]; 
	}
	for (int i = pos + S.length - 1; i < length + S.length; i++) {
		temp[i] = str[i - S.length];
	}
	delete[] str;
	str = temp;
	length = len;
	return OK;
}
Status SString::StrDelete(int pos, int len)
{// 初始条件：串S存在， 1≤pos≤StrLength(S)-len+1
// 操作结果：从串S中删除自第pos个字符起长度为len的子串
	if (pos<1 || pos>length)
		return ERROR;
	for (int i = pos-1; i < length; i++)
		str[i] = str[i + len];
	length -= len;
	char *temp = new char[length];
	for (int i = 0; i < length; i++) {
		temp[i] = str[i];
	}
	delete[] str;
	str = temp;
	return OK;
}
Status SString::Replace(SString &S, SString &T)
{// 初始条件：串S， T和V存在， T是非空串
// 操作结果：用T替换主串中出现的所有与S相等的不重叠的子串
	if (T.length == 0 || S.length == 0)
		return ERROR;
	int pos = 1; str;
	while (pos = Index(S, pos)) {
		StrDelete(pos, S.length);
		if(StrInsert(T, pos)==ERROR)
			return ERROR;
		pos += T.length;
	}
	return OK;
}
void SString::StrPrint()
{
	for (int i = 0; i < length; i++)
		cout << str[i];
	cout << endl;
}

GLNode::GLNode()
{
	tag = LIST;
	head = NULL;
	next = NULL;
}

GList::GList()
{
	head = NULL;
}

//void GList::CreateGList(char* FileName)
//{
//	int iPos = 1;
//	FILE*pF = NULL;
//	errno_t status;
//	SString Sstr,Ssub,Sbracket;
//	GLNode *Gtemp = NULL;
//	status = fopen_s(&pF, FileName, "r");
//	if (status != 0) {
//		cout << "无法打开文件" << FileName << endl;
//		exit(0);
//	}
//	fgets(buf, MAX_SIZE, pF);
//	buf[strlen(buf) - 1] = '\0';
//	Sstr.StrAssign(buf);
//	_CreateGList(head,Sstr);
//	fclose(pF);
//}

void GList::_CreateGList(GLNode *&node, SString str)
{
	SString SBracket, Substr, HSubstr;
	GLNode *Gptr = NULL;
	SBracket.StrAssign("()");
	node = new GLNode;
	if (!str.StrCompare(SBracket)) {
		node->tag = LIST;
		node->head = NULL;
	}
	else if (str.StrLength() == 1) {
		node->tag = ATOM;
		node->atom = str.str[0];
		node->next = NULL;
	}
	else {
		node->tag = LIST;
		node->head = NULL;
		node->next = NULL;
		str.SubString(Substr, 2, str.StrLength() - 2);
		sever(Substr, HSubstr);
		_CreateGList(node->head, HSubstr);
		Gptr = node->head;
		while (!Substr.StrEmpty()) {
			sever(Substr, HSubstr);
			_CreateGList(Gptr->next, HSubstr);
			Gptr = Gptr->next;
		}
	}
}
void GList::_DestroyGList(GLNode *&node)
{
	GLNode *pGhead = NULL, *pGnext = NULL;
	if (node != NULL) {
		if (node->tag == ATOM) {
			pGhead = NULL;
		}
		else {
			pGhead = node->head;
		}
		pGnext = node->next;
		_DestroyGList(pGnext);
		_DestroyGList(pGhead);
		delete node;
		node = NULL;
	}
}
void GList::_CopyGList(GLNode *src, GLNode *&des)
{
	if (src != NULL) {
		des = new GLNode;
		des->tag = src->tag;
		if (src->tag == ATOM) {
			des->atom = src->atom;
		}
		else {
			_CopyGList(src->head, des->head);		
		}
		_CopyGList(src->next, des->next);
	}
	else {
		des = NULL;
	}
}
int GList::_GListDepth(GLNode *node)
{
	int length = 0, max = 0;
	GLNode *pGtemp = NULL;
	if (node == NULL || (node->tag == LIST&&node->head == NULL))
		return 1;
	else if (node->tag == ATOM)
		return 0;

	pGtemp = node->head;
	while (pGtemp != NULL) {
		length = _GListDepth(pGtemp);
		if (length > max)
			max = length;
		pGtemp = pGtemp->next;
	}
	return max + 1;
}
void GList::_Traverse_GL(GLNode * node, void(*func)(AtomType elem))
{
	if ((node == NULL))
		return;
	if (node->tag == ATOM) {
		func(node->atom);		
	}
	else {
		_Traverse_GL(node->head,func);
	}
	_Traverse_GL(node->next, func);
}

void GList::CreateGList(char* FileName)
{
	int iPos = 1;
	FILE*pF = NULL;
	errno_t status;
	SString Sstr, Ssub, Sbracket;
	GLNode *Gtemp = NULL;
	status = fopen_s(&pF, FileName, "r");
	if (status != 0) {
		cout << "无法打开文件" << FileName << endl;
		exit(0);
	}
	fgets(buf, MAX_SIZE, pF);
	buf[strlen(buf) - 1] = '\0';
	Sstr.StrAssign(buf);
	_CreateGList(head, Sstr);
	fclose(pF);
}
void GList::DestroyGList()
{
	_DestroyGList(head);
}
void GList::CopyGList(GList &L)
{
	_CopyGList(head, L.head);
}
void GList::GetHead(GList &L)
{
	GLNode *pGtemp = NULL;
	if (L.head==NULL||(L.head->head==NULL&&L.head->tag == LIST)) {
		head = NULL;
		return;
	}
	pGtemp = L.head->head->next;
	L.head->head->next = NULL;
	_CopyGList(L.head, head);
	L.head->head->next = pGtemp;
}
void GList::GetTail(GList &L)
{
	GLNode *pGtemp = NULL;
	if (L.head == NULL || (L.head->tag == LIST&&L.head->head == NULL)) {
		head = NULL;
		return;
	}
	pGtemp = L.head->head;
	L.head->head = pGtemp->next;
	_CopyGList(L.head, head);
	L.head->head = pGtemp;
}
int GList::GListLength()
{
	if (head == NULL)
		return 0;
	GLNode *pGtemp = head->head;	
	int iCount = 0;
	for (; pGtemp != NULL; iCount++, pGtemp = pGtemp->next);
	return iCount;
}
int GList::GListDepth()
{
	return _GListDepth(head);
}
Status GList::GListEmpty()
{
	if (head == NULL || (head->tag == LIST&&head->next == NULL))
		return	TRUE;
	else
		return	FALSE;
}
void GList::InsertFirst_GL(GList &L)
{
	GLNode *pGtemp = NULL;
	pGtemp = head->head;
//	head->head = L.head;
	_CopyGList(L.head, head->head);
	head->head->next = pGtemp;
}
void GList::DeleteFirst_GL(GList &L)
{
	if (head == NULL || (head->tag == LIST&&head->head == NULL))
		return;
	GLNode *pGtemp = NULL;
	pGtemp = head->head;
	head->head = head->head->next;
	L.head = pGtemp;
}
void GList::Traverse_GL(void(*func)(AtomType elem))
{
	_Traverse_GL(head, func);
}

void visit(AtomType elem)
{
	cout << elem << ends;
}

void sever(SString &str, SString &hstr)
{
	SString SBracketL, SBracketR, SComma, SJudge, STemp;
	int iBracketNum = 0, iLength = 0, iLoop = 1;
	SBracketL.StrAssign("(");
	SBracketR.StrAssign(")");
	SComma.StrAssign(",");
	iLength = str.StrLength();	
	do {
		str.SubString(SJudge, iLoop, 1);
		if (!SJudge.StrCompare(SBracketL)) {
			iBracketNum++;
		}
		else if (!SJudge.StrCompare(SBracketR)) {
			iBracketNum--;
		}
		iLoop++;
	} while ((iLoop <= iLength) && (SJudge.StrCompare(SComma) || iBracketNum));
	if (iLoop <= iLength) {
		str.SubString(hstr, 1, iLoop - 2);
		str.SubString(STemp, iLoop, iLength - iLoop + 1);
		str.StrCopy(STemp);
	}
	else {
		hstr.StrCopy(str);
		str.ClearString();
	}
}