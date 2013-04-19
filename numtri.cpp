/*
ID:wangmengd1
LANG:C++
TASK:numtri
*/

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
#define INNAME "numtri.in"
#define OUTNAME "numtri.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int tri[1001][1001] = {0};
int answer[1001] = {0};
//------------------------------------------
int Mymax(int a, int b)
{
	return a>b?a:b;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<=i; j++)
		{
			scanf("%d", &tri[i][j]);
		}
	}

	for(int i=1; i<N; i++)
	{
		for(int j=0; j<=i; j++)
		{
			int a = 0, b = 0;
			if(j>0)
				a = tri[i][j] + tri[i-1][j-1];
			if(j<i)
				b = tri[i][j] + tri[i-1][j];
			tri[i][j] = Mymax(a, b);
		}
	}
	int MaxN = tri[N-1][0];
	for(int i=0; i<N; i++)
		checkmax(MaxN, tri[N-1][i]);

	printf("%d\n", MaxN);

	return 0;
}
