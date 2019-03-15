#include "stdafx.h"
#include "FunctionString.h"
#include "Test.h"
#include "stdio.h"
using namespace std;

char buf[MaxLineLen + 1];
extern WordListType noidx, wdlist;
extern IdxListType idxlist;
//SString类的成员函数
SString::SString()
{
	length = 0;
	str = NULL;
}
void SString::StrInit()
{
	str = NULL;
	length = 0;
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
int SString::StrCompare(const SString &S)//如果两个字符串相同，返回0，如果主串在字母表后边，返回大于一的值，否则返回小于一的值
{
	for (int i = 0, j = 0; i < length&&j < S.length; i++, j++)
		if (str[i] != S.str[j])
			return str[i] - S.str[j];//ascii码字母在后边数值大
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

//WordListType的类成员函数
void WordListType::ExtractKeyword(int &BookNo)//将书名中的关键词提取到item中去，BookNo是书的检索号码；
{
	char *head = NULL, *tail = NULL,*temp;
	bool bFlag = TRUE;
	int size = 0,loop=0,flag=0;
	for (int i = 0; i < length; i++) {
		delete[] item[i];
		item[i] = NULL;
		
	}
	length = 0;
	BookNo = atoi(buf);
	head = buf + 4;
	while (bFlag) {
		tail = strchr(head, ' ');
		if (tail == NULL) {
			tail = strchr(head,'\12');
			bFlag = FALSE;
		}
		size = tail - head;
		if (head[0] >= 'A'&&head[0] <= 'Z') {
			item[length] = new char[size + 1];
			for (int i = 0; i < size; i++) {
				item[length][i] = head[i];
			}
			item[length][size] = '\0';
			for (loop = 0; loop < noidx.length&&(flag=strcmp(noidx.item[loop], item[length])); loop++);
			if (!flag) {
				delete item[length];
			}
			else
				length++;
		}
		head = tail + 1;
	}
}
void WordListType::GetWord(int i, SString &wd)//获取WordListType的第i个成员，以wd返回；
{
	wd.StrAssign(item[i]);
}
WordListType::WordListType() {
	length = 0;
}

//IdxTermType的类成员函数
IdxTermType::IdxTermType()
{
	InitList(bnolist);
}

//IdxListType的类成员函数
IdxListType::IdxListType()
{
	length = 0;
	
}
bool IdxListType::Locate(SString wd, int &pos)//在索引表中查询是否存在关键词wd，如果不存在返回FALSE,以pos返回插入位置，否则返回TURE;
{	
	int status = 0;
	for (pos = 0; ((status = item[pos].keyword.StrCompare(wd)) < 0)&&!item[pos].keyword.StrEmpty(); pos++);
	if (status != 0) {
		return FALSE;
	}
	else {
		return TRUE;	
	}
}
void IdxListType::InsertNewKey(int i, SString wd)//在检索表上i位置插入关键词wd
{
	for (int j = length - 1; j >= i; j--) {
		item[j + 1] = item[j];
	}
	InitList(item[i].bnolist);
	item[i].keyword.StrInit();
	item[i].keyword.StrCopy(wd);
	length++;
}
void IdxListType::InsertBook(int pos, int bno)//在索引表的第i项插入索引号bno
{
	Link temp;
	MakeNode(temp, bno);
	Append(item[pos].bnolist,temp);
}
void IdxListType::InsIdxList(int bno)
{
	SString wd;
	bool status;
	int pos = 0;
	for (int i = 0; i < wdlist.length; i++) {
		wdlist.GetWord(i,wd);
		if (Locate(wd, pos)) {
			InsertBook(pos, bno);
		}
		else {
			InsertNewKey(pos,wd);
			InsertBook(pos, bno);
			idxlist;
		}
	}
}
void IdxListType::PutText(FILE *p)
{
	Link l;
	fprintf(p, "%d\n", length);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < item[i].keyword.StrLength(); j++) {
			fprintf(p, "%c", item[i].keyword.str[j]);
		}
		fprintf(p, "\n%d\n", item[i].bnolist.length);
		l = item[i].bnolist.head;
		for (int j = 0; j < item[i].bnolist.length; j++) {
			l = l->next;
			fprintf(p, "%d ", l->data);
		}
		fprintf(p, "\n");
	}
}