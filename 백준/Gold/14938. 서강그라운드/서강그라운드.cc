#include <iostream>

#define INF 987654321

using namespace std;

int N,M,R,ret;
int item[101];
int dist[101][101];

void input()
{
    cin>>N>>M>>R;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(i!=j)
                dist[i][j]=INF;

    for(int i=1;i<=N;i++) cin>>item[i];

    for(int i=0;i<R;i++)
    {
        int a,b,l;
        cin>>a>>b>>l;
        
        dist[a][b]=l;
        dist[b][a]=l;
    }
}

void solve()
{
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

    for(int i=1;i<=N;i++)
    {
        int sum=0;
        for(int j=1;j<=N;j++)
            if(dist[i][j]<=M)
                sum+=item[j];
        ret=max(ret,sum);
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}