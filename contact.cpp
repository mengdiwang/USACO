/*
ID:wangmengd1
LANG:C++
TASK:contact
*/

#include <memory.h>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//------------------------------------------
#define INNAME "contact.in"
#define OUTNAME "contact.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
int A, B, N;
string instr, str = "";
map<string, int> mp;
map<string, int>::iterator it;
vector<pair<int, string> > vt;
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d %d %d ", &A, &B, &N);
	while(getline(cin, instr))
		str += instr;
}
//------------------------------------------
void print_answer()
{
	int oldsize = -1;
	int countN = 0;
	int countL = 0;
	for(int i=0; i<vt.size(); i++)
	{
		if(oldsize==-1)
		{
			countL = 0;
			countN ++;
			if(countN>N) break;
			printf("%d\n%s", vt[i].first, vt[i].second.c_str());
			oldsize = vt[i].first;		
		}
		else if(oldsize == vt[i].first)
		{
			countL ++;
			printf("%c%s", !(countL%6)?'\n': ' ', vt[i].second.c_str());
		}
		else 
		{
			countN ++;
			countL = 0;
			if(countN>N) break;
			printf("\n%d\n%s", vt[i].first, vt[i].second.c_str());
			oldsize = vt[i].first;
		}
	}
	printf("\n");
}
//------------------------------------------
bool cmp(const pair<int, string> &a, const pair<int, string> &b)
{
	if(a.first > b.first) return true;
	if(a.first < b.first) return false;
	if(a.second.length()<b.second.length()) return true;
	if(a.second.length()>b.second.length()) return false;
	return strcmp(a.second.c_str(), b.second.c_str())<0;
	//return a.second < b.second;
}
//------------------------------------------
void main_alg()
{
	for(int i=A; i<=B; i++)
		for(int j=0; j+i<=str.length(); j++)
			mp[str.substr(j,i)]++;
	
	for(it = mp.begin(); it!=mp.end(); it++)
		vt.push_back(pair<int, string>(it->second, it->first));
	
	sort(vt.begin(), vt.end(), cmp);
}
//------------------------------------------
int main()
{
	read_and_init();
	main_alg();
	print_answer();

	return 0;
}
//------------------------------------------
