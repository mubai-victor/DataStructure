
#include "stdafx.h"

#include "Function.h"
#include "Test.h"
#include "stdio.h"

using namespace std;
SString::SString()
{
	length = 0;
	str = NULL;
}
void SString::Init() {
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
char* SString::StrGet() {
	return str;
}


Text::Text()
{
	p = NULL;
	LineLength = 0;
}
void Text::Open()//���ļ������ļ������ݶ�E:\�뵽t��ȥ��
{
	errno_t e;
	if (FileName[0])
		cout << "�ļ��Ѿ��򿪹���" << endl;
	else {
		cout << "�������ļ����֣�����·�����ֳ�������20�������ڣ�" << endl;
		getchar();
		gets_s(FileName,NAME_LEN);
		e = fopen_s(&p,FileName, "r");
		if (e==0) {
			while (fgets(str, LINE_LEN, p)!=NULL) {
				if (LineLength >= MAX_LINE) {
					cout << "�ļ�̫��" << endl;
					break;
				}
				str[strlen(str) - 1] = '\0';
				t[LineLength].StrAssign(str);
				LineLength ++;
			}
			fclose(p);
		}
		else {
			cout << "����һ�����ļ���" << endl;
		}
	}
}
void Text::List() //��ʾ�ļ��е�����
{
	for (int i = 0; i < LineLength; i++) {
		t[i].StrPrint();
	}
}
void Text::Insert()//�����С�
{
	int iLinePos = 0, iLineNum = 0;
	cout << "��l��֮ǰ����m�У�������l,m:" << endl;
	cin >> iLinePos >> iLineNum;getchar();
	if (iLinePos > LineLength || iLinePos<1 || LineLength + iLineNum>MAX_LINE) {
		cout << "��������." << endl;
		return;
	}
	for (int i = LineLength - 1 + iLineNum; i >= iLinePos - 1 + iLineNum; i--) {
		t[i] = t[i - iLineNum];
	}
	cout << "���������������ݡ�" << endl;
	for (int i = iLinePos - 1; i < iLinePos - 1 + iLineNum; i++) {
		
		gets_s(str);
		t[i].Init();
		t[i].StrAssign(str);
	}
	LineLength += iLineNum;
}
void Text::Delete()//ɾ����
{
	int iLinePos = 0, iLineNum = 0;
	cout << "��l�п�ʼɾ��m�У�������l,m��" << endl;
	cin >> iLinePos >> iLineNum;
	if (iLinePos<1 || iLinePos>LineLength || iLinePos + iLineNum - 1 > LineLength) {
		cout << "����Ĳ�������" << endl;
		return;
	}
	for (int i = iLinePos - 1; i < LineLength - iLineNum; i++) {
		t[i].ClearString();
		t[i].StrCopy(t[i + iLineNum]);
	}
	for (int i = LineLength - iLineNum;i < LineLength; i++) {
		t[i].Init();
	}
	LineLength -= iLineNum;
}
void Text::Copy()//�����е�����
{
	int iLineSource = 0, iLineDes = 0, iLineNum = 0;
	cout << "�Ѵ�m��ʼ��l�и��Ƶ�n֮ǰ��������m,l,n:" << endl;
	cin >> iLineSource >> iLineNum >> iLineDes;
	if (iLineSource<1 || iLineSource + iLineNum - 1>LineLength || iLineDes > LineLength + 1 || LineLength + iLineNum > MAX_LINE) {
		cout << "����Ĳ�������" << endl;
		return;
	}
	for (int i = LineLength - 1 + iLineNum; i >= iLineDes - 1 + iLineNum; i--) {
		t[i] = t[i - iLineNum];
	}
	if (iLineSource >= iLineDes)
		iLineSource += iLineNum;
	for (int i = 0; i < iLineNum; i++) {
		t[iLineDes + i - 1].Init();
		t[iLineDes + i - 1].StrCopy(t[iLineSource + i - 1]);
	}
	LineLength += iLineNum;
}
void Text::Modify()//�޸�ĳһ�е����ݡ�
{
	int iLinePos = 0;
	cout << "������Ҫ�޸ĵ��кţ�" << endl;
	cin >> iLinePos;
	if (iLinePos<1 || iLinePos>LineLength) {
		cout << "����Ĳ�������" << endl;
		return;
	}
	t[iLinePos - 1].StrPrint();
	cout << "�������޸ĺ�����ݣ�" << endl;
	cin >> str;
	t[iLinePos - 1].StrAssign(str);
}
void Text::Search()
{
	SString strTemp;
	int iPos=0;
	bool bFlag = FALSE;
	char cFlag;
	cout << "������Ҫ���ҵ��ַ�����" << endl;
	cin >> str;
	strTemp.StrAssign(str);
	for (int i = 0; i < LineLength; i++) {
		iPos = 1;
		while (iPos = t[i].Index(strTemp, iPos)) {
			if (iPos) {
				bFlag = TRUE;
				t[i].StrPrint();
				cout << "�ַ���ƥ��ɹ�:�ڵ�" << i + 1 << "��ĵ�" << iPos << "��λ�ó��֡�" << endl;
				cout << "�Ƿ��������?Y/N(Y for yes,and N for no.)" << endl;
				cin >> cFlag;
				if (cFlag == 'N')
					break;
				iPos++;
				bFlag = FALSE;
			}
		}
		i++;
	}
	if (!bFlag) {
		cout << "û���ҵ����ַ�����" << endl;
	}
}
void Text::Replace()//���Ҳ��滻�ַ���
{
	SString strTempSrc,strTempDes;
	int iPos = 0;
	bool bFlag = FALSE;
	char cFlag;
	cout << "������Ҫ���ҵ��ַ�����" << endl;
	cin >> str;
	strTempSrc.StrAssign(str);
	cout << "������Ҫ�滻Ϊ���ַ�����" << endl;
	cin >> str;
	strTempDes.StrAssign(str);
	for (int i = 0; i < LineLength; i++) {
		iPos = 1;
		while (iPos = t[i].Index(strTempSrc, iPos)) {
			bFlag = TRUE;
			t[i].StrPrint();
			cout << "�ַ���ƥ��ɹ�:�ڵ�" << i + 1 << "��ĵ�" << iPos << "��λ�ó��֡�" << endl;
			cout << "�Ƿ��滻��" << endl;
			cin >> cFlag;
			if (cFlag == 'Y') {
				t[i].StrDelete(iPos, strTempSrc.StrLength());
				t[i].StrInsert(strTempDes ,iPos);
			}
			cout << "�Ƿ��������?Y/N(Y for yes,and N for no.)" << endl;
			cin >> cFlag;
			if (cFlag == 'N')
				break;
			iPos++;
		}
		i++;
	}
	if (!bFlag) {
		cout << "û���ҵ����ַ���,�޷�����滻��" << endl;
	}
}
void Text::Save() {
	char *pchar;
	errno_t e;//t
	e = fopen_s(&p,FileName, "w");
	if (e==0) {
		for (int i = 0; i < LineLength; i++) {
			pchar = t[i].StrGet();
			for (int j = 0; j < t[i].StrLength(); j++) {
				fputc(pchar[j], p);
			}
			fputc(10, p);
			t[i].ClearString();
		}
		fclose(p);
	}
	else
		cout << "����ʧ�ܡ�" << endl;
}