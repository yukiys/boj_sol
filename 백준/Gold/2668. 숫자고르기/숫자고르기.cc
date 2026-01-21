#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int edge[101];
int state[101],parent[101];
bool findCycle;
int s,e;
vector<int> ret;

void init()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>edge[i];
}

void dfs(int u,int p)
{
    state[u]=1;
    parent[u]=p;

    int v=edge[u];

    if(state[v]==0) dfs(v,u);
    else if(state[v]==1)
    {
        findCycle=true;
        s=v;
        e=u;
    }

    state[u]=2;
}

void solve()
{
    for(int i=1;i<=N;i++)
    {
        if(state[i]!=0) continue;
        dfs(i,0);

        if(findCycle)
        {
            ret.push_back(e);
            while(e!=s)
            {
                e=parent[e];
                ret.push_back(e);
            }

            findCycle=false;
        }
    }

    sort(ret.begin(),ret.end());
}

void printRet()
{
    cout<<ret.size()<<"\n";
    for(int i=0;i<ret.size();i++)
        cout<<ret[i]<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}