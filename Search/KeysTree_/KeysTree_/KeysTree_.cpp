// KeysTree_.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	TrieTrees t;
	int i;
	char s[MAX_KEY_LEN + 1];
	KeysType k;
	Record *p;
	Record r[N] = { { { "CAI" },1 },{ { "CAO" },2 },{ { "LI" },3 },{ { "LAN" },4 },{ { "CHA" },5 },{ { "CHANG" },6 },
	{ { "WEN" },7 },{ { "CHAO" },8 },{ { "YUN" },9 },{ { "YANG" },10 },{ { "LONG" },11 },
	{ { "WANG" },12 },{ { "ZHAO" },13 },{ { "LIU" },14 },{ { "WU" },15 },{ { "CHEN" },16 } };
	for (i = 0; i<N; i++)
	{
		r[i].key.num = strlen(r[i].key.ch) + 1;
		r[i].key.ch[r[i].key.num] = ' '; // �ڹؼ��ַ������ӽ�����
		p = t.SearchTrieTree(r[i].key);
		if (!p)
			t.InsertTrieTree(&r[i]);
	}
	printf("���ؼ��ַ�����˳�����Trie��(����):\n");
	t.TraverseTrieTree(print);
	printf("\n����������Ҽ�¼�Ĺؼ��ַ���: ");
	cin >> s;
	k.num = strlen(s) + 1;
	strcpy_s(k.ch, s);
	k.ch[k.num] = ' '; // �ڹؼ��ַ������ӽ�����
	p = t.SearchTrieTree(k);
	if (p)
		print(p);
	else
		printf("û�ҵ�");
	printf("\n");
	t.DestroyTrieTree();
    return 0;
}

