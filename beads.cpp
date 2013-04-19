/*
ID:wangmengd1
LANG:C++
TASK:beads
*/

#include "stdafx.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
//------------------------------------------
int main()
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int n, roff = 0, loff = 0;
	int leftLen = 0, rightLen = 0, maxLen = -1;
	char lace[351];
	char leftSta, rightSta;


	scanf("%d", &n);
	getchar();
	gets(lace);

	for(int i=0; i<n; i++)
	{
		int j =(i + 1) % n;
		assert(j>=0 && j<n);
		leftSta = lace[j];
		for(; j!=i; j=(j+1)%n) 
		{
			assert(j>=0 && j<n);
			if(lace[j] == 'w')
				leftLen ++;
			else if(leftSta == 'w')
			{
				leftSta = lace[j];
				leftLen ++;
			}
			else if(leftSta == lace[j])
				leftLen ++;
			else
				break;
		}

		if(j==i && leftLen == n-1)
		{
			maxLen = n;
			break;
		}

		rightSta = lace[i];
		int k = i;
		assert(k>=0 && k<n);
		for(; k!=i+1; k=((k-1)%n+n)%n)
		{
			assert(k>=0 && k<n);
			if(lace[k] == 'w')
				rightLen ++;
			else if(rightSta == 'w')
			{
				rightSta = lace[k];
				rightLen ++;
			}
			else if(rightSta == lace[k])
				rightLen ++;
			else
				break;
		}
		if(maxLen < rightLen + leftLen)
			maxLen = rightLen + leftLen;
		rightLen = 0;
		leftLen = 0;
	}
	printf("%d\n", maxLen);

	return 0;
}

