#include <iostream>

#define INF 1e9

using namespace std;

int N,M;
long long dist[101][101];

void input()
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(i!=j)
                dist[i][j]=INF;

    for(int i=0;i<M;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;

        if(dist[a][b]>c) dist[a][b]=c;
    }
}

void floyd()
{
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}

void printResult()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(dist[i][j]==INF) cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    floyd();
    printResult();

    return 0;
}