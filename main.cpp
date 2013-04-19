/*
ID:wangmengd1
LANG:C++
TASK:nocows
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
#define INNAME "nocows.in"
#define OUTNAME "nocows.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
const int MOD = 9901;
int dp[201][101];
int smalltree[201][101];
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int N, K;
	scanf("%d %d", &N, &K);
	
//	memset(dp, 0, sizeof(dp));
//	memset(smalltree, 0, sizeof(smalltree));
	
	//for(int i=1; i<=N; i++)
		
	dp[1][1] = 1;

	for(int i=2; i<=K; i++)
	{
		for(int j=1; j<=N; j+=2)
		{
			for(int k=1; k<j; k+=2)
			{
				dp[j][i] += dp[k][i-1] * smalltree[j-1-k][i-2]
				+ dp[j-1-k][i-1] * smalltree[k][i-2]
				+ dp[j-1-k][i-1] * dp[k][i-1];
				dp[j][i] %= MOD;
			}
		}

		for(int j=0; j<=N; j++)
		{
			smalltree[j][i-1] += smalltree[j][i-2]+dp[j][i-1];
			smalltree[j][i-1] %= MOD;
		}
	}

	printf("%d\n", dp[N][K]);

	return 0;
}
