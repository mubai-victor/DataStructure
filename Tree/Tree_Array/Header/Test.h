//ʱ��
#ifndef TEST_H
#define TEST_H

#define	CHAR 1
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
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -2
// #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int QElemType;


#if CHAR
typedef char TElemType;
#define Nil ' '
#else
typedef int TElemType;
#define Nil 0
#endif


#endif