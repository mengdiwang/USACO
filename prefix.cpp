/*
ID:wangmengd1
LANG:C++
TASK:prefix
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
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
using namespace std;
//------------------------------------------
#define INNAME "prefix.in"
#define OUTNAME "prefix.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
char s[201][11];
//char sent[200001] = {0};
char getin[80] = {0};
bool dp[200001] = {0};
string sent="", temp;
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int t=0;
	while(scanf("%s", s[t])!=EOF)
	{
		if(s[t][0]!='.')
			t++;
		else
			break;
	}


	while(cin>>temp)
		sent+=temp;
	int slen=sent.length();

	//while(gets(getin)!=NULL)
	//	strcat(sent, getin);

	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for(int i=1; i<=slen; i++)
	{
		for(int j=0; j<t; j++)
		{
			int len = strlen(s[j]);
			if(i>=len)
			{
				bool check = true;
				for(int k=0; k<len; k++)
					if(sent[i-len+k]!=s[j][k])
					{
						check = false;
						break;
					}

				if(dp[i-len] && check)
				{
					dp[i] = true;
					break;
				}
			}
		}
	}


	int printed = 0;
	for(int i=slen; i>0; i--)
	{
		if(dp[i])
		{
			printed = 1;
			printf("%d\n", i);
			break;
		}
	}
	if(!printed)
		printf("0\n");

	return 0;
}
