// Editor_Line.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
FILE *fp;
int main()
{
	fopen_s(&fp,"ed.txt", "w"); // �ڵ�ǰĿ¼�½���ed.txt�ļ�������д���ݣ�
	if (fp) // ������ͬ���ļ�����ɾ��ԭ�ļ�
	{
		LineEdit();
		fclose(fp); // �ر�fp��ָ���ļ�
	}
	else
		printf("�����ļ�ʧ��!\n");
	return 0;
}

