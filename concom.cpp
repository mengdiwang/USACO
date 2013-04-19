/*
ID:wangmengd1
LANG:C++
TASK:concom
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
#define INNAME "concom.in"
#define OUTNAME "concom.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int ctrl[101][101] = {0};
bool owner[101][101] = {0};
int newCtrl[101][101] = {0};
int N;
//------------------------------------------
void readIn()
{
	int u, v, p;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d %d %d", &u, &v, &p);	
		ctrl[u][v] += p;
		if(ctrl[u][v]>50)
			owner[u][v] = true;
	}

	for(int i=1; i<=100; i++)
		owner[i][i] = true;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	readIn();

	bool changed = true;
	while(changed)
	{
		changed = false;
		memset(newCtrl, 0, sizeof(newCtrl));

		for(int i=1; i<=100; i++)
			for(int j=1; j<=100; j++)
				if(owner[i][j])
					for(int k=1; k<=100; k++)
						newCtrl[i][k] += ctrl[j][k];

		for(int i=1; i<=100; i++)
			for(int j=1; j<=100; j++)
				if(newCtrl[i][j] > 50 && !owner[i][j])
				{
					changed = true;
					owner[i][j] = true;	
				}
	}

	for(int i=1; i<=100; i++)
		for(int j=1; j<=100; j++)
			if(owner[i][j] && i!=j)
				printf("%d %d\n", i, j);

	return 0;
}
//------------------------------------------