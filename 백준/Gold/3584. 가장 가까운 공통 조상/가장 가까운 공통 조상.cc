#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T,N,A,B;
vector<int> G[10001];
int up[15][10001];
int depth[10001];
int parent[10001];

void init()
{
    cin>>N;

    for(int node=1;node<=N;node++)
    {
        G[node].clear();
        for(int k=0;k<=14;k++)
            up[k][node]=0;
        depth[node]=0;
        parent[node]=0;
    }

    for(int i=0;i<N-1;i++)
    {
        cin>>A>>B;

        G[A].push_back(B);
        parent[B]=A;
    }
    cin>>A>>B;
}

int lca(int a,int b)
{
    if(depth[a]<depth[b]) swap(a,b);
    
    int diff=depth[a]-depth[b];
    for(int k=0;k<=14;k++)
        if(diff & (1<<k))
            a=up[k][a];
    
    if(a==b) return a;

    for(int k=14;k>=0;k--)
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
    
    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        for(int next:G[now])
        {
            up[0][next]=now;
            depth[next]=depth[now]+1;
            q.push(next);
        }
    }
}

void solve()
{
    int root;
    for(int i=1;i<=N;i++)
    {
        if(parent[i]==0)
        {
            root=i;
            break;
        }
    }
     
    bfs(root);

    for(int k=1;k<=14;k++)
    {
        for(int node=1;node<=N;node++)
        {
            int mid=up[k-1][node];
            up[k][node]=(mid?up[k-1][mid]:0);
        }
    }
}

void printRet()
{
    cout<<lca(A,B)<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--)
    {
        init();
        solve();
        printRet();
    }
}