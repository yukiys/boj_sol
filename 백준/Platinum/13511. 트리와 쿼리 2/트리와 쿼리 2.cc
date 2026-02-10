#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
vector<pair<int,int>> G[100001];
int up[18][100001];
int depth[100001];
long long dist[100001];
bool visited[100001];

void init()
{
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
}

int lca(int a,int b)
{
    if(depth[a]<depth[b]) swap(a,b);

    int diff=depth[a]-depth[b];
    for(int k=0;k<=17;k++)
        if(diff & (1<<k))
            a=up[k][a];

    if(a==b) return a;

    for(int k=17;k>=0;k--)
    {
        if(up[k][a]!=up[k][b])
        {
            a=up[k][a];
            b=up[k][b];
        }
    }

    return up[0][a];
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

        for(auto[next,cost]:G[now])
        {
            if(visited[next]) continue;

            q.push(next);
            up[0][next]=now;
            depth[next]=depth[now]+1;
            dist[next]=dist[now]+cost;
            visited[next]=true;
        }
    }
}

int jump(int j,int node)
{
    for(int k=0;k<=17;k++)
        if(j & (1<<k))
            node=up[k][node];
    return node;
}

void solve()
{
    bfs(1);

    for(int k=1;k<=17;k++)
    {
        for(int node=1;node<=N;node++)
        {
            int mid=up[k-1][node];
            up[k][node]=(mid?up[k-1][mid]:0);
        }
    }

    cin>>M;
    for(int i=0;i<M;i++)
    {
        int op,u,v;
        cin>>op>>u>>v;

        int L=lca(u,v);

        if(op==1) cout<<dist[u]+dist[v]-2LL*dist[L]<<"\n";
        else
        {
            int k;
            cin>>k;
            
            int len1=depth[u]-depth[L];
            int len2=depth[v]-depth[L];

            if(k-1<=len1) cout<<jump(k-1,u)<<"\n";
            else cout<<jump(len1+len2-(k-1),v)<<"\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}