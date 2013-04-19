/*
ID:wangmengd1
LANG:C++
TASK:gift1
*/

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
//---------------------------------------------
int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	
	int n, amount, m;
	map<string, int>giftMap;
	map<string, int>::iterator iter;
	map<int, string>nameMap;
	map<int, string>::iterator niter;
	string stu, gived;

	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		cin >> stu;
		giftMap.insert(pair<string, int>(stu, 0));	
		nameMap.insert(pair<int, string>(i, stu));
	}
	for(int i=0; i<n; i++)
	{
		cin >> stu;
		cin >> amount >> m;
		for(int j=0; j<m; j++)
		{	
			cin >> gived;
			iter = giftMap.find(gived);
			iter->second += amount/m;
		}
		
		iter = giftMap.find(stu);
		iter->second -= amount;
		if(m)
			iter->second += amount%m;
		else
			iter->second += amount;
	}
	
	for(niter = nameMap.begin();
		niter != nameMap.end();
		niter++)
	{
		iter = giftMap.find(niter->second);
		cout << iter->first << ' ' << iter->second << endl;
	}

	return 0;
}

