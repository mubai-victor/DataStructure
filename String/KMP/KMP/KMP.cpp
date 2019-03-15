// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;

int main()
{
	int i, *p;
	SString s1, s2; // 以教科书算法4.8之上的数据为例
	s1.StrAssign("aaabaaaab");
	printf("主串为");
	s1.StrPrint();
	s2.StrAssign("aaaab");
	printf("子串为");
	s2.StrPrint();
	s2.GetNext(); // 利用算法4.7，求得next数组，存于p中
	printf("子串的next数组为");
	s2.PrintNext();
	i = s1.Index_KMP(s2, 1); // 利用算法4.6求得串s2在s1中首次匹配的位置i
	if (i)
		printf("主串和子串在第%d个字符处首次匹配\n", i);
	else
		printf("主串和子串匹配不成功\n");
	s2.GetNextval(); // 利用算法4.8，求得next数组，存于p中
	printf("子串的nextval数组为");
	s2.PrintNext();
	printf("主串和子串在第%d个字符处首次匹配\n", s1.Index_KMP(s2, 1));
	return 0;
}

