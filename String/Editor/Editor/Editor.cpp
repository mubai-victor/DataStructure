// Editor.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("��ѡ��: 1.���ļ�(�»��) 2.��ʾ�ļ�����\n");
		printf(" 3.������ 4.ɾ���� 5.������ 6.�޸���\n");
		printf(" 7.�����ַ��� 8.�滻�ַ���\n");
		printf(" 9.�����˳� 0.�����༭\n");
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

