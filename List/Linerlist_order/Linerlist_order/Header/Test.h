//ʱ��
#ifndef TEST_H
#define TEST_H

#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()��
#include<limits.h> // INT_MAX��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<process.h> // exit()
#include<iostream> // cout,cin
// �������״̬����
#define TRUE -5
#define FALSE -4
#define OK -3
#define ERROR -2
#define INFEASIBLE -1
// #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int Elemtype;
typedef Elemtype ElemType;
typedef Elemtype *Triplet;

#endif