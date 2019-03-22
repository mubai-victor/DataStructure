#include "stdafx.h"
#include "stdarg.h"
#include "Function.h"
#include "Test.h"
using namespace std;

char buf[MAX_SIZE];



int compare(int iR, int iL) {
	return (iR - iL) == 0 ? 0 : ((iR - iL) > 0 ? 1 : -1);
}
