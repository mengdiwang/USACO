/*
ID:wangmengd1
LANG:C++
TASK:comehome
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
#define INNAME "comehome.in"
#define OUTNAME "comehome.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax 
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase( 
//------------------------------------------
const int inf = 999999999;
int board[60][60];
bool visited[60] = {0};
int dis[60] = {0};
int N;
//------------------------------------------
void dijkstra()
{
	for(int i=0; i<60; i++)
		dis[i] = inf;
	
	dis['Z'-'A'] = 0;
	int v = 'Z'-'A', w, wgt;

	while(!visited[v])
	{
		visited[v] = true;
		for(int i=0; i<60; i++)
		{
			if(board[v][i]!=-1)
			{
				w = i;
				wgt = board[v][i];
				if(dis[w]>dis[v]+wgt)
					dis[w] = dis[v]+wgt;
			}
		}

		v = 0;
		int dist = inf;
		for(int i=0; i<60; i++)
		{
			if(!visited[i] && dist>dis[i])
			{
				dist = dis[i];
				v = i;
			}
		}
	}
}
//------------------------------------------
void init_and_read()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);
	memset(board, -1, sizeof(board));
	scanf("%d\n", &N);

	char u, v;
	int c;
	for(int i=0; i<N; i++)
	{
		cin >> u >> v >> c;
		if(board[u-'A'][v-'A']==-1 || board[u-'A'][v-'A'] > c)
		{
			board[u-'A'][v-'A'] = c;
			board[v-'A'][u-'A'] = c;
		}
	}
}
//------------------------------------------
void get_answer()
{
	char u;
	int dist = inf;
	for(int i=0; i<60; i++)
	{
		if(dist>dis[i] && dis[i]!=0 && isUpperCase(char(i+'A')))
		{
			u = char(i + 'A');
			dist = dis[i];
		}
	}

	printf("%c %d\n", u, dist);
}
//------------------------------------------
int main()
{
	init_and_read();
	dijkstra();
	get_answer();

	return 0;
}
