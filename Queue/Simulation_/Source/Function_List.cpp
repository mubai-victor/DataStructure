#include "stdafx.h"
#include "Function_List.h"
#include "Function_Queue.h"
#include "Test.h"


LinkQueue q[Qu];
LinkQueue Q;
QElemType customer[Qu];
EventList evlist;
Event ev_pre, ev_temp;
long int TotalTime = 0;
int CloseTime, CustomerNum = 0;
bool check[Qu];
//24 base functions
void MakeNode(Link&p, Elemtype elem)//分配一个由P指向的节点，节点的数据的值为elem
{
	p = (Link)malloc(LEN);
	if (!p)
		exit(ERROR);
	p->data = elem;
}
void FreeNode(Link&p)//release the node pointed by the pointer p;
{
	free(p);
	p = NULL;
}
void InitList(LinkList&L)//initialise the list L; 
{
	L.head = L.tail = (Link)malloc(LEN);
	L.head->next = NULL;
	L.length = 0;
}
void ClearList(LinkList&L)//clear the list L;
{
	Link cur_front,cur_back = L.head->next;
	L.head->next = NULL;
	while (cur_back != L.tail){
		cur_front=cur_back;
		free(cur_front);
		cur_back=cur_front;
	}
	free(L.tail);
	L.tail = L.head;
	L.length = 0;
}
void DestroyList(LinkList&L)//destroy the list L;
{
	Link cur_front, cur_back = L.head->next;
	free(L.head);
	while (cur_back){
		cur_front = cur_back;
		free(cur_front);
		cur_back=cur_back->next;
	}
	L.tail = L.head = NULL;
	L.length = 0;
}
void InsFirst(LinkList&L, Link head, Link addnode)//head points to the node of L,treat head as the head of the list and insert addnode before it;
{//or insert the addnode after head;
	addnode->next= head->next;
	head->next = addnode;
	if (head == L.tail)
		L.tail = addnode;
	L.length++;
}
Status DelFirst(LinkList&L, Link head, Link&delnode)//head points to the node of L,treat head as the head of the list,delete the fisrt node of the list;
{//return the value of the node with delnode,return OK,if list is empty,delnode is NULL and return ERROR;
//	ListTraverse(evlist, Print);
	if (L.head != L.tail){
		delnode = head->next;
		head->next= delnode->next;
		if (delnode == L.tail)
			L.tail = head;
		L.length--;
//		ListTraverse(evlist, Print);
		return OK;
	}
	delnode = NULL;
	return FALSE;
}
void Append(LinkList&L, Link s)//append the list whose head is s to the tail of the L;
{
	int count = 1;
	L.tail->next = s;
	while (s->next){
		s = s->next;
		count++;
	}
	L.length += count;
	L.tail = s;
	L.tail->next = NULL;
}
Position PriorPos(LinkList L, Link s)//s points to the node of the list L,return pointer of  the prior position,if not exist ,return NULL;
{
	Link cur = L.head->next;
	if (cur == s){
		return NULL;
	}
	while (cur->next != s)
		cur = cur->next;
	return cur;
}
Status Remove(LinkList&L, Link&p)//delete the tail node of the list and return it with p,change the element of tail of L,if empty,p is NULL,return ERROR;
{
	if (L.tail == L.head){
		p = NULL;
		return FALSE;
	}		
	Link cur = L.head;
	while (cur->next!=L.tail){
		cur = cur->next;
	}
	p = L.tail;
	cur->next = NULL;
	L.tail = cur;
	L.length--;
	return OK;
}
void InsBefore(LinkList&L, Link&p, Link s)//p points to the node of the list,insert node pointed by s into the front of p,and p points to new node;
{
	Link cur=PriorPos(L,p);
	if (!cur)
		cur = L.head;
	s->next = p;
	cur->next = s;
	p = s;
	L.length++;
}
void InsAfter(LinkList&L, Link&p, Link s)//p points to the node of the list,insert s into the back of the node pointed by p,points to the new node;
{
	s->next = p->next;
	p->next = s;
	if (L.tail == p)
		L.tail = s;
	L.length++;
	p = s;
}
void SetCurElem(Link p, Elemtype s)//p points the node of the list,update the element of the p with s;
{
	p->data = s;
}
Elemtype GetCurElem(Link p)//p points to the node of the list,return the value of the element of the node.
{
	return p->data;
}
Status ListEmpty(LinkList L)//if the list is empty,return true,othewise,return false;
{
	if (L.head == L.tail)
		return TRUE;
	else
		return FALSE;
}
int ListLength(LinkList L)//return the length of list;
{
	return L.length;
}
Position GetHead(LinkList L)//return the pointer of the the head of list;
{
	return L.head->next;
}
Position GetLast(LinkList L)//return the tail pointer of the list;
{
	return L.tail;
}
Position NextPos(Link p)//p pionts to the node of the list,return the next pointer points to next positon;
{
	return p->next;
}
Status LocatePos(LinkList L, int i, Link&p)//get the pointer of poisition i;
{
	if (i<0 || i>L.length)
		return ERROR;
	p = L.head;
	int count = 0;
	while (count < i){
		count++;
		p = p->next;
	}
	return OK;
}
Position LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b))//return the pointer of which value meet the function compare,
{//return its position,if failed,return NULL;
	Link cur = L.head->next;
	while (cur){
		if (compare(cur->data, elem))
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void ListTraverse(LinkList L, void(*func)(Elemtype elem))//call function func for each element of the list by order;
{
	Link cur = L.head->next;
	while (cur){
//		printf("\nhere:\n");
		func(cur->data);
		cur=cur->next;
	}
}
void OrderInsert(LinkList&L, Elemtype elem, int(*compare)(Elemtype elem_a, Elemtype elem_b))//insert elem into L non_dencent
{
	Link cur_front=L.head,cur_temp,cur_back = L.head->next;
	if (cur_front == L.tail){
		cur_temp = (Link)malloc(LEN);
		cur_temp->data = elem;
		cur_temp->next = NULL;
		L.head->next = L.tail = cur_temp;
	}
	else{
		while (cur_back&&compare(cur_back->data, elem) < 0){
			cur_front = cur_back;
			cur_back = cur_back->next;
		}
		cur_temp = (Link)malloc(LEN);
		cur_temp->data = elem;
		cur_front->next = cur_temp;
		cur_temp->next = cur_back;
		if (cur_front == L.tail)
			L.tail = cur_temp;
	}
//	printf("6.%d,%d\n", elem.NType, elem.OccurTime);
	L.length++;
}
Status LocateElem(LinkList&L, Elemtype elem, Position&p, int(*compare)(Elemtype elem_a, Elemtype elem_b))//get the pointer of position of which value makes the compare return 0;
{//if such element don't exist,return the pointer of position before which value make the compare return value beyond 0,and return false;
	Link cur_front = L.head->next;
	p = L.head->next;
	while (p&&compare(p->data,elem) < 0){
		cur_front = p;
		p = p->next;
	}
	if (!p || compare(p->data, elem) < 0){
		p = cur_front;
		return FALSE;
	}
	return OK;
}

Status ListInsert_L(LinkList&L, int i, Elemtype elem)
{
	Link cur,node;
	if(LocatePos(L, i - 1, cur)==ERROR)
		return ERROR;
	MakeNode(node, elem);
	InsAfter(L, cur, node);
	return OK;
}
void MergeList_L(LinkList&A, LinkList&B, LinkList&C,int(*compare)(Elemtype elem_a,Elemtype elem_b))
{
	Link head_a, head_b, iter_a, iter_b,cur_temp;
	Elemtype elem_a, elem_b;
	InitList(C);
	head_a = GetHead(A);
	head_b = GetHead(B);
	iter_a = NextPos(head_a);	
	iter_b = NextPos(head_b);
	while (A.length&&B.length){
		elem_a = GetCurElem(iter_a);
		elem_b = GetCurElem(iter_b);
		if (compare(elem_a, elem_b) < 0){
			DelFirst(A, head_a, cur_temp);
			cur_temp->next = NULL;
			Append(C, cur_temp);
			iter_a = NextPos(head_a);
		}
		else{
			DelFirst(B, head_b, cur_temp);
			cur_temp->next = NULL;
			Append(C, cur_temp);
			iter_b = NextPos(head_b);
		}
	}
	if (A.length){
		Append(C, iter_a);
	}
	else{
		Append(C, iter_b);
	}
	A.head->next = NULL;
	DestroyList(A);
	B.head->next = NULL;
	DestroyList(B);
}

int compare(Event a, Event b)
{
	if (a.OccurTime == b.OccurTime)
		return 0;
	else
		return (a.OccurTime - b.OccurTime) / abs(a.OccurTime - b.OccurTime);
}
void Random(int &d, int &j)
{
	d = rand() % Blsh + 1;
	j = rand() % (Khjg + 1);
}
void OpenForDay()
{
	ev_pre.OccurTime = 0;
	ev_pre.NType = Qu;
	InitList(evlist);
	OrderInsert(evlist, ev_pre, compare);
	InitQueue(Q);
	for (int i=0; i < Qu; i++) {
		check[i] = FREE;
	}
}
int Minimum(LinkQueue q[]) {
	int l[Qu];
	int i, k = 0;
	for (i = 0; i < Qu; i++) {
		l[i] = QueueLength(q[i]);
		printf("第%d窗口有%d个人等待。", i, l[i]);
	}
	for (i = 1; i<Qu; i++)
		if (l[i]<l[0])
		{
			l[0] = l[i];
			k = i;
		}
	return k;
}
void CostumerArrived()
{
	QElemType q_elem;
//	ListTraverse(evlist, Print);
	int durtime, intertime;
	Random(durtime, intertime);
	CustomerNum++;
	ev_temp.OccurTime = ev_pre.OccurTime + intertime;
	ev_temp.NType = Qu;
	if (ev_temp.OccurTime < CloseTime) {
		OrderInsert(evlist, ev_temp, compare);
	}
	q_elem.ArrivalTime = ev_pre.OccurTime;
	q_elem.Duration = durtime;
	EnQueue(Q, q_elem);
	int i = chk();
	q_elem.ArrivalTime = ev_temp.OccurTime;
	q_elem.Duration = durtime;	
	printf("第%d位客户在%d时刻到来。\n", CustomerNum, ev_pre.OccurTime);
	if (i<Qu) {
		DeQueue(Q, customer[i]);
		check[i] = BUSY;
		ev_temp.NType = i;
		ev_temp.OccurTime = ev_pre.OccurTime + durtime;
		OrderInsert(evlist, ev_temp, compare);
	}
}
void CostumerDepature()
{
	TotalTime += ev_pre.OccurTime - customer[ev_pre.NType].ArrivalTime;
	check[ev_pre.NType] = FREE;
	printf("客户在%d时刻从窗口%d离开。\n",ev_pre.OccurTime, ev_pre.NType);
	if (!QueueEmpty(Q)) {
		DeQueue(Q, customer[ev_pre.NType]);
		ev_temp.OccurTime = ev_pre.OccurTime + customer[ev_pre.NType].Duration;
		ev_temp.NType = ev_pre.NType;
		check[ev_pre.NType] = BUSY;
		OrderInsert(evlist, ev_temp, compare);
	}
}
void Bank_Simulation() {
	Link p;
	OpenForDay();
	while (!ListEmpty(evlist)) {
//		ListTraverse(evlist, Print);
		if (DelFirst(evlist, evlist.head, p) == FALSE) {
			printf("error.\n");
			exit(0);
		}		
		ev_pre.NType = GetCurElem(p).NType;
		ev_pre.OccurTime = GetCurElem(p).OccurTime;
		free(p);
		if (ev_pre.NType == Qu) {
			CostumerArrived();
		}
		else{
			CostumerDepature();
		}
	}
	printf("总时间：%d\t总人数:%d\t平均时间%d\t", TotalTime,CustomerNum,TotalTime/CustomerNum);
	printf("最后一位顾客离开的时间为：%d\n",ev_pre.OccurTime );
	DestroyList(evlist);
	for (int i = 0; i < 4; i++) {
		DestroyQueue(q[i]);
	}
}
void Print(Event ev) {
	printf("事件类型：%d,发生时间：%d\n", ev.NType, ev.OccurTime);
}
int chk()
{
	int i;
	for (i = 0; i < Qu; i++) {
		if (check[i] == FREE)
			return i;
	}
	return Qu;
}
