/*
ID:wangmengd1
LANG:C++
TASK:namenum
*/

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <map>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------
#define INNAME "namenum.in"
#define OUTNAME "namenum.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
char name[15];
char num[15];
map<__int64, int>nameMap;
map<__int64, int>::iterator iter;
__int64 n;
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("I64d", &n);
	iter = nameMap.find(n);
	printf("%d\n", iter->second);

	return 0;
}