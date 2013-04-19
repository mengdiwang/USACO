/*
ID:wangmengd1
LANG:C++
TASK:friday
*/

#include "stdafx.h"
#include <stdio.h>
/*
formular:w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
*/
//---------------------------------------
int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);

	int n;
	int days[7] = {0};
	days[6]++;
	days[2]++;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		int y = (1900 + i)%100;
		int c = (1900 + i)/100;
		int d = 13;
		for(int m=3; m<=14; m++)
		{
			int w = y+y/4+c/4-2*c+26*(m+1)/10+d-1;
			w = (w % 7 + 7 ) % 7;
			if(!(i==n-1 && m>=13))
				days[w]++;
		}
	}

	for(int i=6; i<=12; i++)
		printf("%d%c", days[i%7], (i==12)?'\n':' ');

	return 0;
}

