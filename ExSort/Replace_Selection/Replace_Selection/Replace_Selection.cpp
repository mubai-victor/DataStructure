// Replace_Selection.cpp : 定义控制台应用程序的入口点。
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
	fo = fopen("ori", "wb"); // 以写的方式打开大文件ori
	fwrite(a, sizeof(RedType), N, fo); // 将数组a写入大文件ori
	fclose(fo);
	fi = fopen("ori", "rb"); // 以读的方式重新打开大文件ori
	printf("大文件的记录为\n");
	for (i = 1; i <= N; i++)
	{
		fread(&b, sizeof(RedType), 1, fi); // 依次将大文件ori的数据读入b
		print(b); // 输出b的内容
		if (i%M == 0)
			printf("\n");
	}
	printf("\n");
	rewind(fi); // 使fi的指针重新返回大文件ori的起始位置，以便重新读入内存，产生有序的子文件
	fo = fopen("out", "wb"); // 以写的方式打开初始归并段文件out
	Replace_Selection(ls, wa, fi, fo); // 用置换－选择排序求初始归并段
	fclose(fo);
	fclose(fi);
	fi = fopen("out", "rb"); // 以读的方式重新打开初始归并段文件out
	printf("初始归并段文件的记录为\n");
	i = 1;
	do
	{
		k = fread(&b, sizeof(RedType), 1, fi); // 依次将大文件out的数据读入b
		if (k == 1)
		{
			print(b); // 输出b的内容
			if (i++%M == 0)
				printf("\n");
		}
	} while (k == 1);
	printf("\n");
	rewind(fi); // 使fi的指针重新返回大文件ori的起始位置，以便重新读入内存，产生有序的子文件
	k = 0;
	while (!feof(fi)) // 按段输出初始归并段文件out
	{
		_itoa(k, s, 10); // 依次生成文件名f0，f1，…
		strcpy(fname, "f");
		strcat(fname, s);
		fo = fopen(fname, "wb"); // 依次以写的方式打开文件f0，f1，…
		do
		{
			i = fread(&b, sizeof(RedType), 1, fi);
			if (i == 1) // fread()调用成功
			{
				fwrite(&b, sizeof(RedType), 1, fo); // 将b写入文件f0，f1，…
				if (b.key == j) // 1个归并段结束
				{
					k++;
					fclose(fo);
					break;
				}
			}
		} while (i == 1);
	};	fclose(fi);
	printf("共产生%d个初始归并段文件\n", k);
    return 0;
}

