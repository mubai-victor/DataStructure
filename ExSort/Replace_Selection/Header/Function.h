#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define w 6
#define N 24
#define M 10

typedef int LoserTree[w];
typedef int KeyType;
typedef int InfoType;



struct RedType {
	KeyType key;
	InfoType otherinfo;
};
typedef struct {
	RedType rec;
	KeyType key;
	int num;
}RedNode, WorkArea[w];



void Select_MiniMax(LoserTree ls, WorkArea wa, int q);
void Construct_Loser(LoserTree ls,WorkArea wa,FILE *fi);
void get_run(LoserTree ls, WorkArea wa, int rc, int &rmax, FILE *fi, FILE *fo);
void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo);
void print(RedType);




#endif