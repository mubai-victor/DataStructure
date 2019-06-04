// Hash.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{

	ElemType r[N] = { { 17,1 },{ 60,2 },{ 29,3 },{ 38,4 },{ 1,5 },{ 2,6 },{ 3,7 },{ 4,8 },{ 60,9 },{ 13,10 } };
	HashTable h;
	int i, p;
	Status j;
	KeyType k;
	h.InitHashTable();
	for (i = 0; i<N - 1; i++)
	{ // ����ǰN-1����¼
		j = h.InsertHash(r[i]);
		if (j == DUPLICATE)
			printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n", r[i].key, r[i].key,
				r[i].ord);
	}
	printf("����ϣ��ַ��˳�������ϣ��:\n");
	h.TraverseHash(print);
	printf("����������Ҽ�¼�Ĺؼ���: ");
	cin >> k;
	j = h.Find(k, p);
	if (j == SUCCESS)
		h.Print(p);
	else
		printf("û�ҵ�\n");
	j = h.InsertHash(r[i]); // �����N����¼
	if (j == ERROR) // �ؽ���ϣ��
		j = h.InsertHash(r[i]); // �ؽ���ϣ������²���
	printf("����ϣ��ַ��˳������ؽ���Ĺ�ϣ��:\n");
	h.TraverseHash(print);
	printf("����������Ҽ�¼�Ĺؼ���: ");
	cin >> k;
	j = h.Find(k, p);
	if (j == SUCCESS)
		h.Print(p);
	else
		printf("û�ҵ�\n");
	h.DestroyHashTable();
    return 0;
}

