/*
ID:wangmengd1
LANG:C++
TASK:calfflac
*/

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------
#define INNAME "calfflac.in"
#define OUTNAME "calfflac.out"
//------------------------------------------
char buffer[81];
char instr[20001] = {0};
char str[20001] = {0};
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}
inline void checkmax(int &a,int b){if(b>a) a=b;} 
//------------------------------------------
bool inRange(char ch)
{
	if( ch <= 'z' && ch >= 'a' || 
		ch <= 'Z' && ch >= 'A')
		return true;
	return false;
}
//------------------------------------------
bool isUPPER(char ch)
{
	return (ch >='A' && ch<='Z');
}
//------------------------------------------
char toUPPER(char ch)
{
	if(isUPPER(ch))
		return ch;
	return char(ch - 'a' +'A');
}
//------------------------------------------
/* is string s a palindrome? */
int palLen(int p, int len)
{
	int maxo = 1;
	int maxe = 0;

	//odd pal
	for(int i=1; ; i++)
	{
		if(p-i>=0 && p+i<len && str[p-i]==str[p+i])
			maxo += 2;
		else
			break;
	}

	//even pal
	int q = p+1;
	for(int i=0; ; i++)
	{
		if(p-i>=0 && q+i<len && str[p-i] == str[q+i])
			maxe += 2;
		else
			break;
	}

	return maxe>maxo?maxe:maxo;
}
//------------------------------------------
int Traverse(int &pos)
{
	int maxL = 0;
	int newL = 0;
	int len = strlen(str);

	for(int i=0; i<len; i++)
	{
		newL = palLen(i, len);
		if(maxL < newL)
		{
			maxL = newL;
			if(maxL & 1)	pos = i - maxL/2 ;
			else			pos = i - maxL/2 + 1;
		}
	}
	return maxL;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int t = 0;
	int pos = 0;
	int i, k, p;

	while(gets(buffer)!=NULL)
	{
		strcat(instr, "\n");
		strcat(instr, buffer);
	}

	for(i=0; i<strlen(instr); i++)
	{
		if(inRange(instr[i]))
		{
			str[t++] = toUPPER(instr[i]);
		}
	}

	int l = Traverse(pos);
	printf("%d\n", l);

	for(i=0, k=0; k<=pos; i++)
	{
		if(inRange(instr[i]))
			k++;
	}
	for(k=i-1, p=0; p<l; k++)
	{
		if(inRange(instr[k]))
			p++;
		printf("%c", instr[k]);
	}
	printf("\n");


	return 0;
}
//------------------------------------------

