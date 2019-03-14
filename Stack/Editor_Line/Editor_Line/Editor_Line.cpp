// Editor_Line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
FILE *fp;
int main()
{
	fopen_s(&fp,"ed.txt", "w"); // 在当前目录下建立ed.txt文件，用于写数据，
	if (fp) // 如已有同名文件则先删除原文件
	{
		LineEdit();
		fclose(fp); // 关闭fp所指的文件
	}
	else
		printf("建立文件失败!\n");
	return 0;
}

