#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "stdio.h"
using namespace std;
SString::SString()
{
	length = 0;
}
Status SString::StrAssign(char *chars)
{
	int len = strlen(chars);
	if (len > MAX_STR_LEN)
		return ERROR;
	for (int i = 1; i <= len; i++) {
		str[i] = chars[i-1];
	}
	length = len;
	return OK;
}
void SString::StrCopy(const SString &S)
{
	int len = S.length;
	for (int i = 1; i <= len; i++) {
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
	for (int i = 1, j = 1; i <= length&&j <= S.length; i++, j++)
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
}
Status SString::Concat(SString L, SString &S)
{
	if (length + L.length <= MAX_STR_LEN) {
		for (int i = 1; i <= length; i++) {
			S.str[i] = str[i];
		}
		for (int i = 1; i <= L.length; i++) {
			S.str[i + length] = L.str[i];
		}
		S.length = length + L.length;
		return TRUE;
	}
	else {
		for (int i = 1; i <= length; i++) {
			S.str[i] = str[i];
		}
		for (int i = 1; i + length <= MAX_STR_LEN - 1; i++) {
			S.str[i + length] = L.str[i];
		}
		S.length = MAX_STR_LEN;
		return FALSE;
	}
}
Status SString::SubString(SString &Sub, int pos, int len)
{// ��Sub���ش�S���Ե�pos���ַ��𳤶�Ϊlen���Ӵ���
	if (pos<1 || pos>length || pos + len > MAX_STR_LEN - 1)
		return ERROR;
	for (int i = 1; i <= len; i++) {
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
	for (int i = pos; i <= length - S.length + 1; i++) { 
		int j,k;
		for (j = 1;j <= S.length&&str[j + i - 1] == S.str[j];j++ );
		if (j > S.length)
			return i;
	}
	return 0;
}
Status SString::StrInsert(SString &S, int pos)
{// ��ʼ��������S���ڣ� 1��pos��StrLength(S)+1
// ����������ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE�����ֲ��뷵��FALSE
	if (pos<1 || pos>length + 1)
		return ERROR;
	if (length + S.length <= MAX_STR_LEN) {
		for (int i = length; i >= pos; i--) {
			str[i + S.length] = str[i];
		}
		for (int i = pos; i <= pos + S.length - 1; i++) {
			str[i] = S.str[i - pos + 1];
		}
		length += S.length;
		return TRUE;;
	}
	else {
		for (int i = MAX_STR_LEN; i >= pos + S.length; i--) {
			str[i] = str[i - S.length];
		}
		for (int i = pos; i < pos + S.length; i++) {
			str[i] = S.str[i-pos+1];
		}
		length = MAX_STR_LEN;
		return FALSE;
	}
}
Status SString::StrDelete(int pos, int len)
{// ��ʼ��������S���ڣ� 1��pos��StrLength(S)-len+1
// ����������Ӵ�S��ɾ���Ե�pos���ַ��𳤶�Ϊlen���Ӵ�
	if (pos<1 || pos>length)
		return ERROR;
	for (int i = pos; i <= length; i++)
		str[i] = str[i + len];
	length -= len;
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
	for (int i = 1; i <= length; i++)
		cout << str[i];
	cout << endl;
}