#include "Function.h"
#include "Test.h"

void difference(SLinkList L, int&head)
{
	int count_a = 0, count_b = 0, cur = 0, cur_temp, tail, cur_back;
	Elemtype elem;
	InitSpace(L);
	tail=head = InitList(L);
	printf("���뼯��A�ͼ���B��Ԫ������,���ŷָ���\n");
	scanf("%d,%d*c", &count_a,&count_b);
	printf("���뼯��AԪ�أ�\n");scanf("%*c"); 
	for (int i = 0; i < count_a; i++){
		cur_temp = Malloc(L);
		if (!cur_temp)
			printf("ERROR.\n");
		scanf("%c", &L[cur_temp].data);
		L[tail].cur = cur_temp;
		tail = cur_temp;
	}
	L[tail].cur = 0;
	scanf("%*c"); 
	ListTraverse(L, head, print2);
	printf("���뼯��BԪ�أ�\n");
	for (int i = 0; i < count_b; i++){			
		scanf("%c", &elem);
//		printf("elem=%c��\n",elem);
		cur_back = L[head].cur;
		cur = head;
		while (L[tail].cur!=cur_back&&L[cur_back].data != elem){
			cur = cur_back;
			cur_back = L[cur_back].cur;//printf("ERROR.\n");
		}
		if (L[tail].cur == cur_back){
			cur_temp = Malloc(L);
			L[cur_temp].data = elem;
			L[cur_temp].cur = L[tail].cur;
			L[tail].cur = cur_temp;
		}
		else{
			L[cur].cur = L[cur_back].cur;
			Free(L, cur_back);
			if (cur_back == tail)
				tail = cur_back;
		}
	}
	printf("finished.");
}
//void difference(SLinkList space, int &S) // �㷨2.17
//{ // �������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A-B)��(B-A)
//	// �ľ�̬���� SΪ��ͷָ�롣���豸�ÿռ��㹻�� space[0].curΪ���ÿռ��ͷָ��
//	int r, p, m, n, i, j, k;
//	ElemType b;
//	InitSpace(space); // ��ʼ�����ÿռ�
//	S = Malloc(space); // ����S��ͷ���
//	r = S; // rָ��S�ĵ�ǰ�����
//	printf("�����뼯��A��B��Ԫ�ظ���m,n:");
//	scanf("%d,%d%*c", &m, &n); // %*c�Ե��س���
//	printf("�����뼯��A��Ԫ�أ���%d���� :", m);
//	for (j = 1; j <= m; j++) // ��������A������
//	{
//		i = Malloc(space); // ������
//		scanf("%c", &space[i].data); // ����A��Ԫ��ֵ
//		space[r].cur = i; // ���뵽��β
//		r = i;
//	}
//	scanf("%*c"); // %*c�Ե��س���
//	space[r].cur = 0; // β����ָ��Ϊ��
//	ListTraverse(space, S, print2);
//	printf("�����뼯��B��Ԫ�أ���%d���� :", n);
//	for (j = 1; j <= n; j++)
//	{ // ��������B��Ԫ�أ������ڵ�ǰ���У�����룻����ɾ��
//		scanf("%c", &b);
//		p = S;
//		k = space[S].cur; // kָ�򼯺�A�еĵ�һ�����
//		while (k != space[r].cur&&space[k].data != b)
//		{ // �ڵ�ǰ���в���
//			p = k;
//			k = space[k].cur;
//		}
//		if (k == space[r].cur)
//		{ // ��ǰ���в����ڸ�Ԫ�أ�������r��ָ���֮����r��λ�ò���
//			i = Malloc(space);
//			space[i].data = b;
//			space[i].cur = space[r].cur;
//			space[r].cur = i;
//		}
//		else // ��Ԫ�����ڱ��У�ɾ��֮
//		{
//			space[p].cur = space[k].cur;
//			Free(space, k);
//			if (r == k)
//				r = p; // ��ɾ������βԪ�أ������޸�βָ��
//		}
//	}
//}
void InitSpace(SLinkList L)
{
	int i;
	L[MAX_SIZE-1].cur = 0;
	for (i = 0; i < MAX_SIZE - 1;i++){
		L[i].cur = i + 1;
	}
}

