#include "Function.h"
#include "Test.h"

void difference(SLinkList L, int&head)
{
	int count_a = 0, count_b = 0, cur = 0, cur_temp, tail, cur_back;
	Elemtype elem;
	InitSpace(L);
	tail=head = InitList(L);
	printf("输入集合A和集合B的元素数量,逗号分隔：\n");
	scanf("%d,%d*c", &count_a,&count_b);
	printf("输入集合A元素：\n");scanf("%*c"); 
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
	printf("输入集合B元素：\n");
	for (int i = 0; i < count_b; i++){			
		scanf("%c", &elem);
//		printf("elem=%c：\n",elem);
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
//void difference(SLinkList space, int &S) // 算法2.17
//{ // 依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)∪(B-A)
//	// 的静态链表， S为其头指针。假设备用空间足够大， space[0].cur为备用空间的头指针
//	int r, p, m, n, i, j, k;
//	ElemType b;
//	InitSpace(space); // 初始化备用空间
//	S = Malloc(space); // 生成S的头结点
//	r = S; // r指向S的当前最后结点
//	printf("请输入集合A和B的元素个数m,n:");
//	scanf("%d,%d%*c", &m, &n); // %*c吃掉回车符
//	printf("请输入集合A的元素（共%d个） :", m);
//	for (j = 1; j <= m; j++) // 建立集合A的链表
//	{
//		i = Malloc(space); // 分配结点
//		scanf("%c", &space[i].data); // 输入A的元素值
//		space[r].cur = i; // 插入到表尾
//		r = i;
//	}
//	scanf("%*c"); // %*c吃掉回车符
//	space[r].cur = 0; // 尾结点的指针为空
//	ListTraverse(space, S, print2);
//	printf("请输入集合B的元素（共%d个） :", n);
//	for (j = 1; j <= n; j++)
//	{ // 依次输入B的元素，若不在当前表中，则插入；否则删除
//		scanf("%c", &b);
//		p = S;
//		k = space[S].cur; // k指向集合A中的第一个结点
//		while (k != space[r].cur&&space[k].data != b)
//		{ // 在当前表中查找
//			p = k;
//			k = space[k].cur;
//		}
//		if (k == space[r].cur)
//		{ // 当前表中不存在该元素，插入在r所指结点之后，且r的位置不变
//			i = Malloc(space);
//			space[i].data = b;
//			space[i].cur = space[r].cur;
//			space[r].cur = i;
//		}
//		else // 该元素已在表中，删除之
//		{
//			space[p].cur = space[k].cur;
//			Free(space, k);
//			if (r == k)
//				r = p; // 若删除的是尾元素，则需修改尾指针
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
{ // 判断是否相等的函数
	if (c1 == c2)
		return TRUE;
	else
		return FALSE;
}
int comp(ElemType a, ElemType b)
{ // 根据a<、 =或>b，分别返回-1、 0或1
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
{ // 数据元素判定函数(平方关系)， LocateElem()调用的函数
	if (c1 == c2*c2)
		return TRUE;
	else
		return FALSE;
}
void dbl(ElemType &c)
{ // ListTraverse()调用的另一函数(元素值加倍)
	c *= 2;
}

