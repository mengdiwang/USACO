/*
ID:wangmengd1
LANG:C++
TASK:frac1
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
#define INNAME "frac1.in"
#define OUTNAME "frac1.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
struct TDic
{
	int a;
	int b;
};
//------------------------------------------
template<class T> inline T gcd(T a,T b) 
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);} 
//------------------------------------------
TDic num[161*161];
int t = 0;
//------------------------------------------
int cmp(const void *x, const void *y)
{
	TDic *A = (TDic *)x;
	TDic *B = (TDic *)y;
	return A->a*B->b < A->b*B->a;
}
//------------------------------------------
void solve(int N)
{
	for(int i=1; i<=N; i++)
		for(int j=i; j<=N; j++)
		{
			if(gcd(i,j)!=1)
			{
				continue;
			}
			else
			{
				num[t].a = i;
				num[t].b = j;
				t++;
			}
		}
}
//------------------------------------------
int main()
{
	//freopen(INNAME, "r", stdin);
	//freopen(OUTNAME, "w", stdout);

	int N;
	scanf("%d", &N);
	solve(N);
	qsort(num, t, sizeof(TDic), cmp);

	printf("0/1\n");
	for(int i=t-1; i>=0; i--)
		printf("%d/%d\n", num[i].a, num[i].b);

	return 0;
}
