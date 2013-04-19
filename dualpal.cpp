/*
ID:wangmengd1
LANG:C++
TASK:dualpal
*/

#include "stdafx.h"
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------
#define INNAME "dualpal.in"
#define OUTNAME "dualpal.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
char answer[20];
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

	int N, S, count = 0;
	scanf("%d %d", &N, &S);
	memset(reversestr, 0, sizeof(reversestr));
	memset(answer, 0, sizeof(answer));

	for(int i=S+1; count!=N; i++)
	{
		int times = 0;
		for(int k=2; k<=10; k++)
		{
			memset(reversestr, 0, sizeof(reversestr));
			memset(answer, 0, sizeof(answer));
			Myitoa(i, answer, k);
			if(checkPal(strlen(answer)))
			{
				times ++;
			}

			if(times == 2)
			{
				count ++;
				printf("%d\n", i);
				break;
			}

		}
	}
	return 0;
}

