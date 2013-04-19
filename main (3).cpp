/*
ID:wangmengd1
LANG:C++
TASK:runround
*/

#include <stdio.h>
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
#define INNAME "runround.in"
#define OUTNAME "runround.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int M;

	scanf("%d", &M);
	for(int i=M+1; ; i++)
	{
		int t = 0, len, pos = 0, dupl = 0;
		char num[11] = {0};
		int note[11] = {0};
		int reached[11] = {0};
		sprintf(num, "%d", i);
		len = strlen(num);
		
		for(int j=0; j<len; j++)
		{
			note[num[j]-'0'] ++;
			if(note[num[j]-'0']>1)
				dupl = 1;
		}

		if(dupl)
			continue;

		reached[0] = 1;
		for(int j=0; j<=len; j++)
		{
			t = num[pos % len] - '0';
			pos = (t+pos)%len;
			reached[pos%len] = 1;
		}

		for(int j=0; j<len; j++)
			if(reached[j]<1)
				dupl = 1;

		if(dupl || t != num[0]-'0')
		{	
			continue;
		}
		else
		{
			printf("%s\n", num);
			break;
		}
	}

	return 0;
}
