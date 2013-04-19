/*
ID:wangmengd1
LANG:C++
TASK:packrec
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
#define INNAME "packrec.in"
#define OUTNAME "packrec.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
struct TRect
{
	int x;
	int y;
};
//------------------------------------------
TRect rect[4];
//------------------------------------------
TRect Rotate(TRect r)
{
	TRect r2;
	r2.x = r.y;
	r2.y = r.x;

	return r2;
}
//------------------------------------------
void ReadIn()
{
	for(int i=0; i<4; i++)
		scanf("%d %d", &rect[i].x, &rect[i].y);
}
//------------------------------------------
int max(int a, int b)
{
	return a > b ? a : b;
}
//------------------------------------------
int min(int a, int b)
{
	return a < b ? a : b;
}
//------------------------------------------
//------------------------------------------
//------------------------------------------
//------------------------------------------
//------------------------------------------

//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	ReadIn();


	return 0;
}
