/*
ID:wangmengd1
LANG:C++
TASK:inflate
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
#define INNAME "inflate.in"
#define OUTNAME "inflate.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
int m, n;
int dp [10001] = {0};
int contest[10001] = {0};
int cost[10001] ={0};
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d %d ", &m, &n);
	for(int i=0; i<n; i++)
		scanf("%d %d ", &contest[i], &cost[i]);
}
//------------------------------------------
void kacknap()
{
	dp[0] = 0;
	for(int j=1; j<=m; j++)
	{	
		int maxN = dp[j];
		for(int i=0; i<n; i++)
			if(j-cost[i]>=0)
				checkmax(maxN, dp[j-cost[i]]+contest[i]);
		dp[j] = maxN;
	}
}
//------------------------------------------
void print_answer()
{
	printf("%d\n", dp[m]);
}
//------------------------------------------
int main()
{
	read_and_init();
	kacknap();
	print_answer();

	return 0;
}
