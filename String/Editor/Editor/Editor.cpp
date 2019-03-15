// Editor.cpp : 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Test.h"
#include "Function.h"
using namespace std;

int main()
{
	Status s = TRUE;
	Text t;
	int i, k;
	errno_t e;
	char temp[30];
	char *flag;
	FILE*p=NULL;
	//e = fopen_s(&p, "text.txt", "w");
	//fputs("hello,world.", p);
	//fclose(p);
	//e = fopen_s(&p, "text.txt", "r");
	//if (e == 0)
	//	flag = fgets(temp, 30, p);
	//	cout << temp << endl;;
	//fclose(p);
	while (s)
	{
		printf("请选择: 1.打开文件(新或旧) 2.显示文件内容\n");
		printf(" 3.插入行 4.删除行 5.拷贝行 6.修改行\n");
		printf(" 7.查找字符串 8.替换字符串\n");
		printf(" 9.存盘退出 0.放弃编辑\n");
		cin >> k;
		switch (k)
		{
		case 1: t.Open();
			break;
		case 2: t.List();
			break;
		case 3: t.Insert();
			break;
		case 4: t.Delete();
			break;
		case 5: t.Copy();
			break;
		case 6: t.Modify();
			break;
		case 7: t.Search();
			break;
		case 8: t.Replace();
			break;
		case 9: t.Save();
		case 0: s = FALSE;
		}
	}
	return 0;
}

