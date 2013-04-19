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
int prim(int g[][maxN], int n) //��С������PRIM�㷨
{
	int lowcost[maxN],prevex[maxN],m=0; //LOWCOST[]�洢��ǰ����U�ֱ�ʣ��������·��
	//prevex[]�洢���·����U�еĽ��
	int i,j,k,min; 

	for(i=2;i<=n;i++) //n�����㣬n-1���� 
	{
		lowcost[i]=g[1][i]; //��ʼ�� 
		prevex[i]=1; //����δ���뵽��С�������� 
	} 

	lowcost[1]=0; //��־����1����U���� 
	for(i=2;i<=n;i++) //�γ�n-1���ߵ������� 
	{
		min=inf; 
		k=0; 
		for(j=2;j<=n;j++) //Ѱ������ߵ�һ��������U,��һ��������V����С�� 
			if((lowcost[j]<min)&&(lowcost[j]!=0)) 
			{
				min=lowcost[j]; 
				k=j; 
			} 
			m+=min;
			//      printf("(%d,%d)%d\t",prevex[k]-1,k-1,min); 
			lowcost[k]=0; //����k����U 
			for(j=2;j<=n;j++) //�޸��ɶ���k����������ߵ�Ȩֵ 
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
