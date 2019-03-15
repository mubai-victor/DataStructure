// Retrieval.cpp : 定义控制台应用程序的入口点。
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
	//FILE*p;
	//errno_t  status;
	//int iBookNo = 0;
	//status = fopen_s(&p, "NoIdx.txt", "r");
	//if (status) {
	//	cout << "无法打开文件1。" << endl;
	//	exit(0);
	//}
	//fscanf_s(p, "%d", &noidx.length);
	//fgets(buf,MaxLineLen,p);
	//for (int i = 0; i < noidx.length; i++) {
	//	fgets(buf,MaxLineLen,p);
	//	buf[strlen(buf) - 1] = '\0';
	//	noidx.item[i] = new char[strlen(buf) + 1];
	//	strcpy_s(noidx.item[i],sizeof(noidx.item[i]), buf);
	//}
	//fclose(p);
	//status = fopen_s(&p, "BookInfo.txt", "r");
	//if (status) {
	//	cout << "无法打开文件2。" << endl;
	//	exit(0);
	//}
	//while (fgets(buf, MaxLineLen, p)) {
	//	wdlist.ExtractKeyword(iBookNo);
	//	idxlist.InsIdxList(iBookNo);
	//}
	//fclose(p);
	//status = fopen_s(&p, "BookIdx.txt", "w");
	//if (status) {
	//	cout << "无法打开文件3." << endl;
	//	exit(0);
	//}
	//idxlist.PutText(p);
	//fclose(p);//generate the retrieval file.
	FILE*p;
	errno_t status = 0;
	BookListType BkList;
	IdxListType WdList;
	int iItemNum = 0, iBkNum = 0, pos = 0, iBkNo = 0;
	char iFlag;
	SString temp;
	status = fopen_s(&p, "BookIdx.txt", "r");
	if (status) {
		cout << "无法打开文件1." << endl;
		exit(0);
	}
	fscanf_s(p, "%d", &iItemNum);
	fgets(buf, MaxLineLen, p);
	for (int i = 0; i < iItemNum; i++) {
		fgets(buf, MaxLineLen, p);
		buf[strlen(buf) - 1] = '\0';
		temp.StrAssign(buf);
		WdList.Locate(temp, pos);
		WdList.InsertNewKey(pos, temp);		
		fscanf_s(p, "%d", &iBkNum);
		fgets(buf, MaxLineLen, p);
		for (int j = 0; j < iBkNum; j++) {
			fscanf_s(p, "%d", &iBkNo);			
			WdList.InsertBook(pos,iBkNo);
		}
		fgets(buf, MaxLineLen, p);
	}
	fclose(p);


	status = fopen_s(&p, "BookInfo.txt", "r");
	if (status) {
		cout << "无法打开文件1." << endl;
		exit(0);
	}
	BkList.length = 0;
	while (fgets(buf, MaxLineLen, p)) {
		buf[strlen(buf) - 1] = '\0';
		iBkNo = atoi(buf);
		BkList.item[BkList.length].bookno = iBkNo;
		strcpy_s(BkList.item[BkList.length].bookname, MaxLineLen, buf + 4);
		BkList.length++;
	}
	fclose(p);

	iFlag = 'y';
	Link l = NULL;
	while (iFlag == 'y') {
		cout << "请输入要检索的关键词：" << endl;
		cin >> buf;
		buf[0] = toupper(buf[0]);
		for (int i = 1; i < strlen(buf); i++) {
			buf[i] = tolower(buf[i]);
		}
		temp.StrAssign(buf);
		if (WdList.Locate(temp, pos)) {
			l = WdList.item[pos].bnolist.head->next;
			while (l) {
				iBkNo = l->data;
				for (int i = 0; i < BkList.length; i++) {
					if (BkList.item[i].bookno == iBkNo) {
						cout << "找到书目，书名为：" << BkList.item[i].bookname << endl;
					}
				}
				l = l->next;
			}
		}
		else {
			cout << "没有找到书目." << endl;
		}
		cout << "是否继续检索？（y for 'yes' and n for 'no'）" << endl;
		cin >> iFlag;
	}
    return 0;
}

