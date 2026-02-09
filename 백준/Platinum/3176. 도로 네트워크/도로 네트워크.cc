#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,K,D,E,minRet,maxRet;
vector<pair<int,int>> G[100001];
int up[18][100001];
int depth[100001];
int m[18][100001],M[18][100001];
bool visited[100001];

void init()
{
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int A,B,C;
        cin>>A>>B>>C;

        G[A].push_back({B,C});
        G[B].push_back({A,C});
    }
}

void lca(int a,int b)
{
    minRet=1e9,maxRet=0;

    if(depth[a]<depth[b]) swap(a,b);

    int diff=depth[a]-depth[b];
    for(int k=0;k<=17;k++)
    {
        if(diff & (1<<k))
        {
            minRet=min(minRet,m[k][a]);
            maxRet=max(maxRet,M[k][a]);
            a=up[k][a];
        }
    }

    if(a==b) return;

    for(int k=17;k>=0;k--)
    {
        if(up[k][a]!=up[k][b])
        {
            minRet=min(minRet,m[k][a]);
            maxRet=max(maxRet,M[k][a]);

            minRet=min(minRet,m[k][b]);
            maxRet=max(maxRet,M[k][b]);

            a=up[k][a];
            b=up[k][b];
        }
    }

    minRet=min(minRet,m[0][a]);
    maxRet=max(maxRet,M[0][a]);

    minRet=min(minRet,m[0][b]);
    maxRet=max(maxRet,M[0][b]);
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    up[0][start]=0;
    depth[start]=0;
    m[0][start]=1e9;
    M[0][start]=0;
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
            m[0][next]=M[0][next]=cost;
            visited[next]=true;
        }
    }
}

void solve()
{
    bfs(1);

    for(int k=1;k<=17;k++)
    {
        for(int node=1;node<=N;node++)
        {
            int mid=up[k-1][node];

            if(mid==0)
            {
                up[k][node]=0;
                m[k][node]=m[k-1][node];
                M[k][node]=M[k-1][node];
            }
            else
            {
                up[k][node]=up[k-1][mid];
                m[k][node]=min(m[k-1][node],m[k-1][mid]);
                M[k][node]=max(M[k-1][node],M[k-1][mid]);
            }
        }
    }

    cin>>K;
    for(int i=0;i<K;i++)
    {
        cin>>D>>E;

        lca(D,E);
        
        cout<<minRet<<" "<<maxRet<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}