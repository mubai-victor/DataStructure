#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define ORDER

#ifdef ORDER
#define N 11
typedef int KeyType;
struct ElemType {
	KeyType key;
};

#else
typedef long KeyType;

#define key number
#define N 5


struct ElemType // 数据元素类型(以教科书图9.1高考成绩为例)
{
	long number; // 准考证号，与关键字类型同
	char name[9]; // 姓名(4个汉字加1个串结束标志)
	int politics; // 政治
	int Chinese; // 语文
	int English; // 英语
	int math; // 数学
	int physics; // 物理
	int chemistry; // 化学
	int biology; // 生物
	int total; // 总分
};
#endif
class SStable {
private:
	ElemType *elem;
	int length;
public:
	SStable();
	void Create_Seq(ElemType table[],int n);
	void Ascend();
	void Create_Ord(ElemType table[], int n);
	int Search_Seq(KeyType key);
	int Search_Bin(KeyType key);
	void Traverse(void(*Func)(ElemType elem));
	void Print(int i,void(*Func)(ElemType elem));
};

void print(ElemType elem);
#endif