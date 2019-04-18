// ThreadingTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#define FILENAME "ThreadingTree.txt"
#define FILENAME1 "ThreadingTree1.txt"
#define FILENAME2 "ThreadingTree2.txt"
using namespace std;

int main()
{
	BiThrTree H, T;
	T.CreateBiThrTree(FILENAME); // 按先序产生二叉树
	H.InOrderThreading(T); // 在中序遍历的过程中，中序线索化二叉树
	printf("中序遍历(输出)线索二叉树:\n");
	H.InOrderTraverse_Thr(visit); // 中序遍历(输出)线索二叉树
	printf("\n");
	H.DestroyBiThrTree(); // 销毁线索二叉树
	T.CreateBiThrTree(FILENAME); // 按先序产生二叉树T
	H.PreOrderThreading(T); // 在先序遍历的过程中，先序线索化二叉树
	printf("先序遍历(输出)线索二叉树:\n");
	H.PreOrderTraverse_Thr(visit);
	H.DestroyBiThrTree(); // 销毁线索二叉树
	T.CreateBiThrTree(FILENAME); // 按先序产生二叉树T
	H.PostOrderThreading(T); // 在后序遍历的过程中，后序线索化二叉树
	H.DestroyBiThrTree(); // 销毁线索二叉树
    return 0;
}

