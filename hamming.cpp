/*
ID:wangmengd1
LANG:C++
TASK:hamming
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
#define INNAME "hamming.in"
#define OUTNAME "hamming.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int ans[65] = {0};
int sum = 1;
int N, B, D;
//------------------------------------------
bool check(int x)
{
	for(int i=1; i<=sum; i++)
	{
		int y = ans[i];
		int cnt=0,tmp=x^y;
		for (;tmp>0;)
		{
			cnt++;
			tmp=tmp-(tmp&(-tmp));
		}
		if(cnt < D)
			return false;
	}
	return true;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);


	scanf("%d %d %d", &N, &B, &D);

	ans[1] = 0;
	for(int i=1; i<=1<<B; i++)
	{
		if(check(i))
			ans[++sum] = i;

		if(sum == N)
			break;
	}

	for(int i=1; i<=N; i++)
	{
		printf("%d", ans[i]);
		if(i%10==0 || i==N)
			printf("\n");
		else
			printf(" ");
	}

	return 0;
}
