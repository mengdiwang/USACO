/*
ID:wangmengd1
LANG:C++
TASK:subset
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
#define INNAME "subset.in"
#define OUTNAME "subset.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
long long f[40][1000] = {0};
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int N;
	scanf("%d", &N);
	

	int sum = N*(N+1)/2;
	if(sum&1)
	{
		printf("0\n");
		return 0;
	}
	sum /= 2;

	f[1][1] = 1;
	f[1][0] = 1;

	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<=sum; j++)
		{
			if(i<=j)
				f[i][j] = f[i-1][j] + f[i-1][j-i];
			else
				f[i][j] = f[i-1][j];
		}
	}
	printf("%d\n", f[N][sum]/2);

	return 0;
}
