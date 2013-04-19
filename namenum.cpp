/*
ID:wangmengd1
LANG:C++
TASK:namenum
*/

#include "stdafx.h"
#include <cstdio>
#include <map>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//------------------------------------------
#define INNAME "namenum.in"
#define OUTNAME "namenum.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
string name;
string num;
int dicmap[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
priority_queue<string, vector<string>, greater<string> > pq;
string notuse;
long long n, inNum;
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);
	fstream dict_in("dict.txt");

	cin>>inNum;

	while(dict_in>>name)
	{
		stringstream ss(notuse);
		num = name;
		for(int i=0; i<name.length(); i++)
		{
			int pos = name[i] -'A';
			num[i] = dicmap[pos] + '0';
		}

		ss << num;
		ss >> n;

		if(inNum == n)
		{
			pq.push(name);
		}
	}

	if(!pq.size())
	{
		cout << "NONE" << endl;
	}
	else
	{
		while(!pq.empty())
		{
			string toPrint;
			toPrint = pq.top();
			cout << toPrint << endl;
			pq.pop();
		}
	}

	return 0;
}
