/*
ID:wangmengd1
LANG:C++
TASK:zerosum
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
#define INNAME "zerosum.in"
#define OUTNAME "zerosum.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int N = 0;
char state[10] = {0};
//------------------------------------------
void DFS(int t, int sum, int last)
{
	if(t==N)
	{
		if(!sum)
		{
			state[N] = '\n';
			for(int i=1; i<=N; i++)
				printf("%d%c", i, state[i]);
		}
		return;
	}

	state[t] = ' ';
	if(last>0)
		DFS(t+1, sum-last+last*10+t+1, last*10+t+1);
	else
		DFS(t+1, sum-last+last*10-t-1, last*10-t-1);

	state[t] = '+';
	DFS(t+1, sum+t+1, t+1);

	state[t] = '-';
	DFS(t+1, sum-t-1, -t-1);
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);
	scanf("%d", &N);

	DFS(1, 1, 1);

	return 0;
}
