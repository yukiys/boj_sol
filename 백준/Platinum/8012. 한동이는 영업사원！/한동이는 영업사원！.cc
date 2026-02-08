#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
long long ret;
vector<int> G[30001];
int path[5000];
int up[16][30001];
int depth[30001];
long long dist[30001];
bool visited[30001];

void init()
{
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    cin>>M;
    for(int i=0;i<M;i++)
        cin>>path[i];
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    up[0][start]=0;
    depth[start]=0;
    dist[start]=0;
    visited[start]=true;

    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        for(int next:G[now])
        {
            if(visited[next]) continue;

            q.push(next);
            up[0][next]=now;
            depth[next]=depth[now]+1;
            dist[next]=dist[now]+1;
            visited[next]=true;
        }
    }
}

int lca(int a,int b)
{
    if(depth[a]<depth[b]) swap(a,b);

    int diff=depth[a]-depth[b];
    for(int k=0;k<=15;k++)
        if(diff & (1<<k))
            a=up[k][a];
    
    if(a==b) return a;

    for(int k=15;k>=0;k--)
    {
        if(up[k][a]!=up[k][b])
        {
            a=up[k][a];
            b=up[k][b];
        }
    }

    return up[0][a];
}

void solve()
{
    bfs(1);

    for(int k=1;k<=15;k++)
    {
        for(int node=1;node<=N;node++)
        {
            int mid=up[k-1][node];
            up[k][node]=(mid?up[k-1][mid]:0);
        }
    }

    for(int i=0;i<M-1;i++)
    {
        int a=path[i];
        int b=path[i+1];

        ret+=dist[a]+dist[b]-2LL*dist[lca(a,b)];
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}