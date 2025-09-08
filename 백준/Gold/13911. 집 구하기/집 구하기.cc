#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

vector<pair<int,int>> nodes[10003];
int dist[10001],MacResult[10001],StarResult[10001];

void dijkstra(int start)
{
    for(int i=1;i<=10000;i++) dist[i]=INF;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,start));
    dist[start]=0;

    while(!pq.empty())
    {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<nodes[here].size();i++)
        {
            int via_cost=cost+nodes[here][i].first;

            if(via_cost<dist[nodes[here][i].second])
            {
                dist[nodes[here][i].second]=via_cost;
                pq.push({-via_cost,nodes[here][i].second});
            }
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;

    for(int i=1;i<=10000;i++)
    {
        MacResult[i]=-1;
        StarResult[i]=-1;
    }

    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        nodes[u].push_back({w,v});
        nodes[v].push_back({w,u});
    }

    int MacCount,MacDist;
    cin>>MacCount>>MacDist;
    for(int i=0;i<MacCount;i++)
    {
        int mac;
        cin>>mac;

        nodes[10001].push_back({0,mac});
    }

    dijkstra(10001);

    for(int i=1;i<=V;i++)
    {
        if(dist[i]!=0&&dist[i]<=MacDist)
        {
            if(MacResult[i]==-1) MacResult[i]=dist[i];
            else if(dist[i]<MacResult[i]) MacResult[i]=dist[i];
        }
    }

    int StarCount,StarDist;
    cin>>StarCount>>StarDist;
    for(int i=0;i<StarCount;i++)
    {
        int star;
        cin>>star;

        nodes[10002].push_back({0,star});
    }

    dijkstra(10002);

    for(int i=1;i<=V;i++)
    {
        if(dist[i]!=0&&dist[i]<=StarDist)
        {
            if(StarResult[i]==-1) StarResult[i]=dist[i];
            else if(dist[i]<MacResult[i]) StarResult[i]=dist[i];
        }
    }

    int min=INF;
    for(int i=1;i<=V;i++)
    {
        if(MacResult[i]!=-1&&StarResult[i]!=-1&&MacResult[i]+StarResult[i]<min) min=MacResult[i]+StarResult[i];
    }

    if(min==INF) cout<<-1<<endl;
    else cout<<min<<endl;

    return 0;
}