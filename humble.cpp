/*
ID:wangmengd1
LANG:C++
TASK:humble
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
#define INNAME "humble.in"
#define OUTNAME "humble.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
int k, n;
int prime[101] = {0};
int humble[100001] = {0};
int pindex[101] = {0};
int temp[101] = {0};
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d %d ", &k, &n);
	for(int i=0; i<k; i++)
		scanf("%d ", &prime[i]);
	
}
//------------------------------------------
int main_alg()
{
	humble[0] = 1;
	int t = 1;
	while(t<=n)
	{
		int temp = 1e20, pos = 0;
		for(int i=0; i<k; i++)
		{
			if(pindex[i]<t && temp>prime[i]*humble[pindex[i]])
			{
				temp = prime[i]*humble[pindex[i]];
				pos = i;
			}	
		}
		pindex[pos]++;
		if(temp!=humble[t-1])
			humble[t++] = temp;
	}

	return humble[n];
}
//------------------------------------------
void print_answer()
{
	printf("%d\n", main_alg());
}
//------------------------------------------
int main()
{
	read_and_init();
	print_answer();

	return 0;
}
