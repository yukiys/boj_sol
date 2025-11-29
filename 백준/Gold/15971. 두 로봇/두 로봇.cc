#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,R1,R2,M;
vector<pair<int,int>> G[100001];
int parent[100001],weight[100001];
long long ret;

void input()
{
    cin>>N>>R1>>R2;
    for(int i=0;i<N-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back({c,b});
        G[b].push_back({c,a});
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    parent[start]=-1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        
        for(auto[cost,next]:G[cur])
        {
            if(next==parent[cur]) continue;

            parent[next]=cur;
            weight[next]=cost;
            q.push(next);
        }
    }
}

void solve()
{
    if(R1==R2) return;

    bfs(R1);

    int cur=R2;
    while(cur!=R1)
    {
        ret+=weight[cur];
        M=max(M,weight[cur]);
        cur=parent[cur];
    }

    ret-=M;
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    input();
    solve();
    printResult();

    return 0;
}