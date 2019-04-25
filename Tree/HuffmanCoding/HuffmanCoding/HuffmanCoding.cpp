// HuffmanCoding.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"

#define FILENAME1 "HuffmanCoding1.txt"
#define FILENAME2 "HuffmanCoding2.txt"

using namespace std;

int main()
{
	HuffmanTree H, T;
	H.Create(FILENAME1);
	T.Create(FILENAME2);
	H.HuffmanCoding();
	T.HuffmanCoding1();
	cout << "文件1的huffman编码。" << endl;
	H.Print();
	cout << "文件2的Huffman编码。" << endl;
	T.Print();
	return 0;
}

