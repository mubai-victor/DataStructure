// Simulation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function_Queue.h"
#include "Function_List.h"
#include "Test.h"
extern int CloseTime;
int main()
{
	CloseTime = 480;
	srand(time(0));
	Bank_Simulation();
	//LinkList list;
	//InitList(list);
	//for (int i = 10; i > 0; i--) {
	//	Event ev;
	//	ev.OccurTime = rand();
	//	ev.NType = i;
	//	OrderInsert(list, ev, compare);
	//	
	//}
	//ListTraverse(list, Print);
	//Link ev_temp;
	//DelFirst(list, list.head, ev_temp);
	//printf("%d\n", ev_temp->data.OccurTime);
	//OrderInsert(list, ev_temp->data, compare);
	//ListTraverse(list, Print);
	//printf("length:%d",list.length);
    return 0;
}

