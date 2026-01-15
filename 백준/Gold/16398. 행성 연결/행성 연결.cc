#include <iostream>
#include <vector>
#include <algorithm>

const long long INF=1e18;

using namespace std;

int N;
long long ret;
int G[1001][1001];
long long dist[1001];
bool visited[1001];

void init()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>G[i][j];

    for(int i=1;i<=N;i++)
        dist[i]=INF;
    dist[1]=0;
}

void Prim()
{
    for(int i=1;i<=N;i++)
    {
        int v=-1;

        for(int from=1;from<=N;from++)
        {
            if(visited[from]) continue;
            if(v==-1 or dist[v]>dist[from]) v=from;
        }

        visited[v]=true;
        ret+=dist[v];

        for(int to=1;to<=N;to++)
        {
            if(visited[to]) continue;
            if(dist[to]>G[v][to]) dist[to]=G[v][to];
        }
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    Prim();
    printRet();
}