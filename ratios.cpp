/*
ID:wangmengd1
LANG:C++
TASK:ratios
*/
//行列式解法
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
#include <cstdlib>
using namespace std;
//------------------------------------------
ifstream fin("ratios.in");
ofstream fout("ratios.out");
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
/*
int gcd(int a, int b)
{
	while(b^=a^=b^=a%=b);
	return a;
}
*/

int gcd( int a, int b )
{
	int c;
	while(a!=0)
	{
		c = a; a = b%a; b = c;
	}
	
	return b;
}

int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}

int main()
{
	int x[4],y[4],z[4],p[4];
	for(int i=1; i<4; i++)
		fin>>p[i];
	for(int i=1; i<4; i++)
		fin>>x[i];
	for(int i=1; i<4; i++)
		fin>>y[i];
	for(int i=1; i<4; i++)
		fin>>z[i];
	
	int D = x[1]*y[2]*z[3] + y[1]*z[2]*x[3] + z[1]*x[2]*y[3]
		- (x[1] *z[2] * y[3] + y[1]*x[2]*z[3] + z[1]*y[2]*x[3]);
	if(D==0)
	{
		fout << "NONE" << endl;
		return 0;
	}
	
	int a, b, c;
	a = p[1]*y[2]*z[3] + y[1]*z[2]*p[3] + z[1]*p[2]*y[3]
		- (p[1]*z[2]*y[3] + y[1]*p[2]*z[3] + z[1]*y[2]*p[3]);
	b = x[1]*p[2]*z[3] + p[1]*z[2]*x[3] + z[1]*x[2]*p[3]
		- (x[1]*z[2]*p[3] + p[1]*x[2]*z[3] + z[1]*p[2]*x[3]);
	c = x[1]*y[2]*p[3] + y[1]*p[2]*x[3] + p[1]*x[2]*y[3]
		- (x[1]*p[2]*y[3] + y[1]*x[2]*p[3] + p[1]*y[2]*x[3]);
	
	if(D<0)
	{
		a = -a;
		b = -b;
		c = -c;
		D = -D;
	}
	
	if(a<0 || b<0 || c<0)
	{
		fout << "NONE" << endl;
		return 0;
	}
	
	int d = gcd(gcd(a,(gcd(b,c))),D);
	fout << a/d << " " << b/d  << " " << c/d << " " << D/d << endl;
	
	return 0;
}
