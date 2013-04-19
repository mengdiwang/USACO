/*
ID:wangmengd1
LANG:C++
TASK:pprime
*/

#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <cstdlib>
using namespace std;
//------------------------------------------
#define INNAME "pprime.in"
#define OUTNAME "pprime.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int base10[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
//------------------------------------------
bool Isprime(int n)
{
	int i;
	for(i=2;i<int(sqrt(double(n)))+1;++i)
		if(n%i==0)
			return false;

	return true;
}
//------------------------------------------

bool Gen1(int a, int b)
{
	if(9 < a)
		return true;

	int ans[4] = {2,3,5,7};

	for(int i=0; i<4; i++)
	{
		if(ans[i]<b)
		{
			if(ans[i]>=a)
				printf("%d\n", ans[i]);
			else
				continue;
		}
		else
		{
			return false;
		}
	}

	return true;
}
//------------------------------------------
bool Gen2(int a, int b)
{
	if(99 < a)
		return true;

	if(11 <= b)
	{
		if(11>=a)
			printf("11\n");
	}
	else
	{
		return false;
	}
	return true;
	
}
//------------------------------------------
bool Gen3(int a, int b)
{
	if(999 < a)
		return true;

	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			int palindrome = 100*d1 + 10*d2 + d1;
			if(palindrome <=b)
			{	
				if(Isprime(palindrome) && palindrome>=a)
					printf("%d\n", palindrome);
				else
					continue;
			}
			else
			{
				return false;
			}
		}

	}
	return true;
}
//------------------------------------------
bool Gen4(int a, int b)
{
	if(9999 < a)
		return true;

	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			int palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
			if(palindrome <=b)
			{	
				if(Isprime(palindrome) && palindrome>=a)
					printf("%d\n", palindrome);
				else
					continue;
			}
			else
			{
					return false;
			}
		}

	}
	return true;
}
//------------------------------------------
bool Gen5(int a, int b)
{
	if(99999 < a)
		return true;
	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++) 
			{
				int palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
				if(palindrome <=b)
				{	
					if(Isprime(palindrome) && palindrome>=a)
						printf("%d\n", palindrome);
					else
						continue;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}
//------------------------------------------
bool Gen6(int a, int b)
{
	if(999999 < a)
		return true;
	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++) 
			{
				int palindrome = 100000*d1 + 10000*d2 + 1000*d3 +100*d3 + 10*d2 + d1;
				if(palindrome <=b)
				{	
					if(Isprime(palindrome) && palindrome>=a)
						printf("%d\n", palindrome);
					else
						continue;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;

}
//------------------------------------------
bool Gen7(int a, int b)
{
	if(9999999 < a)
		return true;
	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++) 
			{
				for(int d4 = 0; d4 <= 9; d4++)
				{
					int palindrome = 1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
					if(palindrome <=b)
					{	
						if(Isprime(palindrome) && palindrome>=a)
							printf("%d\n", palindrome);
						else
							continue;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
//------------------------------------------
bool Gen8(int a, int b)
{
	if(99999999 < a)
		return true;
	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++) 
			{
				for(int d4 = 0; d4 <= 9; d4++)
				{
					int palindrome = 10000000*d1 + 1000000*d2 + 100000*d3 +10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
					if(palindrome <=b)
					{	
						if(Isprime(palindrome) && palindrome>=a)
							printf("%d\n", palindrome);
						else
							continue;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
//------------------------------------------
bool Gen9(int a, int b)
{
	if(999999999 < a)
		return true;
	for (int d1 = 1; d1 <= 9; d1+=2) 
	{	/* only odd; evens aren't so prime */
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++) 
			{
				for (int d4 = 0; d4 <= 9; d4++) 
				{
					for (int d5 = 0; d5 <= 9; d5++) 
					{
						int palindrome = 100000000*d1 + 10000000*d2 + 1000000*d3 + 100000*d4
							+ 10000*d5 + 1000*d4 + 100*d3 + 10*d2 + d1;
						if(palindrome <=b)
						{	
							if(Isprime(palindrome) && palindrome>=a)
								printf("%d\n", palindrome);
							else
								continue;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int a, b;
	scanf("%d %d", &a, &b);

	if(Gen1(a, b))
		if(Gen2(a,b))
			if(Gen3(a, b))
				if(Gen4(a,b))
					if(Gen5(a,b))
						if(Gen6(a,b))
							if(Gen6(a,b))
								if(Gen7(a,b))
									if(Gen8(a,b))
										if(Gen9(a,b))
											;

	return 0;
}
