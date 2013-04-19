/*
ID:wangmengd1
LANG:C++
TASK:agrinet
*/

#include <memory.h>
#include <string.h>
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
#define INNAME "agrinet.in"
#define OUTNAME "agrinet.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
//<declare part>
const int inf = 1e20;
const int maxN = 102;
int N;
int g[maxN][maxN] = {0};
int dis[maxN] = {0};
bool intree[maxN] = {0};
bool source[maxN] = {0};
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			scanf("%d", &g[i][j]);
}
//------------------------------------------
int prim(int g[][maxN], int n) //最小生成树PRIM算法
{
	int lowcost[maxN],prevex[maxN],m=0; //LOWCOST[]存储当前集合U分别到剩余结点的最短路径
	//prevex[]存储最短路径在U中的结点
	int i,j,k,min; 

	for(i=2;i<=n;i++) //n个顶点，n-1条边 
	{
		lowcost[i]=g[1][i]; //初始化 
		prevex[i]=1; //顶点未加入到最小生成树中 
	} 

	lowcost[1]=0; //标志顶点1加入U集合 
	for(i=2;i<=n;i++) //形成n-1条边的生成树 
	{
		min=inf; 
		k=0; 
		for(j=2;j<=n;j++) //寻找满足边的一个顶点在U,另一个顶点在V的最小边 
			if((lowcost[j]<min)&&(lowcost[j]!=0)) 
			{
				min=lowcost[j]; 
				k=j; 
			} 
			m+=min;
			//      printf("(%d,%d)%d\t",prevex[k]-1,k-1,min); 
			lowcost[k]=0; //顶点k加入U 
			for(j=2;j<=n;j++) //修改由顶点k到其他顶点边的权值 
				if(g[k][j]<lowcost[j]) 
				{
					lowcost[j]=g[k][j]; 
					prevex[j]=k; 
				} 
	}   
	printf("%d\n", m);  
	return 0;
} 
//------------------------------------------
void print_answer()
{
	
}
//------------------------------------------
int main()
{
	read_and_init();
	prim(g, N);
	print_answer();

	return 0;
}
