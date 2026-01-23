#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> G[3001],cycle;
int parent[3001],state[3001];
int s,e;
bool findCycle;
int ret[3001];

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int u,v;
        cin>>u>>v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1;i<=N;i++)
        ret[i]=-1;
}

void dfs(int u,int p)
{
    state[u]=1;
    parent[u]=p;

    for(int v:G[u])
    {
        if(v==p) continue;

        if(state[v]==0) dfs(v,u);
        else if(state[v]==1)
        {
            findCycle=true;
            s=v;
            e=u;
        }
    }

    state[u]=2;
}

void getDist()
{
    queue<int> q;

    for(int c:cycle)
    {
        ret[c]=0;
        q.push(c);
    }

    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        for(int next:G[now])
        {
            if(ret[next]!=-1) continue;
            ret[next]=ret[now]+1;
            q.push(next);
        }
    }
}

void solve()
{
    dfs(1,0);
    
    cycle.push_back(e);
    while(e!=s)
    {
        e=parent[e];
        cycle.push_back(e);
    }

    getDist();
}

void printRet()
{
    for(int i=1;i<=N;i++)
        cout<<ret[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
    printRet();
}