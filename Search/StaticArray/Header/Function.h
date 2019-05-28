#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

typedef long KeyType;

#define key number
#define N 5


struct ElemType // ����Ԫ������(�Խ̿���ͼ9.1�߿��ɼ�Ϊ��)
{
	long number; // ׼��֤�ţ���ؼ�������ͬ
	char name[9]; // ����(4�����ּ�1����������־)
	int politics; // ����
	int Chinese; // ����
	int English; // Ӣ��
	int math; // ��ѧ
	int physics; // ����
	int chemistry; // ��ѧ
	int biology; // ����
	int total; // �ܷ�
};
class SStable {
private:
	ElemType *elem;
	int length;
public:
	SStable();
	void Create_Seq(ElemType table[],int n);
	void Ascend();
	void Create_Ord(ElemType table[], int n);
	int Search_Seq(KeyType key);
	int Search_Bin(KeyType key);
	void Traverse(void(*Func)(ElemType elem));
	void Print(int i,void(*Func)(ElemType elem));
};

void print(ElemType elem);
#endif