#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "stdio.h"

using namespace std;
#define Destroystring ClearString;
SString::SString()
{
	length = 0;
	head=tail=NULL;
}
Status SString::StrAssign(char *chars)
{
	int len = strlen(chars);
	int blocks;
	Chunk *front=NULL, *back=NULL;
	if (len == 0|| strchr(chars,BLANK)) {
		return	ERROR;
	}
	if (length)
		DestroyString();
	blocks = len / CHUNK_SIZE;
	if ((len % CHUNK_SIZE))
		blocks++;	
	for (int i = 0,j=0; i < blocks; i++) {
		front = new Chunk;
		for (int k = 0; k < CHUNK_SIZE&&chars[k + i*CHUNK_SIZE]; k++) {
			front->ch[k] = chars[k + i*CHUNK_SIZE];
		}
		if (i == 0) {
			head = front;
			back = front;
		}
		else {			
			back->next = front;
			back = front;			
		}
	}
	back->next = NULL;
	tail = back;
	length = len;
	return OK;
}
Status SString::StrCopy(const SString &S)
{
	int len = S.length;
	if (length)
		ClearString();
	char*temp;
	int status = S.ToChars(temp);
	StrAssign(temp);
	return status;
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
	int result;
	char*str1, *str2;
	ToChars(str1);
	S.ToChars(str2);
	result = strcmp(str1, str2);
	delete[] str1;
	delete[] str2;
	return result;
}
int SString::StrLength()
{
	return length;
}
void SString::ClearString()
{
	length = 0;
	while (head) {
		tail = head->next;
		delete[] head;
		head = tail;
	}
	head = tail = NULL;
}
Status SString::Concat(SString L, SString &S)
{
	int len = length + L.length;
	int i=0;
	if (S.length)
		S.DestroyString();
	char *temp1, *temp2, *temp3;
	if (ToChars(temp1)==ERROR || L.ToChars(temp2)==ERROR || !(temp3 = new char[len + 1]))
		return ERROR;
	for (i = 0; i < length; i++) {
		temp3[i] = temp1[i];
	}
	for (; i < len; i++) {
		temp3[i] = temp2[i - length];
	}
	temp3[len] = '\0';
	S.StrAssign(temp3);
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	return OK;
}
Status SString::SubString(SString &Sub, int pos, int len)
{// 用Sub返回串S的自第pos个字符起长度为len的子串。
	if (pos<1 || pos>length)
		return ERROR;
	if (Sub.length)
		Sub.DestroyString();
	char*temp1, *temp2;
	ToChars(temp1);
	temp2 = new char[len + 1];
	for (int i = pos-1; i < len + pos - 1; i++) {
		temp2[i - pos + 1] = temp1[i];
	}
	temp2[len] = '\0';
	Sub.StrAssign(temp2);
	delete[] temp1;
	delete[] temp2;
	return OK;
}
int SString::Index(SString S, int pos)// 返回子串S在主串中第pos个字符之后的位置。若不存在，则函数值为0。
// 其中， T非空， 1≤pos≤StrLength(S)。算法4.5
{
	if ((1 > pos) || (pos > length - S.length + 1))
		return 0;	
	SString sub;
	int len = S.length;
	for (int i = pos; i < length - len + 1; i++) {
		SubString(sub, i, len);
		if (sub.StrCompare(S) == 0) {
			sub.DestroyString();
			return i;
		}
	}
	return 0;
}
Status SString::StrInsert(SString &S, int pos)
{// 初始条件：串S存在， 1≤pos≤StrLength(S)+1
// 操作结果：在主串第pos个字符之前插入串S。
	if (pos<1 || pos>length + 1)
		return ERROR;
	int len = length + S.length;
	char *temp1,*temp2,*temp3 = new char[len + 1];
	ToChars(temp1);
	S.ToChars(temp2);
	for (int i = 0; i < pos - 1; i++) {
		temp3[i] = temp1[i];
	}
	for (int i = pos - 1; i < pos + S.length - 1; i++) {
		temp3[i] = temp2[i - pos + 1]; 
	}
	for (int i = pos + S.length - 1; i < len; i++) {
		temp3[i] = temp1[i - S.length];
	}
	temp3[len] = '\0';
	DestroyString();
	StrAssign(temp3);
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	return OK;
}
Status SString::StrDelete(int pos, int len)
{// 初始条件：串S存在， 1≤pos≤StrLength(S)-len+1
// 操作结果：从串S中删除自第pos个字符起长度为len的子串
	if (pos<1 || pos>length - len + 1)
		return ERROR;
	char *temp1=new char[length - len + 1],*temp2;
	ToChars(temp2);
	for (int i = pos-1; i < length; i++)
		temp2[i] = temp2[i + len];
	for (int i = 0; i < length - len; i++) {
		temp1[i] = temp2[i];
	}
	temp1[length - len] = '\0';
	DestroyString();
	StrAssign(temp1);
	delete[] temp1;
	delete[] temp2;
	return OK;
}
Status SString::Replace(SString &S, SString &T)
{// 初始条件：串S， T和V存在， T是非空串
// 操作结果：用T替换主串中出现的所有与S相等的不重叠的子串
	if (T.length == 0 || S.length == 0)
		return ERROR;
	int pos = 1; 
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
	char *temp;
	ToChars(temp);
	cout << temp << endl;

}
Status SString::ToChars(char *&chars)const
{
	chars = new char[length + 1];
	int curs = 0;
	Chunk *pos=NULL;
	pos = head;
	if (!(chars = new char[length + 1]))
		return ERROR;
	for (int i = 0; i < length; ) {
		for (int j = 0; j < CHUNK_SIZE&&i<length; j++,i++) {
			chars[i] = pos->ch[j];
		}
		pos = pos->next;
	}
	chars[length] = '\0';
	return OK;
}