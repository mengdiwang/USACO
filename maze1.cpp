/*
ID:wangmengd1
LANG:C++
TASK:maze1
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
#define INNAME "maze1.in"
#define OUTNAME "maze1.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
char maze[420][420];
int mzdis[420][420][2];
int stpos[2][2];
int W, H;
//------------------------------------------
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
//------------------------------------------
void BFS(int sx, int sy, int count, int ss)
{
	queue<int> q;
	mzdis[sx][sy][ss] = 0;
	q.push(sx);
	q.push(sy);
	q.push(count);
	while(!q.empty())
	{
		int cx = q.front(); q.pop();
		int cy = q.front(); q.pop();
		int cc = q.front(); q.pop();

		for(int i=0; i<4; i++)
		{
			int nx = cx+dir[i][0];
			int ny = cy+dir[i][1];
			if(nx>0 && nx<2*H && ny>0 && ny<2*W && maze[nx][ny] == ' ' && mzdis[nx][ny][ss]==-1)
			{
				q.push(nx);
				q.push(ny);
				if(nx&1 && ny&1)
					cc ++;
				q.push(cc);
				mzdis[nx][ny][ss] = cc;
			}
		}
	}
}
//------------------------------------------
int main()
{
	FILE *fin, *fout;
	char buf[500];
	fin = fopen(INNAME, "r");
	fout = fopen(OUTNAME, "w");
	memset(mzdis, -1, sizeof(mzdis));

	fscanf(fin, "%d %d ", &W, &H);

	for(int i=0; i<H*2+1; i++)
	{
		fgets(buf, sizeof(buf), fin);
		for(int j=0; j<W*2+1; j++)
			maze[i][j] = buf[j];	
	}

	int t=0;
	for(int i=0; i<H*2+1; i++)
	{
		for(int j=0; j<W*2+1; j++)
		{
			if(maze[i][j]==' ' && (i==0 || i==2*H || j==0 || j==2*W))
			{
				stpos[t][0] = i; stpos[t][1] = j;
				t++;
			}
		}
	}

	BFS(stpos[0][0], stpos[0][1], 0, 0);
	BFS(stpos[1][0], stpos[1][1], 0, 1);

	int maxN = 0;
	for(int i=0; i<2*H+1; i++)
		for(int j=0; j<2*W+1; j++)
			{
				checkmin(mzdis[i][j][0], mzdis[i][j][1]);
				checkmax(maxN, mzdis[i][j][0]);	
			}

	fprintf(fout, "%d\n", maxN);

	return 0;
}
