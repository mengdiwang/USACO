/*
ID:wangmengd1
LANG:C++
TASK:holstein
*/
#include <memory.h>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
//#include <memory>
#include <cstdlib>
using namespace std;
//------------------------------------------
#define INNAME "holstein.in"
#define OUTNAME "holstein.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int V, G;
int demand[28] = {0};
int scoop[18][28] = {0};
int ans[18] = {0};
long long minN = 99999999999999;
int countN = 0;
//------------------------------------------
bool done()
{
	for(int i=0; i<V; i++)
	{
		if(demand[i] > 0)
			return false;
	}
	return true;
}
//------------------------------------------
void Inc(int m)
{
	for(int i=0; i<V; i++)
		demand[i] -= scoop[m][i];
}
//------------------------------------------
void Dec(int m)
{
	for(int i=0; i<V; i++)
		demand[i] += scoop[m][i];
}
//------------------------------------------
void DFS(int m, long long state)
{
	if(done())
	{
		int tmp[15] = {0};
		int t = 0;
		for(int i=0; i<m; i++)
		{
			if(state & (1<<i))
			{
				tmp[t++] = i+1;
			}
		}
		long long k = 1;
		long long p = 0;
		for(int i=0; i<t; i++)
		{
			p += tmp[t-1-i] * k;
			k *= 16;
		}

		if(p < minN || t<countN)
		{
			memcpy(ans, tmp, 15*sizeof(int));
			countN = t;
			minN = p;
		}
		return;
	}

	if(m>=G)
		return;

	Inc(m);
	DFS(m+1, state|1<<m);
	Dec(m);

	DFS(m+1, state);
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);


	scanf("%d", &V);
	for(int i=0; i<V; i++)
		scanf("%d", &demand[i]);
	scanf("%d", &G);
	for(int i=0; i<G; i++)
	{
		for(int j=0; j<V; j++)
		{
			scanf("%d", &scoop[i][j]);
		}
	}

	DFS(0, 0L);

	printf("%d ", countN);
	for(int i=0; i<countN; i++)
		printf("%d%c", ans[i], i==countN-1?'\n':' ');

	return 0;

}