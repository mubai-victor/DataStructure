// StaticArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;

int main()
{
#ifdef ORDER
	SStable st;
	int i;
	KeyType s;
	ElemType r[N] = { 5,13,19,21,37,56,64,75,80,88,92 }; // ����Ԫ��(�Խ̿����219ҳ������Ϊ��)
	st.Create_Ord(r, N); // ��ȫ����������ǽ���̬���ұ�st
	st.Traverse(print); // ˳������ǽ���̬���ұ�st
	printf("\n");
	printf("�����������ֵ�Ĺؼ���: ");
	cin >> s;
	i = st.Search_Bin(s); // �۰���������
	if (i)
		st.Print(i, print);
	else
		printf("û�ҵ�\n");
#else
	ElemType r[N] = { { 179328,"�η���",85,89,98,100,93,80,47 },
	{ 179325,"�º�",85,86,88,100,92,90,45 },
	{ 179326,"½��",78,75,90,80,95,88,37 },
	{ 179327,"��ƽ",82,80,78,98,84,96,40 },
	{ 179324,"��С��",76,85,94,57,77,69,44 } }; // ���鲻���ؼ�������
	SStable st;
	int i;
	long s;
	for (i = 0; i<N; i++) // �����ܷ�
		r[i].total = r[i].politics + r[i].Chinese + r[i].English + r[i].math + r[i].physics +
		r[i].chemistry + r[i].biology;
	st.Create_Seq(r, N); // ������r����˳��̬���ұ�st
	printf("׼��֤�� ���� ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�\n");
	st.Traverse(print); // ��˳�������̬���ұ�st
	printf("������������˵Ŀ���: ");
	/*scanf("%ld", &s);*/
	cin >> s;
	i = st.Search_Seq(s); // ˳�����
	if (i)
		st.Print(i, print);
	else
		printf("û�ҵ�\n");
#endif
    return 0;
}

