/*
ID:wangmengd1
LANG:C++
TASK:money
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
#define INNAME "money.in"
#define OUTNAME "money.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int coinage[26] = {0};
long long dp[10001] = {0};
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int V, N;
	scanf("%d %d", &V, &N);
	for(int i=0; i<V; i++)
		scanf("%d", &coinage[i]);

	dp[0] = 1;
	for(int i=0; i<V; i++)
		for(int j=coinage[i]; j<=N; j++)
			dp[j] += dp[j-coinage[i]];
		
	printf("%lld\n", dp[N]);

	return 0;
}
