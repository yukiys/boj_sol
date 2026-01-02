#include <iostream>

#define INF 1e9

using namespace std;

int V,E,ret=INF;
int dist[401][401];

void init()
{
    cin>>V>>E;
    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            if(i!=j)
                dist[i][j]=INF;

    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
}

void floyd()
{
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

void solve()
{
    floyd();

    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(i==j) continue;
            if(dist[i][j]==INF or dist[j][i]==INF) continue;

            ret=min(ret,dist[i][j]+dist[j][i]);
        }
    }
}

void printRet()
{
    if(ret==INF) cout<<-1<<"\n";
    else cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}