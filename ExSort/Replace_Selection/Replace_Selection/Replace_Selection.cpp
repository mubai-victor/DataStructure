// Replace_Selection.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	RedType b, a[N] = { { 51,1 },{ 49,2 },{ 39,3 },{ 46,4 },{ 38,5 },{ 29,6 },{ 14,7 },{ 61,8 },{ 15,9 },{ 30,10 },
	{ 1,11 },{ 48,12 },{ 52,13 },{ 3,14 },{ 63,15 },{ 27,16 },{ 4,17 },{ 13,18 },{ 89,19 },
	{ 24,20 },{ 46,21 },{ 58,22 },{ 33,23 },{ 76,24 } };
	FILE *fi, *fo;
	LoserTree ls;
	WorkArea wa;
	int i, k, j = INT_MAX;
	char s[3], fname[4];
	fo = fopen("ori", "wb"); // ��д�ķ�ʽ�򿪴��ļ�ori
	fwrite(a, sizeof(RedType), N, fo); // ������aд����ļ�ori
	fclose(fo);
	fi = fopen("ori", "rb"); // �Զ��ķ�ʽ���´򿪴��ļ�ori
	printf("���ļ��ļ�¼Ϊ\n");
	for (i = 1; i <= N; i++)
	{
		fread(&b, sizeof(RedType), 1, fi); // ���ν����ļ�ori�����ݶ���b
		print(b); // ���b������
		if (i%M == 0)
			printf("\n");
	}
	printf("\n");
	rewind(fi); // ʹfi��ָ�����·��ش��ļ�ori����ʼλ�ã��Ա����¶����ڴ棬������������ļ�
	fo = fopen("out", "wb"); // ��д�ķ�ʽ�򿪳�ʼ�鲢���ļ�out
	Replace_Selection(ls, wa, fi, fo); // ���û���ѡ���������ʼ�鲢��
	fclose(fo);
	fclose(fi);
	fi = fopen("out", "rb"); // �Զ��ķ�ʽ���´򿪳�ʼ�鲢���ļ�out
	printf("��ʼ�鲢���ļ��ļ�¼Ϊ\n");
	i = 1;
	do
	{
		k = fread(&b, sizeof(RedType), 1, fi); // ���ν����ļ�out�����ݶ���b
		if (k == 1)
		{
			print(b); // ���b������
			if (i++%M == 0)
				printf("\n");
		}
	} while (k == 1);
	printf("\n");
	rewind(fi); // ʹfi��ָ�����·��ش��ļ�ori����ʼλ�ã��Ա����¶����ڴ棬������������ļ�
	k = 0;
	while (!feof(fi)) // ���������ʼ�鲢���ļ�out
	{
		_itoa(k, s, 10); // ���������ļ���f0��f1����
		strcpy(fname, "f");
		strcat(fname, s);
		fo = fopen(fname, "wb"); // ������д�ķ�ʽ���ļ�f0��f1����
		do
		{
			i = fread(&b, sizeof(RedType), 1, fi);
			if (i == 1) // fread()���óɹ�
			{
				fwrite(&b, sizeof(RedType), 1, fo); // ��bд���ļ�f0��f1����
				if (b.key == j) // 1���鲢�ν���
				{
					k++;
					fclose(fo);
					break;
				}
			}
		} while (i == 1);
	};	fclose(fi);
	printf("������%d����ʼ�鲢���ļ�\n", k);
    return 0;
}

