#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "stdio.h"
using namespace std;
SString::SString()
{
	length = 0;
	str = NULL;
	next = NULL;
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
	delete[] next;
	str = NULL;//�����ó�0���׷���ָ�뵹������������
	next = NULL;
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
void SString::GetNext() {
	if (next) {
		delete[] next;
		next = NULL;
	}		
	next = new int[length];
	
	next[0] = -1;
	int i = 0, j = -1;
	while (i < length - 1) {
		if (j==-1 || str[i] == str[j]) {
			i++,j++;//����һ������ʵ�next�ĵ�length��Ԫ�أ�ʹ��ԭ��������ڴ����鷢���仯��ʹ���´��ͷŵ�ʱ��delete����
			next[i] = j;
		}
		else j = next[j];
	}
}
void SString::GetNextval()
{
	if (next)
		delete[] next;
	next = new int[length];
	next[0] = -1;
	int i = 0, j = -1;
	while (i < length - 1) {
		if (j==-1 || str[i] == str[j]) {
			i++,j++;
			if (str[i] == str[j])
				next[i] = next[j];
			else
				next[i] = j;
		}
		else j = next[j];
	}
}
int SString::Index_KMP(SString S, int pos)
{
	int i = pos - 1, j = 0;
	while (j < S.length && i < length) {
		if (j==-1 || S.str[j] == str[i])
			i++,j++;
		else {
			j = S.next[j];
		}
	}
	if (j == S.length)
		return i - j + 1;
	return 0;

}
void SString::PrintNext()
{
	for (int i = 0; i < length; i++)
		cout << next[i];
	cout << endl;
}