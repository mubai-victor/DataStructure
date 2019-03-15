// LInerList_without_head.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Func.h"
#include "Test.h"

using namespace std;

char sta[3][9] = { "���� ", "һ�� ", "��˥��" }; // ����״��(3��)(��ͼ219)
FILE *fp; // ȫ�ֱ���
void Print(stud e)
{ // ��ʾ��¼e������
	printf("%-8s %6ld", e.name, e.num);
	if (e.sex == 'm')
		printf(" ��");
	else
		printf(" Ů");
	printf("%5d %-4s", e.age, e.Class);
	printf("%9s\n", sta[e.health]);
}
void ReadIn(stud &e)
{ // �ɼ�����������Ϣ
	printf("����������(<=%d���ַ�): ", NAMELEN);
	scanf("%s", e.name);
	printf("������ѧ��: ");
	scanf("%ld", &e.num);
	printf("�������Ա�(m:�� f:Ů): ");
	scanf("%*c%c", &e.sex);
	printf("����������: ");
	scanf("%d", &e.age);
	printf("������༶(<=%d���ַ�): ", CLASSLEN);
	scanf("%s", e.Class);
	printf("�����뽡��״��(0:%s 1:%s 2:%s):", sta[0], sta[1], sta[2]);
	scanf("%d", &e.health);
}
void WriteToFile(stud e)
{ // �������Ϣд��fpָ�����ļ�
	fwrite(&e, sizeof(stud), 1, fp);
}
Status ReadFromFile(stud &e)
{ // ��fpָ�����ļ���ȡ�����Ϣ��e
	int i;
	i = fread(&e, sizeof(stud), 1, fp);
	if (i == 1) // ��ȡ�ļ��ɹ�
		return OK;
	else
		return ERROR;
}
int cmp(ElemType c1, ElemType c2)
{
	return (int)(c1.num - c2.num);
}
void Modify(LinkList &L, ElemType e)
{ // �޸Ľ�����ݣ�����ѧ�Ž����ǽ����������L
	char s[80];
	Print(e); // ��ʾԭ����
	printf("��������޸�������ݣ����޸ĵ���س�������ԭֵ:\n");
	printf("����������(<=%d���ַ�): ", NAMELEN);
	gets(s);
	if (strlen(s))
		strcpy(e.name, s);
	printf("������ѧ��: ");
	gets(s);
	if (strlen(s))
		e.num = atol(s);
	printf("�������Ա�(m:�� f:Ů): ");
	gets(s);
	if (strlen(s))
		e.sex = s[0];
	printf("����������: ");
	gets(s);
	if (strlen(s))
		e.age = atoi(s);
	printf("������༶(<=%d���ַ�): ", CLASSLEN);
	gets(s);
	if (strlen(s))
		strcpy(e.Class, s);
	printf("�����뽡��״��(0:%s 1:%s 2:%s):", sta[0], sta[1], sta[2]);
	gets(s);
	if (strlen(s))
		e.health = atoi(s); // �޸����
	InsertAscend(L, e, cmp); // ��q��ָ�������ݰ�ѧ�ŷǽ������L(func2-1.cpp)
}
#define N 4 // student��¼�ĸ���
Status EqualNum(ElemType c1, ElemType c2)
{
	if (c1.num == c2.num)
		return OK;
	else
		return ERROR;
}
Status EqualName(ElemType c1, ElemType c2)
{
	if (strcmp(c1.name, c2.name))
		return ERROR;
	else
		return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{

	//LinkList L;
	//ElemType e, e0;
	//Status i;
	//int j, k;
	//InitList(L);
	//for (j = 1; j <= 5; j++)
	//{
	//	i = ListInsert(L, 1, j);
	//	if (!i) // ����ʧ��
	//		exit(ERROR);
	//}
	//printf("��L�ı�ͷ���β���1��5�� L=");
	//ListTraverse(L, print); // ���ζ�Ԫ�ص���print()�����Ԫ�ص�ֵ

	//i = ListEmpty(L);
	//printf("L�Ƿ�գ� i=%d(1:�� 0:��)\n", i);
	//ClearList(L);//////////////////////////////////////////
	//printf("���L�� L=");
	//ListTraverse(L, print);
	//i = ListEmpty(L);
	//printf("L�Ƿ�գ� i=%d(1:�� 0:��)\n", i);
	//for (j = 1; j <= 10; j++)
	//	ListInsert(L, j, j);
	//printf("��L�ı�β���β���1��10�� L=");//getchar();
	//ListTraverse(L, print);	
	//i = GetElem(L, 5, e);
	//if (i == OK)
	//	printf("��5��Ԫ�ص�ֵΪ%d\n", e);
	//for (j = 0; j <= 1; j++)
	//{
	//	k = LocateElem(L, j, equal);
	//	if (k)
	//		printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
	//	else
	//		printf("û��ֵΪ%d��Ԫ��\n", j);
	//}
	//for (j = 1; j <= 2; j++) // ����ͷ��������
	//{
	//	GetElem(L, j, e0); // �ѵ�j�����ݸ���e0
	//	i = PriorElem(L, e0, e); // ��e0��ǰ��
	//	if (i == INFEASIBLE)
	//		printf("Ԫ��%d��ǰ��\n", e0);
	//	else
	//		printf("Ԫ��%d��ǰ��Ϊ%d\n", e0, e);
	//}
	//for (j = ListLength(L) - 1; j <= ListLength(L); j++) // �����������
	//{
	//	GetElem(L, j, e0); // �ѵ�j�����ݸ���e0
	//	i = NextElem(L, e0, e); // ��e0�ĺ��
	//	if (i == INFEASIBLE)
	//		printf("Ԫ��%d�޺��\n", e0);
	//	else
	//		printf("Ԫ��%d�ĺ��Ϊ%d\n", e0, e);
	//}
	//k = ListLength(L); // kΪ��
	//for (j = k + 1; j >= k; j--)
	//{
	//	i = ListDelete(L, j, e); // ɾ����j������
	//	if (i == ERROR)
	//		printf("ɾ����%d��Ԫ��ʧ��\n", j);
	//	else
	//		printf("ɾ����%d��Ԫ�سɹ�����ֵΪ%d\n", j, e);
	//}
	//printf("�������L��Ԫ�أ� ");
	//ListTraverse(L, print); 
	//DestroyList(L);
	//printf("����L�� L=%u\n", L);
	stud student[N] = { { "��С��", 790631, 'm', 18, "��91", 0 }, { "�º�", 790632, 'f', 20, "��91", 1 },
	{ "����ƽ", 790633, 'm', 21, "��91", 0 }, { "������", 790634, 'm', 17, "��91", 2 } };
	int i, j, flag = 1;
	char filename[13];
	ElemType e;
	LinkList T, p, q;
	InitList(T); // ��ʼ������
	while (flag)
	{
		printf("1:���ṹ������student�еļ�¼��ѧ�ŷǽ����������\n");
		printf("2:���ļ��еļ�¼��ѧ�ŷǽ����������\n");
		printf("3:���������¼�¼�������䰴ѧ�ŷǽ����������\n");
		printf("4:ɾ�������е�һ���и���ѧ�ŵļ�¼\n");
		printf("5:ɾ�������е�һ���и��������ļ�¼\n");
		printf("6:�޸������е�һ���и���ѧ�ŵļ�¼\n");
		printf("7:�޸������е�һ���и��������ļ�¼\n");
		printf("8:���������е�һ���и���ѧ�ŵļ�¼\n");
		printf("9:���������е�һ���и��������ļ�¼\n");
		printf("10:��ʾ���м�¼ 11:�������е����м�¼�����ļ� 12:����\n");
		printf("��ѡ���������: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1: for (j = 0; j<N; j++)
			InsertAscend(T, student[j], cmp); // ��func2-1.cpp��
			break;
		case 2: printf("�������ļ���: ");
			scanf("%s", filename);
			if ((fp = fopen(filename, "rb")) == NULL)
				printf("���ļ�ʧ��!\n");
			else
			{
				while (ReadFromFile(e))
					InsertAscend(T, e, cmp); // ��func2-1.cpp��
				fclose(fp);
			}
			break;
		case 3: ReadIn(e);
			InsertAscend(T, e, cmp); // ��func2-1.cpp��
			break;
		case 4: printf("�������ɾ����¼��ѧ��: ");
			scanf("%ld", &e.num);
			if (!DeleteElem(T, e, EqualNum)) // ��func2-1.cpp��
				printf("û��ѧ��Ϊ%ld�ļ�¼\n", e.num);
			break;
		case 5: printf("�������ɾ����¼������: ");
			scanf("%*c%s", e.name); // %*c�Ե��س���
			if (!DeleteElem(T, e, EqualName)) // ��func2-1.cpp��
				printf("û������Ϊ%s�ļ�¼\n", e.name);
			break;
		case 6: printf("��������޸ļ�¼��ѧ��: ");
			scanf("%ld%*c", &e.num);
			if (!DeleteElem(T, e, EqualNum)) // ��������ɾ���ý�㣬����e����(func2-1.cpp)
				printf("û��ѧ��Ϊ%ld�ļ�¼\n", e.num);
			else
				Modify(T, e); // �޸�e����ѧ�Ų�������T
			break;
		case 7: printf("��������޸ļ�¼������: ");
			scanf("%*c%s%*c", e.name); // %*c�Ե��س���
			if (!DeleteElem(T, e, EqualName)) // ��func2-1.cpp��
				printf("û������Ϊ%s�ļ�¼\n", e.name);
			else
				Modify(T, e);
			break;
		case 8: printf("����������Ҽ�¼��ѧ��: ");
			scanf("%ld", &e.num);
			if (!(q = Point(T, e, EqualNum, p))) // ��func2-1.cpp��
				printf("û��ѧ��Ϊ%ld�ļ�¼\n", e.num);
			else
				Print(q->data);
			break;
		case 9: printf("����������Ҽ�¼������: ");
			scanf("%*c%s", e.name);
			if (!(q = Point(T, e, EqualName, p))) // ��func2-1.cpp��
				printf("û������Ϊ%s�ļ�¼\n", e.name);
			else
				Print(q->data);
			break;
		case 10:printf(" ���� ѧ�� �Ա� ���� �༶ ����״��\n");
			ListTraverse(T, Print);
			break;
		case 11:printf("�������ļ���: ");
			scanf("%s", filename);
			if ((fp = fopen(filename, "wb")) == NULL)
				printf("���ļ�ʧ��!\n");
			else
				ListTraverse(T, WriteToFile);
			fclose(fp);
			break;
		case 12:flag = 0;
		}
	}
	getchar();
	return 0;
}

