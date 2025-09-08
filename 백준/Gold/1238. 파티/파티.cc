#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

vector<pair<int,int>> nodes[1001];
int dist[1001],result[1001];

void dijkstra(int start)
{
    priority_queue<pair<int,int>> pq;

    for(int i=1;i<=1000;i++) dist[i]=INF;

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
    int N,M,X;
    cin>>N>>M>>X;

    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        nodes[a].push_back({c,b});
    }

    dijkstra(X);

    for(int i=1;i<=N;i++) result[i]=dist[i];

    for(int i=1;i<=N;i++)
    {
        dijkstra(i);

        result[i]+=dist[X];
    }
    
    int max=0;
    for(int i=1;i<=N;i++)
    {
        if(max<result[i]) max=result[i];
    }

    cout<<max<<endl;

    return 0;
}