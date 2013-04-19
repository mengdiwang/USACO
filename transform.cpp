/*
ID:wangmengd1
LANG:C++
TASK:transform
*/

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------
#define INNAME "transform.in"
#define OUTNAME "transform.out"
#define  MAXN 11
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
struct TBoard
{
	char board[MAXN][MAXN];
	int n;
};
//------------------------------------------
/*void ReadIn(int n, TBoard &b)
{
	b.n = n;
	for(int i=0; i<n; i++)
		gets(b.board[i]);
}*/
//------------------------------------------
TBoard Rotate(TBoard b)
{
	TBoard tmp = b;
	for(int i=0; i<b.n; i++)
	{
		for(int j=0; j<b.n; j++)
		{
			tmp.board[j][b.n-i-1] = b.board[i][j];
		}
	}
	return tmp;
}
//------------------------------------------	
TBoard Reflect(TBoard b)
{
	TBoard tmp = b;
	for(int i=0; i<b.n; i++)
		for(int j=0; j<b.n; j++)
			tmp.board[i][b.n-1-j] = b.board[i][j];
	return tmp;
}
//------------------------------------------	
bool IsEqual(const TBoard &bb, const TBoard &b)
{
	for(int i=0; i<b.n; i++)
		for(int j=0; j<b.n; j++)
			if(bb.board[i][j] != b.board[i][j])
				return false;
	return true;
}
//------------------------------------------	
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int n;
	TBoard b;
	TBoard bb;
	scanf("%d\n", &n);

	b.n = n;
	bb.n = n;
	for(int i=0; i<n; i++)
		gets(b.board[i]);

	for(int i=0; i<n; i++)
		gets(bb.board[i]);
	//ReadIn(n, b);
	//ReadIn(n, bb);

	if(IsEqual(Rotate(b),bb))
	{	
		printf("1\n");
		return 0;
	}
	else if(IsEqual(Rotate(Rotate(b)),bb))
	{	
		printf("2\n");
		return 0;
	}
	else if(IsEqual(Rotate(Rotate(Rotate(b))),bb))
	{	
		printf("3\n");
		return 0;
	}
	else if(IsEqual(Reflect(b),bb))
	{	
		printf("4\n");
		return 0;
	}
	else if(IsEqual(Reflect(Rotate(b)),bb) || IsEqual(Reflect(Rotate(Rotate(b))),bb) ||
		IsEqual(Reflect(Rotate(Rotate(Rotate(b)))),bb))
	{	
		printf("5\n");
		return 0;
	}
	else if(IsEqual(b,bb))
	{	
		printf("6\n");
		return 0;
	}
	else
	{	
		printf("7\n");
	}

	return 0;
}
