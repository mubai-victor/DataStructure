// AllocBuddy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	int i, n;
	cAlloc a;
	a.Init();
	Space q[SIZE + 1] = { NULL }; // q数组为占用块的首地址
	printf("sizeof(WORD_b)=%u size=%u int(pow(2,size))=%u\n", sizeof(WORD_b), SIZE, int(pow(2, SIZE)));
	a.Print();
	n = 100;
	q[0] = a.AllocBuddy(n);
	// 向a申请100个WORD_b的内存(实际获得128个WORD_b)
	printf("申请%d个字后，可利用空间为\n", n);
	a.Print();
	a.PrintUser(q);
	n = 200;
	q[1] = a.AllocBuddy(n); // 向a申请200个WORD_b的内存(实际获得256个WORD_b)
	printf("申请%d个字后，可利用空间为\n", n);
	a.Print();
	a.PrintUser(q);
	n = 220;
	q[2] = a.AllocBuddy(n); // 向a申请220个WORD_b的内存(实际获得256个WORD_b)
	printf("申请%d个字后，可利用空间为\n", n);
	a.Print();
	a.PrintUser(q);
	a.Reclaim(q[1]); // 回收q[1]，伙伴不空闲
	printf("回收q[1]后，可利用空间为\n");
	a.Print();
	a.PrintUser(q);
	a.Reclaim(q[0]); // 回收q[0]，伙伴空闲
	printf("回收q[0]后，可利用空间为\n");
	a.Print();
	a.PrintUser(q);
	a.Reclaim(q[2]); // 回收q[2]，伙伴空闲，生成一个大结点
	printf("回收q[2]后，可利用空间为\n");
	a.Print();
	a.PrintUser(q);

    return 0;
}

