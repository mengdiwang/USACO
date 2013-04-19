/*
ID:wangmengd1
LANG:C++
TASK:palsquare
*/

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
//------------------------------------------
#define INNAME "palsquare.in"
#define OUTNAME "palsquare.out"
#define MAXNUM 300
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
char answer[20];
char orig[10];
char reversestr[20];
//------------------------------------------
/**
* ANSI C "itoa" based on Kernighan & Ritchie's "ANSI C"
* with slight modification to optimize for specific architecture:
*/
void strreverse(char* begin, char* end) 
{
	char aux;
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}
//------------------------------------------
void Myitoa(int value, char* str, int base) 
{
	static char num[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";	
	char* wstr=str;	
	int sign;
	div_t res;
	
	if (base<2 || base>35){ *wstr='\0'; return; }
	if ((sign=value) < 0) value = -value;	

	do {
		res = div(value,base);	
		*wstr++ = num[res.rem];	
	}while(value=res.quot);

	if(sign<0) *wstr++='-';
	*wstr='\0';
	// Reverse string
	strreverse(str,wstr-1);
}
//------------------------------------------
int checkPal(int pivot)
{
	strcpy(reversestr, answer);
	strreverse(reversestr, reversestr+pivot-1);
	return !strcmp(reversestr, answer);
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int n, t;
	scanf("%d", &n);

	for(int i=1; i<=MAXNUM; i++)
	{
		//int i = 202;
		memset(answer, 0, sizeof(answer));
		memset(orig, 0, sizeof(orig));

		Myitoa(i, orig, n);
		Myitoa(i*i, answer, n);

		if(checkPal(strlen(answer)))
			printf("%s %s\n", orig, answer);
	}

	return 0;
}