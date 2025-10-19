#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int N,M;
vector<pair<int,int>> edge[501];
long long dist[501];
bool cycle;

void input()
{
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int A,B,C;
        cin>>A>>B>>C;

        edge[A].push_back({B,C});
    }
}

void BellmanFord(int start)
{
    for(int i=1;i<=N;i++) dist[i]=INF;
    dist[start]=0;

    for(int n=0;n<N;n++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<edge[i].size();j++)
            {
                int next=edge[i][j].first;
                int cost=edge[i][j].second;

                if(dist[i]!=INF and dist[next]>dist[i]+cost)
                {
                    dist[next]=dist[i]+cost;
                    if(n==N-1) cycle=true;
                }
            }
        }
    }
}

void printResult()
{
    if(cycle) cout<<-1<<"\n";
    else
    {
        for(int i=2;i<=N;i++)
        {
            if(dist[i]==INF) cout<<-1<<"\n";
            else cout<<dist[i]<<"\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    BellmanFord(1);
    printResult();

    return 0;
}