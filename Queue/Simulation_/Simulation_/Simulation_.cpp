// Simulation_.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function_List.h"
#include "Function_Queue.h"
#include "Test.h"
extern int CloseTime;
int main()
{
	CloseTime = 480;
	srand(0);
	Bank_Simulation();
    return 0;
}

