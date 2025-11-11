#include <iostream>

#define INF 1e9

using namespace std;

int N,M;
int dist[101][101];
int c1,c2,ret=INF;

void input()
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(i!=j)
                dist[i][j]=INF;

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=1;
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

void solve()
{
    for(int n=1;n<N;n++)
    {
        for(int m=n+1;m<=N;m++)
        {
            int temp=0;
            for(int i=1;i<=N;i++)
                temp+=min(dist[n][i],dist[m][i]);
            
            if(ret>temp)
            {
                c1=n;
                c2=m;
                ret=temp;
            }
        }
    }
    ret*=2;
}

void printResult()
{
    cout<<c1<<" "<<c2<<" "<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    floyd();
    solve();
    printResult();

    return 0;
}