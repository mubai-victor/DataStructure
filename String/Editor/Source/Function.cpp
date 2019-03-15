
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
char* SString::StrGet() {
	return str;
}


Text::Text()
{
	p = NULL;
	LineLength = 0;
}
void Text::Open()//打开文件，将文件的内容读E:\入到t中去。
{
	errno_t e;
	if (FileName[0])
		cout << "文件已经打开过。" << endl;
	else {
		cout << "请输入文件名字，包含路径，字长限制在20个字以内：" << endl;
		getchar();
		gets_s(FileName,NAME_LEN);
		e = fopen_s(&p,FileName, "r");
		if (e==0) {
			while (fgets(str, LINE_LEN, p)!=NULL) {
				if (LineLength >= MAX_LINE) {
					cout << "文件太大。" << endl;
					break;
				}
				str[strlen(str) - 1] = '\0';
				t[LineLength].StrAssign(str);
				LineLength ++;
			}
			fclose(p);
		}
		else {
			cout << "这是一个新文件。" << endl;
		}
	}
}
void Text::List() //显示文件中的内容
{
	for (int i = 0; i < LineLength; i++) {
		t[i].StrPrint();
	}
}
void Text::Insert()//插入行。
{
	int iLinePos = 0, iLineNum = 0;
	cout << "在l行之前插入m行，请输入l,m:" << endl;
	cin >> iLinePos >> iLineNum;getchar();
	if (iLinePos > LineLength || iLinePos<1 || LineLength + iLineNum>MAX_LINE) {
		cout << "输入有误." << endl;
		return;
	}
	for (int i = LineLength - 1 + iLineNum; i >= iLinePos - 1 + iLineNum; i--) {
		t[i] = t[i - iLineNum];
	}
	cout << "请输入待插入的内容。" << endl;
	for (int i = iLinePos - 1; i < iLinePos - 1 + iLineNum; i++) {
		
		gets_s(str);
		t[i].Init();
		t[i].StrAssign(str);
	}
	LineLength += iLineNum;
}
void Text::Delete()//删除行
{
	int iLinePos = 0, iLineNum = 0;
	cout << "从l行开始删除m行，请输入l,m：" << endl;
	cin >> iLinePos >> iLineNum;
	if (iLinePos<1 || iLinePos>LineLength || iLinePos + iLineNum - 1 > LineLength) {
		cout << "输入的参数有误。" << endl;
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
void Text::Copy()//复制行的内容
{
	int iLineSource = 0, iLineDes = 0, iLineNum = 0;
	cout << "把从m开始的l行复制到n之前，请输入m,l,n:" << endl;
	cin >> iLineSource >> iLineNum >> iLineDes;
	if (iLineSource<1 || iLineSource + iLineNum - 1>LineLength || iLineDes > LineLength + 1 || LineLength + iLineNum > MAX_LINE) {
		cout << "输入的参数有误：" << endl;
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
void Text::Modify()//修改某一行的内容。
{
	int iLinePos = 0;
	cout << "请输入要修改的行号：" << endl;
	cin >> iLinePos;
	if (iLinePos<1 || iLinePos>LineLength) {
		cout << "输入的参数有误。" << endl;
		return;
	}
	t[iLinePos - 1].StrPrint();
	cout << "请输入修改后的内容：" << endl;
	cin >> str;
	t[iLinePos - 1].StrAssign(str);
}
void Text::Search()
{
	SString strTemp;
	int iPos=0;
	bool bFlag = FALSE;
	char cFlag;
	cout << "请输入要查找的字符串。" << endl;
	cin >> str;
	strTemp.StrAssign(str);
	for (int i = 0; i < LineLength; i++) {
		iPos = 1;
		while (iPos = t[i].Index(strTemp, iPos)) {
			if (iPos) {
				bFlag = TRUE;
				t[i].StrPrint();
				cout << "字符串匹配成功:在第" << i + 1 << "句的第" << iPos << "个位置出现。" << endl;
				cout << "是否继续查找?Y/N(Y for yes,and N for no.)" << endl;
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
		cout << "没有找到该字符串。" << endl;
	}
}
void Text::Replace()//查找并替换字符串
{
	SString strTempSrc,strTempDes;
	int iPos = 0;
	bool bFlag = FALSE;
	char cFlag;
	cout << "请输入要查找的字符串。" << endl;
	cin >> str;
	strTempSrc.StrAssign(str);
	cout << "请输入要替换为的字符串。" << endl;
	cin >> str;
	strTempDes.StrAssign(str);
	for (int i = 0; i < LineLength; i++) {
		iPos = 1;
		while (iPos = t[i].Index(strTempSrc, iPos)) {
			bFlag = TRUE;
			t[i].StrPrint();
			cout << "字符串匹配成功:在第" << i + 1 << "句的第" << iPos << "个位置出现。" << endl;
			cout << "是否替换？" << endl;
			cin >> cFlag;
			if (cFlag == 'Y') {
				t[i].StrDelete(iPos, strTempSrc.StrLength());
				t[i].StrInsert(strTempDes ,iPos);
			}
			cout << "是否继续查找?Y/N(Y for yes,and N for no.)" << endl;
			cin >> cFlag;
			if (cFlag == 'N')
				break;
			iPos++;
		}
		i++;
	}
	if (!bFlag) {
		cout << "没有找到该字符串,无法完成替换。" << endl;
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
		cout << "存盘失败。" << endl;
}