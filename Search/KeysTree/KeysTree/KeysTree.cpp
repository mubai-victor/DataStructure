// KeysTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"

using namespace std;

int main()
{
	KeysTree t;
	int i;
	char s[MAX_KEY_LEN + 1];
	KeysType k;
	Record *p;
	Record r[N] = { { { "CAI" },1 },{ { "CAO" },2 },{ { "LI" },3 },{ { "LAN" },4 },{ { "CHA" },5 },{ { "CHANG" },6 },
	{ { "WEN" },7 },{ { "CHAO" },8 },{ { "YUN" },9 },{ { "YANG" },10 },{ { "LONG" },11 },
	{ { "WANG" },12 },{ { "ZHAO" },13 },{ { "LIU" },14 },{ { "WU" },15 },{ { "CHEN" },16 } };
	// ����Ԫ��(�Խ̿���ʽ924Ϊ��)
	for (i = 0; i<N; i++)
	{
		r[i].key.num = strlen(r[i].key.ch);
		p = t.SearchDLTree(r[i].key);
		if (!p) // t�в����ڹؼ���Ϊr[i].key����
			t.InsertDLTree(&r[i]);
	}
	printf("���ؼ��ַ�����˳�����˫������:\n");
	t.TraverseDLTree(print);
	printf("\n����������Ҽ�¼�Ĺؼ��ַ���: ");
	cin >> s;
	k.num = strlen(s);
	strcpy_s(k.ch, s);
	p = t.SearchDLTree(k);
	if (p)
		print(*p);
	else
		printf("û�ҵ�");
	printf("\n");
    return 0;
}

