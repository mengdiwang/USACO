/* 
 * File:   newmain.cpp
 * Author: XP
 *
 * Created on 2010��2��5��, ����10:56
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
//-----------------------------------------------
const int N = 5;
int board[N][N];
char note[1000000] = {0};
int total = 0;
//-----------------------------------------------

void DFS(int x, int y, int step, int ID)
{
	if (step == 0)
	{
		ID += board[x][y];
		if (!note[ID])
			total++;
		note[ID]++;
		return;
	}

	for (int i = -1; i <= 1; i += 2)
	{
		if (x+i<=4&&x+i>=0)
		{
			int newID = ID+board[x][y]*pow(10,step);
			DFS(x+i,y,step-1,newID);
		}
		if (y+i<=4&&y+i>=0)
		{
			int newID = ID+board[x][y]*pow(10,step);
			DFS(x,y+i,step-1,newID);
		}
	}

}

//------------------------------------------------

int main(int argc, char** argv)
{
	freopen("numgrid.in","r",stdin);
	freopen("numgrid.out","w",stdout);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	total = 0;
	DFS(0,0,6,0);
	cout <<"f"<<endl;
	printf("%d\n",total);
	return (EXIT_SUCCESS);
}

