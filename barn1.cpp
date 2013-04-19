/*
ID:wangmengd1
LANG:C++
TASK:barn1
*/

#include <cstdio>
#include <map>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//------------------------------------------
#define INNAME "barn1.in"
#define OUTNAME "barn1.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
priority_queue< int, vector<int>, greater<int> >pq;
priority_queue< int, vector<int>, less<int> >pq2;
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int M, S, C, B, E, stall, pre = 0;
	scanf("%d %d %d", &M, &S, &C);
	for(int i=0; i<C; i++)
	{
		scanf("%d", &stall);
		pq.push(stall);
	}

	for(int i=0; i<C; i++)
	{
		stall = pq.top();
		pq.pop();

		if(i==0)
		{
			B = stall;
			pre = stall;
			continue;
		}

		pq2.push(stall - pre - 1);
		pre = stall;

		if(i==C-1)
			E = stall;
	}

	int sum = E - B + 1;
	int t = 1;
	while(!pq2.empty() && t<M)
	{
		stall = pq2.top();
		pq2.pop();
		sum -= stall;
		t++;
	}
	printf("%d\n",sum);

	return 0;
}