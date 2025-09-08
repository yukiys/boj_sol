#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000000

using namespace std;

vector<pair<int,int>> nodes[1000];
int dist[1000];

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
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;

    for(int i=0;i<N;i++) dist[i]=INF;

    for(int m=0;m<M;m++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }

    dijkstra(Y);

    sort(dist,dist+N);
    if(2*dist[N-1]>X)
    {
        cout<<-1<<endl;
        return 0;
    }

    int day=1;
    int d=0;
    
    for(int i=0;i<N;i++)
    {
        if(d+2*dist[i]<=X) d+=2*dist[i];
        else
        {
            day++;
            d=2*dist[i];
        }
    }

    cout<<day<<endl;

    return 0;
}