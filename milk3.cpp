/*
ID:wangmengd1
LANG:C++
TASK:milk3
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
#define INNAME "milk3.in"
#define OUTNAME "milk3.out"
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a) a=b;}//NOTES:checkmax 
//------------------------------------------
int A, B, C;
bool record[21][21][21] = {0};
vector<int> answer;
//------------------------------------------
void DFS(int a, int b, int c)
{
	if(record[a][b][c])
		return;

	record[a][b][c] = true;

	if(a==0)
		answer.push_back(c);

	if(a<=B-b)	DFS(0, b+a, c);		//A->B
	else	DFS(a+b-B, B, c);
	if(a<=C-b)	DFS(0, b, c+a);		//A->C
	else	DFS(a+c-C, b, C);
	if(b<=A-a)	DFS(a+b, 0, c);		//B->A
	else	DFS(A, b+a-A, c);	
	if(b<=C-c)	DFS(a, 0, b+c);		//B->C
	else	DFS(a, b+c-C, C);		
	if(c<=B-b)	DFS(a, b+c, 0);		//C->B
	else	DFS(a, B, c+b-B);	
	if(c<=A-a)	DFS(c+a, b, 0);		//C->A
	else	DFS(A, b, c+a-A);	
	
	return;
}
//------------------------------------------
int main()
{
	freopen(INNAME, "r", stdin);
	freopen(OUTNAME, "w", stdout);

	scanf("%d %d %d", &A, &B, &C);
	DFS(0, 0, C);

	sort(answer.begin(), answer.end());

	vector<int>::iterator iter = unique(answer.begin(), answer.end());
	answer.erase(iter, answer.end());

	for(int i=0; i<answer.size(); i++)
		printf("%d%c", answer[i], i==answer.size()-1?'\n':' ');

	return 0;
}
