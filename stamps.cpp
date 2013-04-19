/*
ID:wangmengd1
LANG:C++
TASK:stamps
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
#define INNAME "stamps.in"
#define OUTNAME "stamps.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
int M, N;
int values[51] ={0};
int dp[2000001] = {0};
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d %d ", &M, &N);
	for(int i=0; i<N; i++)
		scanf("%d", &values[i]);
}
//------------------------------------------
int DP()
{
	dp[0] = 0;
	for(int i=0; i<N; i++)
		dp[values[i]] = 1;
	for(int i=1; ; i++)
	{
		int minN = 1e8;
		if(dp[i]!=0) continue;
		for(int j=0; j<N; j++)
			if(i-values[j]>=1)
				checkmin(minN, dp[i-values[j]]+1);
		dp[i] = minN;
		if(minN>M)
			return i-1;
	}
}
//------------------------------------------
void print_answer()
{
	printf("%d\n", DP());
}
//------------------------------------------
int main()
{
	read_and_init();
	print_answer();

	return 0;
}
