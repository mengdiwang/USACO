/*
ID:wangmengd1
LANG:C++
TASK:clocks
*/

#include <memory.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <queue>
using namespace std;
//------------------------------------------
#define INNAME "clocks.in"
#define OUTNAME "clocks.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int OK = 0;
int minN = 99999999;
int state[10] = {0};
int gone[11] = {-1};
int answer[100] = {0};
int change[9][9] = 
{{1,1,0,1,1,0,0,0,0},
{1,1,1,0,0,0,0,0,0},
{0,1,1,0,1,1,0,0,0},
{1,0,0,1,0,0,1,0,0},
{0,1,0,1,1,1,0,1,0},
{0,0,1,0,0,1,0,0,1},
{0,0,0,1,1,0,1,1,0},
{0,0,0,0,0,0,1,1,1},
{0,0,0,0,1,1,0,1,1}};
//------------------------------------------
struct TMove
{
	int x;
	int y;
	int state[10]; 
};
//------------------------------------------
bool Check()
{
	for(int i=0; i<9; i++)
		if((state[i]%4)!=0)
			return false;
	return true;
}
//------------------------------------------
void DecState(int i, int k)
{
	for(int j=0; j<9; j++)
		state[j] = (state[j] - k*change[i][j] + 4)%4;
}
//------------------------------------------
void IncState(int i, int k)
{
	for(int j=0; j<9; j++)
		state[j] = (state[j] + k*change[i][j])%4;
}
//------------------------------------------
void DFS(int n)
{
	if(n==9)
	{
		if(Check())
		{
			if(gone[10] < minN)
			{
				int t=0;
				minN = gone[10];
				for(int i=0; i<10; i++)
					for(int j=0; j<gone[i]; j++)
						answer[t++] = i+1;
				answer[99] = t;
			}
			if(gone[10] == minN)
			{
				int t = 0;
				int answer2[100] = {0};
				for(int i=0; i<10; i++)
					for(int j=0; j<gone[i]; j++)
						answer2[t++] = i+1;
				if(answer[99]>t)
				{
					memset(answer, 0, sizeof(answer));
					memcpy(answer, answer2, sizeof(int)*t);
					answer[99] = t;
				}
				else
				{
					bool bigger = false;
					for(int i=0; i<t; i++)
					{
						if(answer[i]>answer2[i])
						{
							bigger = true;
							break;
						}
					}
					if(bigger)
						memcpy(answer, answer2, sizeof(int)*t);						
				}
				
			}
		}
		return;
	}

	for(int i=0; i<=3; i++)
	{
		IncState(n, i);
		gone[n] = i;
		gone[10] += i;
		DFS(n+1);
		DecState(n, i);
		gone[n] = -1;
		gone[10] -= i;
	}

}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			int s;
			scanf("%d", &s);
			state[i*3+j] = s/3%4;
		}
	}

	DFS(0);

	for(int i=0; i<answer[99]; i++)
		printf("%d%c", answer[i], i==answer[99]-1?'\n':' ');

	return 0;
}
