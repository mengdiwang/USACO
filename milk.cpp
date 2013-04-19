/*
ID:wangmengd1
LANG:C++
TASK:milk
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
#define INNAME "milk.in"
#define OUTNAME "milk.out"
#define MAXN 5001
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
map<int, int>supplier;
map<int, int>::iterator iter;
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int N, M, sum = 0;
	scanf("%d %d", &N, &M);
		
	for(int i=0; i<M; i++)
	{
		int c, a;
		scanf("%d %d", &c, &a);
		iter = supplier.find(c);
		if(iter == supplier.end())
			supplier.insert(pair<int, int>(c,a));
		else
			iter->second += a;
	}

	for(iter = supplier.begin();
		iter != supplier.end();
		iter ++)
	{
		if(N)
		{
			if(N <= iter->second)
			{
				sum += (N * iter->first);
				N = 0;
			}
			else
			{
				N -= iter->second;
				sum += (iter->first * iter->second);
			}
		}
		else
		{
			break;
		}
	}

	printf("%d\n", sum);

	return 0;
}