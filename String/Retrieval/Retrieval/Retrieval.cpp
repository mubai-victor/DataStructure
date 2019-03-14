// Retrieval.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "FunctionString.h"
#include "FunctionList.h"
#include "iostream"
#include "Test.h"
using namespace std;
WordListType noidx, wdlist;
IdxListType idxlist;
extern char buf[MaxLineLen + 1];
int main()
{
	FILE*p;
	errno_t  status;
	int iBookNo = 0;
	status = fopen_s(&p, "NoIdx.txt", "r");
	if (!status)
		cout << "�޷����ļ�1��" << endl;
	fscanf_s(p, "%d", &noidx.length);
	for (int i = 0; i < noidx.length; i++) {
		fgets(buf, MaxLineLen, p);
		noidx.item[i] = new char[strlen(buf) + 1];
		strcpy_s(noidx.item[i],sizeof(noidx.item[i]), buf);
	}
	fclose(p);
	status = fopen_s(&p, "BookInfo.txt", "r");
	if (!status)
		cout << "�޷����ļ�2��" << endl;
	while (fgets(buf, MaxLineLen, p)) {
		wdlist.ExtractKeyword(iBookNo);
		idxlist.InsIdxList(iBookNo);
	}
	fclose(p);
	status = fopen_s(&p, "BookIdx.txt", "w");
	if (!status)
		cout << "�޷����ļ�3." << endl;
	idxlist.PutText(p);
	fclose(0);
    return 0;
}

