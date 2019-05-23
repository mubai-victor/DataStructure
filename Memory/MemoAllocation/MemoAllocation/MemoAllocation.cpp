// MemoAllocation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	cAlloc pav, p; // 空闲块指针
	Space v[MAX / MIN] = { NULL }; // 占用块指针数组(初始化为空)
	int n;
	printf("结构体WORD为%d个字节\n", sizeof(WORD));
	printf("初始化后，可利用空间表为\n");
	pav.Init();
	pav.Print();
	n = 300;
	v[0] = pav.AllocBoundTag(n);
	printf("分配%u个存储空间后，可利用空间表为\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 450;
	v[1] = pav.AllocBoundTag(n);
	printf("分配%u个存储空间后，pav为\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 300; // 分配不成功
	v[2] = pav.AllocBoundTag(n);
	printf("分配%u个存储空间后(不成功)，pav为\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 240; // 分配整个块(250)
	v[2] = pav.AllocBoundTag(n);
	printf("分配%u个存储空间后(整块分配)，pav为\n", n);
	pav.Print();
	pav.PrintUser(v);
	printf("回收v[0](%d)后(当pav空时回收)，pav为\n", v[0]->size);
	pav.Reclaim(v[0]); // pav为空
	pav.Print();
	pav.PrintUser(v);
	printf("1按回车键继续");
	getchar();
	printf("回收v[2](%d)后(左右邻区均为占用块),pav为\n", v[2]->size);
	pav.Reclaim(v[2]); // 左右邻区均为占用块
	pav.Print();
	pav.PrintUser(v);
	n = 270; // 查找空间足够大的块

	v[0] = pav.AllocBoundTag(n);
	printf("分配%u个存储空间后(查找空间足够大的块)，pav为\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 30; // 在当前块上分配
	v[2] = pav.AllocBoundTag(n);
	printf("分配%u个存储空间后(在当前块上分配)，pav为\n", n);
	pav.Print();
	pav.PrintUser(v);
	printf("回收v[1](%d)后(右邻区为空闲块,左邻区为占用块)，pav为\n", v[1]->size);
	pav.Reclaim(v[1]); // 右邻区为空闲块，左邻区为占用块
	Space temp = v[0];
	pav.Print();
	pav.PrintUser(v);
	printf("2按回车键继续");
	getchar();
	printf("回收v[0](%d)后(左邻区为空闲块,右邻区为占用块)，pav为\n", v[0]->size);
	pav.Reclaim(v[0]); // 左邻区为空闲块，右邻区为占用块
	pav.Print();
	pav.PrintUser(v);
	printf("回收v[2](%d)后(左右邻区均为空闲块),pav为\n", v[2]->size);
	pav.Reclaim(v[2]); // 左右邻区均为空闲块
	pav.Print();
	pav.PrintUser(v);
    return 0;
}

