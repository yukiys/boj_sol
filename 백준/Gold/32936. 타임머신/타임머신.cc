#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int N,M;
int a,b,c;
vector<int> edges[200001]; //정방향 그래프
vector<int> rEdges[200001]; //역방향 그래프
long long dist[200001];
long long dist1[200001]; //1->i
long long distToN[200001]; //i->N
long long distToA[200001]; //i->a

long long ret=4e18;
bool useReverse,check;

void input()
{
    cin>>N>>M;
    cin>>a>>b>>c;

    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;

        edges[u].push_back(v);
        rEdges[v].push_back(u);
    }
}

void bfs(int start)
{
    vector<int>* g=useReverse?rEdges:edges;

    for(int i=1;i<=N;i++) dist[i]=INF;

    queue<int> q;
    dist[start]=0;
    q.push(start);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int next:g[cur])
        {
            if(dist[next]==INF)
            {
                dist[next]=dist[cur]+1;
                q.push(next);
            }
        }
    }
}

void solve()
{
    bfs(1);
    for(int i=1;i<=N;i++) dist1[i]=dist[i];

    useReverse=true;
    bfs(N);
    for(int i=1;i<=N;i++) distToN[i]=dist[i];
    
    bfs(a);
    for(int i=1;i<=N;i++) distToA[i]=dist[i];

    if(dist1[a]!=INF and distToA[b]!=INF and distToA[b]<c and (distToN[a]!=INF or distToN[b]!=INF))
    {//1에서 a로 가야 루프 시작, b에서 a로 갈 수 있어야 루프 반복, b->a - c가 음수여야함, 결국 N으로 가야함
        check=true;
        return;
    }

    if(dist1[N]!=INF)
        ret=min(ret,dist1[N]);

    if(dist1[a]!=INF and distToN[b]!=INF)
    {
        long long cand=dist1[a]-c+distToN[b]; //1->a->b->N
        ret=min(ret,cand);
    }
}

void printResult()
{
    if(check)
    {
        cout<<"-inf"<<"\n";
        return;
    }
    if(ret==4e18)
        cout<<"x"<<"\n";
    else
        cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    solve();
    printResult();

    return 0;
}