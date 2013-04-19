/*
ID:wangmengd1
LANG:C++
TASK:rect1
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
#define INNAME "rect1.in"
#define OUTNAME "rect1.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
int k;
const int maxN = 1001;
int ret[2501] = {0};
int x11[maxN] = {0};
int x2[maxN] = {0};
int y11[maxN] = {0};
int y2[maxN] = {0};
int c[maxN] = {0};
int maxc = 0, n;
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	x11[0] = y11[0] = 0;
	c[0] = 1;
	scanf("%d %d %d", &x2[0], &y2[0], &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d %d %d %d", &x11[i], &y11[i], &x2[i], &y2[i], &c[i]);
		checkmax(maxc, c[i]);
	}
}
//------------------------------------------
void cover(int l, int r, int d, int u, int k, int col)
{
	while((k<=n) && (r<=x11[k] || l>=x2[k] || u<=y11[k] || d>=y2[k]))
		k++;	

	if(k>n) 
	{
		ret[col] += (r-l) * (u-d);
		return;
	}

	if(l<x11[k])
	{
		cover(l, x11[k], d, u, k+1, col);
		l = x11[k];
	}
	if(r>x2[k])
	{
		cover(x2[k], r, d, u, k+1, col);
		r = x2[k];
	}
	if(d<y11[k])
	{
		cover(l, r, d, y11[k], k+1, col);
		d = y11[k];
	}
	if(u>y2[k])
	{
		cover(l, r, y2[k], u, k+1, col);
		u = y2[k];
	}
}
//------------------------------------------
void work()
{
	for(int i=n; i>=0; i--)
		cover(x11[i], x2[i], y11[i], y2[i], i+1, c[i]);
}
//------------------------------------------
void print_answer()
{
	for(int i=1; i<=maxc; i++)
		if(ret[i])
			printf("%d %d\n", i, ret[i]);
}
//------------------------------------------
int main()
{
	read_and_init();
	work();
	print_answer();

	return 0;
}
