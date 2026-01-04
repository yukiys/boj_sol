#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int N,M,a,b;
vector<pair<int,int>> nodes[10001];
int capacity[10001];

void init()
{
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int A,B,C;
        cin>>A>>B>>C;

        nodes[A].push_back({C,B});
        nodes[B].push_back({C,A});
    }

    cin>>a>>b;
}

void dijkstra(int start)
{
    priority_queue<pair<int,int>> pq;
    pq.push({INF,start});
    capacity[start]=INF;

    while(!pq.empty())
    {
        int cost=pq.top().first;
        int here=pq.top().second;
        pq.pop();

        if(capacity[here]!=cost) continue;

        for(auto[nextCost,next]:nodes[here])
        {
            int temp=min(capacity[here],nextCost);
            
            if(temp>capacity[next])
            {
                capacity[next]=temp;
                pq.push({temp,next});
            }
        }
    }
}

void printRet()
{
    cout<<capacity[b]<<"\n";
}

int main()
{
    init();
    dijkstra(a);
    printRet();
}