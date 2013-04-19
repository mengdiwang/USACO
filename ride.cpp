/*
ID:wangmengd1
LANG:C++
TASK:ride
*/

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
//---------------------------------------
char input[7];
char comment[7];
//---------------------------------------
int main()
{
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);

	int sumi = 1;
	int sumc = 1;

	gets(input);
	gets(comment);
	for(int i=0; i<strlen(input); i++)
		sumi *= (input[i]-'A'+1);	
	for(int i=0; i<strlen(comment); i++)
		sumc *= (comment[i]-'A'+1);

	if(sumi%47 == sumc%47)
		printf("GO\n");
	else
		printf("STAY\n");

	return 0;
}

