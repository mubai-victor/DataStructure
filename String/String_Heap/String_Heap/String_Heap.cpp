// String_Heap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;

int main()
{
	int i, j;
	Status k;
	char s, c[40 + 1];
	SString t, s1, s2;
	printf("请输入串s1: ");
	gets_s(c);
	s1.StrAssign(c);
	printf("串长为%d 串空否？ %d(1:是 0:否)\n", s1.StrLength(), s1.StrEmpty());
	s2.StrCopy(s1);
	printf("拷贝s1生成的串为");
	s2.StrPrint();
	printf("请输入串s2: ");
	gets_s(c);
	s2.StrAssign(c);
	i = s1.StrCompare(s2);
	if (i<0)
		s = '<';
	else if (i == 0)
		s = '= ';
	else
		s = '>';
	printf("串s1%c串s2\n", s);
	s1.Concat(s2, t);
	printf("串s1联接串s2得到的串t为");
	t.StrPrint();
	s1.ClearString();
	printf("清为空串后,串s1为");
	s1.StrPrint();
	printf("串长为%d 串空否？ %d(1:是 0:否)\n", s1.StrLength(), s1.StrEmpty());
	printf("求串t的子串,请输入子串的起始位置,子串长度: ");
	cin >> i >> j;
	//	scanf_s("%d,%d", &i,&j);
	k = t.SubString(s2, i, j);
	if (k == OK)
	{
		printf("子串s2为");
		s2.StrPrint();
	}
	printf("从串t的第pos个字符起,删除len个字符，请输入pos,len: ");
	cin >> i >> j;
	t.StrDelete(i, j);
	printf("删除后的串t为");
	t.StrPrint();
	i = s2.StrLength() / 2;
	s2.StrInsert(t, i);
	printf("在串s2的第%d个字符之前插入串t后,串s2为\n", i);
	s2.StrPrint();
	i = s2.Index(t, 1);
	printf("s2的第%d个字母起和t第一次匹配\n", i);
	s2.SubString(t, 1, 1);
	printf("串t为");
	t.StrPrint();
	t.Concat(t, s1);
	printf("串s1为");
	s1.StrPrint();
	k = s2.Replace(t, s1);
	if (k==OK) // 替换成功
	{
		printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为");
		s2.StrPrint();
	}
	s2.DestroyString(); // 销毁操作同清空 
	s1.DestroyString();
	t.DestroyString();
	return 0;
}

