// HuffmanCoding.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "�ļ�1��huffman���롣" << endl;
	H.Print();
	cout << "�ļ�2��Huffman���롣" << endl;
	T.Print();
	return 0;
}

