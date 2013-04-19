/*
ID:wangmengd1
LANG:C++
TASK:fact4
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
#define INNAME "fact4.in"
#define OUTNAME "fact4.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
int N;
//------------------------------------------
long long main_alg()
{
	long long fact = 1;
	for(int i=1; i<=N; i++)
	{
		fact *= i;
		while(!(fact%10))
			fact /= 10;
		fact %= 100000;
	}
	return fact%10;
}
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d ", &N);
}
//------------------------------------------
void print_answer()
{
	printf("%lld\n", main_alg());
}
//------------------------------------------
int main()
{
	read_and_init();
	print_answer();

	return 0;
}
