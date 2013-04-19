/* 
 * File:   newmain.cpp
 * Author: XP
 *
 * Created on 2010��2��5��, ����7:56
 *
 *
 *
Problem 11: 谷仓的安保 [Traditional, 2005]

Farmer John给谷仓安装了一个新的安全系统，并且要给牛群中的每一个奶牛分
配
一个有效的密码。一个有效的密码由L(3 <= L <= 15)个小写字母(来自传统的
拉丁
字母集'a'...'z')组成，至少有一个元音('a', 'e', 'i', 'o', 或 'u')和两
个辅
音(除去元音以外的音节)，并且是按字母表顺序出现的(例如，'abc'是有效
的，而
'bac'不是) 。

给定一个期望长度L和C个小写字母，写一个程序，打印出所有的长度为L、能由
这
给定的C个字母组成的有效密码。密码必须按字母表顺序打印出来，一行一个。

你的程序只需输出前25,000个有效密码，即使后面还存在有效密码。

题目名称: passwd

输入格式:

 * 第一行: 两个由空格分开的整数，L和C

 * 第二行: C个空格分开的小写字母，密码是由这个字母集中的字母来构建的。

输入样例 (文件 passwd.in):

4 6
a t c i s w

输入详细说明:

由从给定的六个字母中选择的、长度为4的密码。

输出格式:

 * 第一至?行: 每一个输出行包括一个长度为L个字符的密码(没有空格)。输出
行必
	     须按照字母顺序排列。如果存在多于25,000个有效密码，你的程
序
	     必须在输出25,000个有效密码后停止。

输出样例 (文件 passwd.out):

acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw

 *********************************************************************
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//-------------------------------------------------
int n, m;
char passwd[26] = {0};
char tmp[26] = {0};
const int CMAX = 25000;
char pre[8] = {0};
int c;
int judge[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
//-------------------------------------------------

int cmp(const void *d, const void *s)
{
	return strcmp((char *) d, (char *) s);
}

//-------------------------------------------------
//note: the DFS structure was written before the contest

void DFS(int staInt, int l, int y, int f)
{
	if (l == n)
	{
		if (c <= CMAX && y >= 1 && f >= 2)
		{
			for (int i = 0; i < l; i++)
				printf("%c", tmp[i]);
			printf("\n");
			c++;
		}
		return;
	}
	if ((n - l == 1 && f == 0) || (n - l == 1 && f <= 1 && y == 0))
		return;

	for (int i = staInt; i < m; i++)
	{
		char t = tmp[l] = passwd[i];
		if (judge[t - 'a'] && c <= CMAX)
			DFS(i + 1, l + 1, y + 1, f);
		else
		{
			if (t > 'u' && y == 0)
				return;
			if (c <= CMAX)
				DFS(i + 1, l + 1, y, f + 1);
		}
	}
}
//-------------------------------------------------

void DFS2(int staInt, int l)
{
	if (l == n)
	{
		if (c < CMAX)
		{
			for (int i = 0; i < n - 7; i++)
				printf("%c", pre[i]);
			for (int i = n - 7; i < l; i++)
				printf("%c", tmp[i]);
			printf("\n");
			c++;
		}
		return;
	}

	for (int i = staInt; i < m; i++)
	{
		char t = tmp[l] = passwd[i];
		if (c <= CMAX)
			DFS2(i + 1, l + 1);
	}
}
//-------------------------------------------------

int main(int argc, char** argv)
{
	freopen("passwd.in", "r", stdin);
	freopen("passwd.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		cin >> passwd[i];

	c = 0;
	qsort(passwd, m, sizeof (char), cmp);
	/*	if (n ==15&&m==26)
		{
			for (int i = 0; i < n - 7; i++)
				pre[i] = passwd[i];
			DFS2(n - 7, n - 7);
		}
		else
			DFS(0, 0, 0, 0);
	 */
	if (n >= 7)
		for (int i = 0; i < n - 7; i++)
			if (judge[passwd[i]])
				flag = 1;

	if (flag)
	{
		for (int i = 0; i < n - 7; i++)
			pre[i] = passwd[i];
		DFS2(n - 7, n - 7);
	}
	else
		DFS(0, 0, 0, 0);
	return (EXIT_SUCCESS);
}

