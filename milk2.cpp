/*
ID:wangmengd1
LANG:C++
TASK:milk2
*/

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------
#define INNAME "milk2.in"
#define OUTNAME "milk2.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);
	
	int n;
	int start, end;
	int maxP = 0, maxL = 0;
	priority_queue< pair<int, int> , vector<pair<int, int> >,greater<pair<int, int> > > q;
	pair<int, int> p1, p2;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d", &start, &end);
		q.push(pair<int, int>(start, end));
	}

	p1 = q.top();
	maxP = p1.second - p1.first;
	q.pop();
	for(int i=1; i<n; i++)
	{
		p2 = q.top();
		q.pop();
		if(p1.second >= p2.first)
		{
			checkmax(p1.second, p2.second);
			int per = p1.second-p1.first;
			checkmax(maxP, per);
		}
		else
		{
			int lat = p2.first - p1.second;
			checkmax(maxL, lat);
			p1 = p2;
		}
	}

	printf("%d %d\n", maxP, maxL);

	return 0;
}

