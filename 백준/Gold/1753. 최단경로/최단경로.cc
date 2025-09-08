#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

vector<pair<int,int>> nodes[20001];
int dist[20001];

void dijkstra(int start)
{
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
    int V,E,K;
    cin>>V>>E>>K;

    for(int i=1;i<=V;i++) dist[i]=INF;

    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        nodes[u].push_back({w,v});
    }

    dijkstra(K);

    for(int i=1;i<=V;i++)
    {
        if(dist[i]==INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }

    return 0;
}