/*
ID:wangmengd1
LANG:C++
TASK:crypt1
*/

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------
int num[10];
//------------------------------------------
#define INNAME "crypt1.in"
#define OUTNAME "crypt1.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;} 
inline void checkmax(int &a,int b){if(b>a) a=b;} 
//------------------------------------------
bool Check(int m, int n)
{
	int b;
	while(m>0)
	{
		b = m%10;
		bool isIn = false;
		for(int i=0; i<n; i++)
			if(b == num[i])
				isIn = true;
		if(!isIn)
			return false;
		m /= 10;
	}
	return true;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int n;
	scanf("%d", &n);
	for(int	i=0; i<n; i++)
		scanf("%d", &num[i]);
	
	int count = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				for(int h=0; h<n; h++)
				{

					int ls = (num[i]*100 + num[j]*10 + num[k]) * num[h];
					if(ls>999 || !Check(ls, n))
						continue;

					for(int l=0; l<n; l++)
					{
						int fr = (num[i]*100 + num[j]*10 + num[k]) * (10*num[h]+num[l]);
						int lx = (num[i]*100 + num[j]*10 + num[k]) * num[l];
						if(lx>999 || !Check(lx, n))
							continue;
						else if(fr>9999 || !Check(fr,n))
							continue;
						else
							count ++;
					}
				}
			}

		}
	}
	printf("%d\n", count);

	return 0;
}