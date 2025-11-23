#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,center;
vector<int> edges[200001];
int dist[200001];
int parent[200001];
vector<int> path;

void input()
{
    cin>>N;
    for(int i=1;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}

void bfs(int start)
{
    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        dist[i]=-1;
        parent[i]=-1;
    }
    dist[start]=0;
    q.push(start);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int next:edges[cur])
        {
            if(dist[next]==-1)
            {
                dist[next]=dist[cur]+1;
                parent[next]=cur;
                q.push(next);
            }
        }
    }
}

int findMax()
{
    int d=1;
    for(int i=1;i<=N;i++)
        if(dist[i]>dist[d])
            d=i;
    return d;
}

bool solve()
{
    for(int i=1;i<=N;i++)
        if(edges[i].size()!=1 and edges[i].size()!=3)
            return false;

    bfs(1);
    int A=findMax();
    
    bfs(A);
    int B=findMax();

    int H=dist[B];
    if(H%2==1)
        return false;

    int cur=B;
    while(cur!=-1)
    {
        path.push_back(cur);
        cur=parent[cur];
    }
    reverse(path.begin(),path.end());

    center=path[H/2];
    if(edges[center].size()!=3)
        return false;

    bfs(center);
    int Dist=dist[findMax()];

    for(int i=1;i<=N;i++)
        if(edges[i].size()==1)
            if(dist[i]!=Dist)
                return false;

    return true;
}

void printResult(bool check)
{
    if(!check) cout<<-1<<"\n";
    else
    {
        cout<<1<<"\n";
        cout<<center<<"\n";
    }
}

int main()
{
    input();
    printResult(solve());

    return 0;
}