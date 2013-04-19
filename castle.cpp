/*
ID:wangmengd1
LANG:C++
TASK:castle
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
#define INNAME "castle.in"
#define OUTNAME "castle.out"
//------------------------------------------
inline bool checkmin(int &a,int b){if(b<a) {a=b; return true;} return false;}//NOTES:checkmin
inline bool checkmax(int &a,int b){if(b>a) {a=b; return true;} return false;}//NOTES:checkmax 
//------------------------------------------
int M, N, tot;
bool Map[54][54][4] = {0};
int visited[550][550];
int con[2505] = {0};
int col = 1;
int oriMax = 0, newMax = 0;
int posx, posy;
char wall;
//------------------------------------------
void assg(int x, int y, int wall)
{
	if(wall >= 8) {wall -= 8; Map[x][y][4] = true;}
	if(wall >= 4) {wall -= 4; Map[x][y][3] = true;}
	if(wall >= 2) {wall -= 2; Map[x][y][2] = true;}
	if(wall >= 1) {wall -= 1; Map[x][y][1] = true;}
}
//------------------------------------------
void ReadIn()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	int tmp;
	scanf("%d %d", &M, &N);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
		{
			scanf("%d", &tmp);
			assg(i,j,tmp);
		}
}
//------------------------------------------
bool floodfill(int x, int y, int col)
{
	if(visited[x][y]!= 0)
		return false;
	
	visited[x][y] = col;
	con[col] ++;
	if(!Map[x][y][4]) floodfill(x+1, y, col);
	if(!Map[x][y][3]) floodfill(x, y+1, col);
	if(!Map[x][y][2]) floodfill(x-1, y, col);
	if(!Map[x][y][1]) floodfill(x, y-1, col);

	return true;
}
//------------------------------------------
void findCon()
{
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			if(floodfill(i, j, col))
				col ++;
}
//------------------------------------------
void GetMax()
{
	for(int i=1; i<col; i++)
		checkmax(oriMax, con[i]);
		
	for(int j=1; j<=M; j++)
	{
		for(int i=N; i>0; i--)
		{
			if(Map[i][j][2] && visited[i][j] != visited[i-1][j])
				if(checkmax(newMax, con[visited[i][j]]+con[visited[i-1][j]]))
				{
					posx = j; posy = i; wall = 'N';
				}
			if(Map[i][j][3] && visited[i][j] != visited[i][j+1])
				if(checkmax(newMax, con[visited[i][j]]+con[visited[i][j+1]]))
				{
					posx = j; posy = i; wall = 'E';
				}
		}
	}
}
//------------------------------------------
void myprint()
{
	printf("%d\n%d\n%d\n", col-1, oriMax, newMax);
	printf("%d %d %c\n", posy, posx, wall);
}
//------------------------------------------
int main()
{
	ReadIn();
	findCon();
	GetMax();
	myprint();

	return 0;
}
