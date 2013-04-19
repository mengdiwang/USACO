/*
ID:wangmengd1
LANG:C++
TASK:cowtour
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
#define INNAME "cowtour.in"
#define OUTNAME "cowtour.out"
const double eps = 1e-7;
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
inline void checkmin(double &a,double b){if(b<a)a=b;}//NOTES:checkmax 
inline void checkmax(double &a,double b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
struct TPoint
{
	int x;
	int y;
}p[152];
//------------------------------------------
int N;
int colN = 0;
char board[152][152] = {0};
double dis[152][152] = {0};
int color[152] = {0};
double maxdis[152] = {0};
vector<int> colorSet[152];
//------------------------------------------
double count_dis(int a, int b)
{
		return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y)+0.0);
}
//------------------------------------------
void read_and_init()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	memset(color, -1, sizeof(color));
	memset(maxdis, 0, sizeof(maxdis));
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d ", &p[i].x, &p[i].y);

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%c ", &board[i][j]);
			if(i==j) dis[i][j] = 0;
			else if(board[i][j] == '1')
				dis[i][j] = count_dis(i,j);
			else 
				dis[i][j] = 1e20;
		}
	}
}
//------------------------------------------
bool floodfill(int i, int col)
{
	if(color[i]!=-1)
		return false;

	color[i] = col;
	colorSet[col].push_back(i);
	for(int j=0; j<N; j++)
		if(board[i][j]=='1')
			floodfill(j, col);

	return true;
};
//------------------------------------------
void find_con()
{
	for(int i=0; i<N; i++)
		if(floodfill(i, colN))
			colN ++;
}
//------------------------------------------
void floyd()
{
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				checkmin(dis[i][j], dis[i][k]+dis[k][j]);

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(dis[i][j] != 1e20 && dis[i][j]>maxdis[i])
				maxdis[i] = dis[i][j];
}
//------------------------------------------
void print_ans()
{
	if(colN == 1)
	{
		int maxd = 0;
		for(int i=0; i<N; i++)
			checkmax(maxd, maxdis[i]);
		printf("%.6lf\n", maxd);
	}
	else
	{
		int a = colorSet[0][0];
		int b = colorSet[colN-1][0];
		double mindis = maxdis[a]+maxdis[b]+count_dis(a, b);

		for(int i=0; i<colN; i++)
			for(int j=i+1; j<colN; j++)
				for(int k=0; k<colorSet[i].size(); k++)
					for(int h=0; h<colorSet[j].size(); h++)
						checkmin(mindis, 
						maxdis[colorSet[i][k]]+maxdis[colorSet[j][h]]+
						count_dis(colorSet[i][k],colorSet[j][h]));

		for(int i=0; i<N; i++)
			checkmax(mindis, maxdis[i]);

		printf("%.6lf\n", mindis);
	}	
/*
	double res = 1e20;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(dis[i][j]==1e20)
				checkmin(res, count_dis(i, j)+maxdis[i]+maxdis[j]);

	for(int i=0; i<N; i++)
		checkmax(res, maxdis[i]);
	
	printf("%.6lf\n", res);
*/

}
//------------------------------------------
int main()
{
	read_and_init();
	floyd();
	find_con();
	print_ans();

	return 0;
}
