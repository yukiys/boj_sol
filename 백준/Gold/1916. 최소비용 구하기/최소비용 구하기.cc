#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

vector<pair<int,int>> nodes[1001];
int dist[1001];

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
    int N,M;
    cin>>N>>M;

    for(int i=1;i<=N;i++) dist[i]=INF;

    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        nodes[a].push_back({c,b});
    }

    int A,B;
    cin>>A>>B;

    dijkstra(A);

    cout<<dist[B]<<endl;

    return 0;
}