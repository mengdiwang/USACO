/*
ID:wangmengd1
LANG:C++
TASK:sprime
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
#define INNAME "sprime.in"
#define OUTNAME "sprime.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int base10[9] = {1,10,100,1000,10000,100000,100000,10000000,100000000};
int choice1[4] = {2,3,5,7};
int N;

//------------------------------------------
bool Isprime(int n)
{
	if(n<=1)
		return false;
	int i;
	for(i=2;i<int(sqrt(double(n)))+1;++i)
		if(n%i==0)return false;
	return true;
}
//------------------------------------------
void GenNum(int i, int n)
{
	if(i==N)
	{
		if(Isprime(n))
		printf("%d\n", n);
		return;
	}

	for(int j=1; j<=9; j++)
	{
		int m = 10*n+j;
		if(Isprime(m))
			GenNum(i+1, m);
	}
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d", &N);
	GenNum(0, 0);

	return 0;
}
