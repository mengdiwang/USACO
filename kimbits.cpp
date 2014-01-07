/*
ID:wangmengd1
LANG:C++
TASK:kimbits
*/
	
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <memory>
#include <cstdlib>
using namespace std;
//------------------------------------------
//#define INNAME "kimbits.in"
//#define OUTNAME "kimbits.out"
ifstream mycin("kimbits.in");
ofstream mycout("kimbits.out");
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
double dp[33][33];

int main()
{
	int N, L;
	double I;
	mycin >> N >> L >> I;
	
	for(int i=0; i<33; i++)
	{
		dp[0][i] = 1;
	}
	for(int i=1; i<33; i++)
	{
		for(int j=0; j<33; j++)
		{
			if(j==0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j]+ dp[i-1][j-1];
		}
	}
	
	I--;
	for(int i=N; i>0; i--)
	{
		printf("%d %d %lf %lf\n", i, L, I, dp[i-1][L]);
		if(I >= dp[i-1][L])
		{		
			I -= dp[i-1][L];
			L --;
			mycout << 1;
		}
		else
		{
			mycout << 0;
		}
	}
	mycout << endl;
	return 0;
}
