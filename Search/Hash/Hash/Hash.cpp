// Hash.cpp : 定义控制台应用程序的入口点。
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
	{ // 插入前N-1个记录
		j = h.InsertHash(r[i]);
		if (j == DUPLICATE)
			printf("表中已有关键字为%d的记录，无法再插入记录(%d,%d)\n", r[i].key, r[i].key,
				r[i].ord);
	}
	printf("按哈希地址的顺序遍历哈希表:\n");
	h.TraverseHash(print);
	printf("请输入待查找记录的关键字: ");
	cin >> k;
	j = h.Find(k, p);
	if (j == SUCCESS)
		h.Print(p);
	else
		printf("没找到\n");
	j = h.InsertHash(r[i]); // 插入第N个记录
	if (j == ERROR) // 重建哈希表
		j = h.InsertHash(r[i]); // 重建哈希表后重新插入
	printf("按哈希地址的顺序遍历重建后的哈希表:\n");
	h.TraverseHash(print);
	printf("请输入待查找记录的关键字: ");
	cin >> k;
	j = h.Find(k, p);
	if (j == SUCCESS)
		h.Print(p);
	else
		printf("没找到\n");
	h.DestroyHashTable();
    return 0;
}

