/*
ID:wangmengd1
LANG:C++
TASK:lamps
*/

#include <memory.h>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <cstdlib>
using namespace std;
//------------------------------------------
#define INNAME "lamps.in"
#define OUTNAME "lamps.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int fstate[101];
int sstate[7];
int light[10][10]={{},
{0,0,0,0,0,0,0},
{0,0,0,1,1,1,0},
{0,0,1,0,1,0,1},
{0,0,1,1,0,1,1},
{0,1,0,0,1,0,0},
{0,1,0,1,0,1,0},
{0,1,1,0,0,0,1},
{0,1,1,1,1,1,1},
};
int minC[10]={0,1,2,1,1,2,1,2,0};
int N, C, printed = 0;;
//------------------------------------------
int initAndRead()
{
	int t;
	memset(fstate, -1, sizeof(fstate));
	memset(sstate, -1, sizeof(sstate));
	scanf("%d %d", &N, &C);
	while(scanf("%d", &t) && t!=-1)
		fstate[t] = 1;	
	while(scanf("%d", &t) && t!=-1)
	{
		if(fstate[t]==-1)
		{
			fstate[t] = 0;
		}
		else if(fstate[t] = 1)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	for(int i=1; i<=N; i++)
	{
		int t = i%6;
		if(t==0) t = 6;
		if(fstate[i] == 0)
			sstate[t] = 0;
		if(fstate[i] == 1)
			sstate[t] = 1;
	}

	return 1;
}
//------------------------------------------
void deal()
{
	for(int i=1; i<=8; i++)
	{
		bool isok = true;
		for(int j=1; j<=6; j++)
		{
			if(sstate[j]!=-1 && sstate[j]!=light[i][j])
			{
				isok = false;
				break;
			}
		}

		if(isok && C>=minC[i])
		{
			printed = 1;
			for(int j=1; j<=N; j++)
			{
				int t = j%6;
				if(t==0)  t = 6;
				printf("%d",light[i][t]);
			}
			printf("\n");
		}
	}
	if(!printed)
		printf("IMPOSSIBLE\n");
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	if(initAndRead())
		deal();

	return 0;
}
