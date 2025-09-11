#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N,E,v1,v2;
long long ret,ret1,ret2;
vector<pair<long long,int>> nodes[801];
long long dist[801];

void input()
{
    cin>>N>>E;
    
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }

    cin>>v1>>v2;
}

void dijkstra(int start)
{
    for(int i=1;i<=N;i++) dist[i]=INF;

    priority_queue<pair<long long,int>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty())
    {
        long long cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<cost) continue;

        for(int i=0;i<nodes[cur].size();i++)
        {
            long long newCost=cost+nodes[cur][i].first;
            int next=nodes[cur][i].second;

            if(newCost<dist[next])
            {
                dist[next]=newCost;
                pq.push({-newCost,next});
            }
        }
    }
}

void solve()
{
    dijkstra(1);
    ret1+=dist[v1];
    ret2+=dist[v2];
    
    dijkstra(v1);
    ret1+=dist[v2];
    ret2+=dist[N];
    
    dijkstra(v2);
    ret1+=dist[N];
    ret2+=dist[v1];
    
    ret=min(ret1,ret2);
}

void printAnswer()
{
    if(ret>=INF) cout<<-1<<"\n";
    else cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printAnswer();

    return 0;
}