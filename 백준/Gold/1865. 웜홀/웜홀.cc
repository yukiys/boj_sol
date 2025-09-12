#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int TC,N,M,W;
vector<pair<int,int>> edges[501];
long long dist[501];
bool cycle;

void input()
{
    cin>>N>>M>>W;
    for(int n=1;n<=N;n++) edges[n].clear();
    cycle=false;

    for(int i=0;i<M;i++)
    {
        int S,E,T;
        cin>>S>>E>>T;
        
        edges[S].push_back({E,T});
        edges[E].push_back({S,T});
    }
    for(int i=0;i<W;i++)
    {
        int S,E,T;
        cin>>S>>E>>T;
        
        edges[S].push_back({E,-T});
    }
}

void BelmanFord()
{
    for(int i=1;i<=N;i++) dist[i]=0;

    for(int n=0;n<N;n++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<edges[i].size();j++)
            {
                int next=edges[i][j].first;
                int cost=edges[i][j].second;

                if(dist[next]>dist[i]+cost)
                {
                    dist[next]=dist[i]+cost;
                    if(n==N-1) cycle=true;
                }
            }
        }
    }
}

void printAnswer()
{
    cout<<(cycle?"YES":"NO")<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>TC;
    while(TC--)
    {
        input();
        BelmanFord();
        printAnswer();
    }
    
    return 0;
}