/*
 ID:wangmengd1
 LANG:C++
 TASK:msquare
 */
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <deque>
#include <set>
using namespace std;
//------------------------------------------
ifstream fin("msquare.in");
ofstream fout("msquare.out");
//------------------------------------------
inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin
inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax
//------------------------------------------
string target="12345678";
int Aorder[8] = {7, 6, 5, 4, 3, 2, 1, 0};
int Border[8] = {3, 0, 1, 2, 5, 6, 7, 4};
int Corder[8] = {0, 6, 1, 3, 4, 2, 5, 7};


std::set<string> stateset;

struct TNode
{
    string now;
    int count;
    string order;
    
    TNode(string _now, string _order, int _count)
    {
        now = _now;
        order = _order;
        count = _count;
    }
};

TNode trans()
{
    if(target == "12345678")
    {
        return TNode("","",0);
    }
    stateset.insert("12345678");
    queue<TNode> q;
    TNode newtask = TNode("12345678", "", 0);
    q.push(newtask);
    
    while(q.size()>0)
    {
        TNode task = q.front();
        q.pop();

        string tmp="00000000";
        for(int i=0; i<8; i++)
        {
            tmp[i] = task.now[Aorder[i]];
        }
        if(!stateset.count(tmp))
        {
            string st = task.order;
            st += "A";
            if(tmp == target)
                return TNode(tmp, st, task.count+1);
            stateset.insert(tmp);
            q.push(TNode(tmp, st, task.count+1));
            
        }
        
        for(int i=0; i<8; i++)
        {
            tmp[i] = task.now[Border[i]];
        }
        if(!stateset.count(tmp))
        {
            string st = task.order;
            st += "B";
            
            if(tmp == target)
                return TNode(tmp, st, task.count+1);
            stateset.insert(tmp);
            q.push(TNode(tmp, st, task.count+1));
        }
        
        
        for(int i=0; i<8; i++)
        {
            tmp[i] = task.now[Corder[i]];
        }
        if(!stateset.count(tmp))
        {
            string st = task.order;
            st += "C";
            
            if(tmp == target)
                return TNode(tmp, st, task.count+1);
            stateset.insert(tmp);
            q.push(TNode(tmp, st, task.count+1));
            
        }
    }
    return TNode("","",-1);
}


int main()
{
	string original = "12345678";
    for(int i=0; i<8; i++)
	{
		fin >> target[i];
	}
    
    TNode ans = trans();
    if(ans.count >= 0)
        fout << ans.count << endl << ans.order << endl;
    
	return 0;
}
