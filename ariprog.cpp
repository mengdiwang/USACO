/*
ID:wangmengd1
LANG:C++
TASK:ariprog
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
#define INNAME "ariprog.in"
#define OUTNAME "ariprog.out"
//------------------------------------------

inline void checkmin(int &a, int b)
{
    if (b < a) a = b;
}//NOTES:checkmin

inline void checkmax(int &a, int b)
{
    if (b > a) a = b;
}//NOTES:checkmax
//------------------------------------------

struct TAP
{
    int a;
    int b;
};
//------------------------------------------

bool comp(const TAP &a, const TAP &b)
{
    if (a.b == b.b)
        return (a.a < b.a);
    return a.b < b.b;
}
//------------------------------------------
bool num[125002] = {0};
int sqnum[40001] = {0};
TAP ap[10001] = {0};
int N, M, maxN;
//------------------------------------------

void Calc(int M)
{
    for (int i = 0; i <= M; i++)
    {
        for (int j = i; j <= M; j++)
        {
            num[i * i + j * j] = true;
        }
    }
}
//------------------------------------------

int GenSqlnum()
{
    int j = 0;
    for (int i = 0; i <= maxN; i++)
    {
        if (num[i])
            sqnum[j++] = i;
    }

    return j;
}
//------------------------------------------

int CountN(int t)
{
    int an = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = i + 1; j < t; j++)
        {
            if ((2 - N) * sqnum[i] + sqnum[j]*(N - 1) > maxN)
                break;
            //如果list[i]+(list[j]-list[i])×(n-1)>lim（lim是最大可能的bisquare）
            bool IsOk = true;
            for (int k = 1; k <= N - 2; k++)
            {
                if (!num[(sqnum[j] - sqnum[i]) * k + sqnum[j]])
                {
                    IsOk = false;
                    break;
                }
            }
            if (IsOk)
            {
                ap[an].a = sqnum[i];
                ap[an].b = sqnum[j] - sqnum[i];
                an++;
            }
        }
    }

    return an;
}
//------------------------------------------

int main()
{
    freopen(INNAME, "r", stdin);
    freopen(OUTNAME, "w", stdout);

    int an = 0;
    scanf("%d %d", &N, &M);
    maxN = 2 * M*M;

    Calc(M);
    int t = GenSqlnum();
    if (an = CountN(t))
    {
        sort(ap, ap + an, comp);
        for (int i = 0; i < an; i++)
            printf("%d %d\n", ap[i].a, ap[i].b);
    }
    else
    {
        printf("NONE\n");
    }

    return 0;
}
