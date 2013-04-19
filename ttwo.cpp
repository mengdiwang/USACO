/*
ID:wangmengd1
LANG:C++
TASK:ttwo
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
#define INNAME "ttwo.in"
#define OUTNAME "ttwo.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
//------------------------------------------
char board[10][10] = {0};
bool cvisited[10][10] = {0};
bool fvisited[10][10] = {0};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//------------------------------------------
void mymove(int &x, int &y, int &m)
{
	int nx = x + dir[m][0];
	int ny = y + dir[m][1];

	if(nx<0 || nx>=10 || ny<0 || ny>=10 || board[nx][ny]=='*')
	{
		m = (m+1)%4;
	}
	else
	{
		x = nx; y = ny;
	}
}
//------------------------------------------
int main()
{
//	freopen(INNAME, "r", stdin);
//	freopen(OUTNAME, "w", stdout);

	FILE *fin, *fout;
	char buf[100];
	fin = fopen("ttwo.in", "r");
	fout = fopen("ttwo.out", "w");

	int sfx, sfy, scx, scy;
	for(int i=0; i<10; i++)
	{
		fgets(buf, sizeof(buf), fin);
		for(int j=0; j<10; j++)
		{
			board[i][j] = buf[j];
			if(board[i][j] == 'F')
			{
				sfx = i; sfy = j;board[i][j] = '.';
			}
			if(board[i][j] == 'C')
			{
				scx = i; scy = j;board[i][j] = '.';
			}
		}
	}

	int fx = sfx, cx = scx, fy = sfy, cy = scy, fm = 0, cm = 0;

	int i;
	for(i=0; i<160000 && (scx!=sfx || scy != sfy); i++)
	{
		mymove(scx, scy, cm);
		mymove(sfx, sfy, fm);
	}

	if(scx==sfx && scy==sfy)
		fprintf(fout, "%d\n", i);
	else
		fprintf(fout, "0\n");

	return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char grid[10][10];


int deltay[] = { -1, 0, 1, 0 };

void
	move(int *x, int *y, int *dir)
{
	int nx, ny;

	nx = *x+deltax[*dir];
	ny = *y+deltay[*dir];

	if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || grid[ny][nx] == '*')
		*dir = (*dir + 1) % 4;
	else {
		*x = nx;
		*y = ny;
	}
}

void
	main(void)
{
	FILE *fin, *fout;
	char buf[100];
	int i, x, y;
	int cowx, cowy, johnx, johny, cowdir, johndir;


	fin = fopen("ttwo.in", "r");
	fout = fopen("ttwo.out", "w");
	assert(fin != NULL && fout != NULL);

	cowx = cowy = johnx = johny = -1;

	for(y=0; y<10; y++) {
		fgets(buf, sizeof buf, fin);
		for(x=0; x<10; x++) {
			grid[y][x] = buf[x];
			if(buf[x] == 'C') {
				cowx = x;
				cowy = y;
				grid[y][x] = '.';
			}
			if(buf[x] == 'F') {
				johnx = x;
				johny = y;
				grid[y][x] = '.';
			}
		}
	}

	assert(cowx >= 0 && cowy >= 0 && johnx >= 0 && johny >= 0);

	cowdir = johndir = 0;	

	for(i=0; i<160000 && (cowx != johnx || cowy != johny); i++) {
		move(&cowx, &cowy, &cowdir);
		move(&johnx, &johny, &johndir);
	}

	if(cowx == johnx && cowy == johny)
		fprintf(fout, "%d\n", i);
	else
		fprintf(fout, "0\n");
	exit(0);
}*/