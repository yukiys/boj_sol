#include <iostream>
#include <queue>
#include <vector>

#define INF 1e18

using namespace std;

int N,M,S,E;
vector<pair<int,int>> nodes[1001];
long long dist[1001];
int parent[1001];
vector<int> ret;

void input()
{
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        nodes[a].push_back({c,b});
    }

    cin>>S>>E;
}

void dijkstra(int start)
{
    for(int i=1;i<=N;i++) dist[i]=INF;
    dist[start]=0;
    for(int i=1;i<=N;i++) parent[i]=-1;

    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    while(!pq.empty())
    {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<nodes[here].size();i++)
        {
            int nextCost=cost+nodes[here][i].first;
            int next=nodes[here][i].second;

            if(dist[next]>nextCost)
            {
                dist[next]=nextCost;
                parent[next]=here;
                pq.push({-nextCost,next});
            }
        }
    }
}

void printResult()
{
    for(int cur=E;cur!=-1;cur=parent[cur]) ret.push_back(cur);

    cout<<dist[E]<<"\n";
    cout<<ret.size()<<"\n";
    for(int i=ret.size()-1;i>=0;i--) cout<<ret[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    dijkstra(S);
    printResult();

    return 0;
}