int Malloc(SLinkList L)
{
	int i = L[0].cur;
	if (i){
		L[0].cur = L[i].cur;
	}
	return i;
}
void Free(SLinkList L, int k)
{
	int i = L[0].cur;
	L[0].cur = k;
	L[k].cur = i;
}
int InitList(SLinkList L)
{
	int i;
	i = Malloc(L);
	L[i].cur = 0;
	return i;
}
void ClearList(SLinkList L, int n)
{
	int occupied = L[n].cur, unoccupied = L[0].cur,i;
	L[n].cur = 0;
	L[0].cur = occupied;
	for (i = 0; L[occupied].cur; i++)
		occupied = L[occupied].cur;
	L[occupied].cur = unoccupied;
}
Status ListEmpty(SLinkList L, int n)
{
	if (L[n].cur)
		return FALSE;
	return TRUE;	
}
int ListLength(SLinkList L, int n)
{
	int cur=L[n].cur,count=0;
	while (cur){
		cur = L[cur].cur;
		count++;
	}
	return count;
}
Status GetElem(SLinkList L, int n, int i, Elemtype&elem)
{
	int cur = L[n].cur, count = 1;
	while (cur&&count < i){
		cur = L[cur].cur;
		count++;
	}
	if (!cur || i < count)
		return ERROR;
	elem = L[cur].data;
	return OK;
}
int LocateElem(SLinkList L, int n, Elemtype elem)
{
	int cur = L[n].cur;
	while (cur){
		if (L[cur].data == elem)
			return cur;
		cur = L[cur].cur;
	}
	return 0;
}
Status PriorElem(SLinkList L, int n, Elemtype elem_cur, Elemtype&elem_pre)
{
	int front, back = L[n].cur;
	while (L[back].cur){
		front = back;
		back = L[back].cur;
		
		if (L[back].data == elem_cur){
			elem_pre = L[front].data;
			return OK;//printf("\n%d\n",L[back].data);
		}
	}
	return ERROR;
}
Status NextElem(SLinkList L, int n, Elemtype elem_cur, Elemtype&elem_next)
{
	int cur = L[n].cur;
	while (L[cur].cur){
		if (L[cur].data == elem_cur){
			cur = L[cur].cur;
			elem_next = L[cur].data;
			return OK;
		}	
		cur = L[cur].cur;
	}
	return ERROR;
}
Status ListInsert(SLinkList&L, int n, int i, Elemtype elem)
{
	int cur = n, count = 1,temp;
	while (cur&&count<i){
		cur = L[cur].cur;
		count++;
	}
	if (!cur || i>count)
		return ERROR;
	temp = Malloc(L);
	L[temp].data = elem;
	L[temp].cur = L[cur].cur;
	L[cur].cur = temp;
//	printf("\ntemp=%d\n", temp);
	return OK;
}
Status ListDelete(SLinkList L, int n, int i, Elemtype&elem)
{
	int cur = n,count=1,cur_temp;
	while (L[cur].cur&&count<i){
		count++;
		cur = L[cur].cur;
	}
	if (!L[cur].cur || count>i)
		return ERROR;
	cur_temp = L[cur].cur;
	elem = L[cur_temp].data;
	L[cur].cur = L[cur_temp].cur;
	Free(L,cur_temp);
	return OK;
}
void ListTraverse(SLinkList L, int n, void(*func)(Elemtype elem))
{
	int cur = L[n].cur;
	while (cur){
		func(L[cur].data);
		cur = L[cur].cur;
	}
}

//Testing Function**************************************************************
Status equal(ElemType c1, ElemType c2)
{ // �ж��Ƿ���ȵĺ���
	if (c1 == c2)
		return TRUE;
	else
		return FALSE;
}
int comp(ElemType a, ElemType b)
{ // ����a<�� =��>b���ֱ𷵻�-1�� 0��1
	if (a == b)
		return 0;
	else
		return (a - b) / abs(a - b);
}
void print(ElemType c)
{
	printf("%d ", c);
}
void print2(ElemType c)
{
	printf("%c ", c);
}
void print1(ElemType &c)
{
	printf("%d ", c);
}
Status sq(ElemType c1, ElemType c2)
{ // ����Ԫ���ж�����(ƽ����ϵ)�� LocateElem()���õĺ���
	if (c1 == c2*c2)
		return TRUE;
	else
		return FALSE;
}
void dbl(ElemType &c)
{ // ListTraverse()���õ���һ����(Ԫ��ֵ�ӱ�)
	c *= 2;
}

