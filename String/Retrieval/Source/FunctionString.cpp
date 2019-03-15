#include "stdafx.h"
#include "FunctionString.h"
#include "Test.h"
#include "stdio.h"
using namespace std;

char buf[MaxLineLen + 1];
extern WordListType noidx, wdlist;
extern IdxListType idxlist;
//SString��ĳ�Ա����
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
int SString::StrCompare(const SString &S)//��������ַ�����ͬ������0�������������ĸ���ߣ����ش���һ��ֵ�����򷵻�С��һ��ֵ
{
	for (int i = 0, j = 0; i < length&&j < S.length; i++, j++)
		if (str[i] != S.str[j])
			return str[i] - S.str[j];//ascii����ĸ�ں����ֵ��
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
	str = NULL;//�����ó�0���׷���ָ�뵹������������
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
{// ��Sub���ش�S���Ե�pos���ַ��𳤶�Ϊlen���Ӵ���
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
int SString::Index(SString S, int pos)// �����Ӵ�S�������е�pos���ַ�֮���λ�á��������ڣ�����ֵΪ0��
// ���У� T�ǿգ� 1��pos��StrLength(S)���㷨4.5
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
{// ��ʼ��������S���ڣ� 1��pos��StrLength(S)+1
// ����������ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE�����ֲ��뷵��FALSE
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
{// ��ʼ��������S���ڣ� 1��pos��StrLength(S)-len+1
// ����������Ӵ�S��ɾ���Ե�pos���ַ��𳤶�Ϊlen���Ӵ�
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
{// ��ʼ��������S�� T��V���ڣ� T�Ƿǿմ�
// �����������T�滻�����г��ֵ�������S��ȵĲ��ص����Ӵ�
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

//WordListType�����Ա����
void WordListType::ExtractKeyword(int &BookNo)//�������еĹؼ�����ȡ��item��ȥ��BookNo����ļ������룻
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
void WordListType::GetWord(int i, SString &wd)//��ȡWordListType�ĵ�i����Ա����wd���أ�
{
	wd.StrAssign(item[i]);
}
WordListType::WordListType() {
	length = 0;
}

//IdxTermType�����Ա����
IdxTermType::IdxTermType()
{
	InitList(bnolist);
}

//IdxListType�����Ա����
IdxListType::IdxListType()
{
	length = 0;
	
}
bool IdxListType::Locate(SString wd, int &pos)//���������в�ѯ�Ƿ���ڹؼ���wd����������ڷ���FALSE,��pos���ز���λ�ã����򷵻�TURE;
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
void IdxListType::InsertNewKey(int i, SString wd)//�ڼ�������iλ�ò���ؼ���wd
{
	for (int j = length - 1; j >= i; j--) {
		item[j + 1] = item[j];
	}
	InitList(item[i].bnolist);
	item[i].keyword.StrInit();
	item[i].keyword.StrCopy(wd);
	length++;
}
void IdxListType::InsertBook(int pos, int bno)//��������ĵ�i�����������bno
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