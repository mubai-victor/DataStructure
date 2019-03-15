// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

int main()
{
	printf("请输入算术表达式(输入的值要在0～9之间、中间运算值和输出结果在-128～127之间)\n");
	printf("%d\n", EvaluateExpression());
	return 0;
}

