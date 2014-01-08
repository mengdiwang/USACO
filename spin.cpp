/*
ID:wangmengd1
LANG:C++
TASK:spin
*/
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include <bitset>
#include <cstdlib>
using namespace std;
//------------------------------------------
ifstream fin("spin.in");
ofstream fout("spin.out");
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------

int main()
{	
	std::bitset<360> now[6], tmp;
	int speed[6];
	
	for(int i=0; i<5; i++)
	{
		int num;
		fin>>speed[i] >> num;
		for(int j=0; j<num; j++)
		{
			int st, wid;
			fin >> st >> wid;
			for(int k=st; k<=st+wid; k++)
			{
				now[i].set(k%360);
			}
		}
	}
	
	for(int t=0; t<360; t++)
	{
		for(int i=0; i<360; i++)
		{
			int flag = 0;
			for(int j=0; j<5; j++)
			{
				if(now[j].test(i)==false)
				{
					flag = 1;
					break;
				}	
			}	
			if(flag == 0)
			{
				fout << t << endl; 
				return 0; 
			}	
		}
		
		for(int j=0; j<5; j++)
		{
			for(int i=0; i<360; i++)
			{
				tmp[i] = now[j][(i-speed[j]+360)%360];//the line is in the opposite director
			}
			now[j] = tmp;
		}
	}
	
	fout << "none" << endl;

	return 0;
}
