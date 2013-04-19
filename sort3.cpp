/*
ID:wangmengd1
LANG:C++
TASK:sort3
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
#define INNAME "sort3.in"
#define OUTNAME "sort3.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int input[1000] = {0};
vector<int> to1;
vector<int> to2;
vector<int> to3;
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int N;
	int count1 = 0, count2 = 0, count3 = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d", &input[i]);
		if(input[i] == 1)
			count1++;
		else if(input[i] == 2)
			count2++;
		else
			count3++;
	}

	for(int i=0; i<N; i++)
	{
		if(i<count1)
		{
			if(input[i] == 1)
				continue;
			to1.push_back(input[i]);
		}
		else if(i<count1+count2)
		{
			if(input[i] == 2)
				continue;
			to2.push_back(input[i]);
		}
		else
		{
			if(input[i] == 3)
				continue;
			to3.push_back(input[i]);
		}
	}

	int count = 0;
	sort(to1.begin(), to1.end());
	sort(to2.begin(), to2.end());
	sort(to3.begin(), to3.end());

	for(int i=0; i<to1.size(); i++)
	{		
		int j = 0, k = 0;
		if(to1[i] == 2)
		{
			for(; j<to2.size(); j++)
			{
				if(to2[j] == 1)
				{
					to1[i] = 0;
					to2[j] = 0;
					count ++;
					break;
				}
			}
		}
		else
		{
			for(; k<to3.size(); k++)
			{
				if(to3[k] == 1)
				{
					to3[k] = 0;
					to1[i] = 0;
					count ++;
					break;
				}
			}
		}
	}

	for(int i=0; i<to2.size(); i++)
	{
		int k = 0;
		if(to2[i] == 3)
		{
			for(; k<to3.size(); k++)
			{
				if(to3[k] == 2)
				{
					to3[k] = 0;
					to2[i] = 0;
					count ++;
					break;
				}
			}
		}
	}

	int icount = 0;
	for(int i=0; i<to1.size(); i++)
		if(to1[i] != 0)
			icount++;
	for(int i=0; i<to2.size(); i++)
		if(to2[i] != 0)
			icount++;
	for(int i=0; i<to3.size(); i++)
		if(to3[i] != 0)
			icount++;
	count += 2*icount/3;

	printf("%d\n", count);

	return 0;
}
