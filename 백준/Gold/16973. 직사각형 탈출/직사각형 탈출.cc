#include <iostream>
#include <queue>

using namespace std;

int N,M;
int grid[1001][1001],dist[1001][1001];
int H,W,Sr,Sc,Fr,Fc;
bool visited[1001][1001];
int dn[4]={-1,1,0,0};
int dm[4]={0,0,-1,1};
queue<pair<int,int>> q;

void input()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>grid[i][j];
            dist[i][j]=-1;
        }
    }

    cin>>H>>W>>Sr>>Sc>>Fr>>Fc;
}

void checkUp(int n,int m)
{
    int nn=n+dn[0];
    int nm=m+dm[0];

    if(nn<=0 or nn>N or nm<=0 or nm+W-1>M or visited[nn][nm]) return;
    for(int w=0;w<W;w++)
        if(grid[nn][nm+w]==1)
            return;

    dist[nn][nm]=dist[n][m]+1;
    q.push({nn,nm});
    visited[nn][nm]=true;
}

void checkDown(int n,int m)
{
    int nn=n+dn[1];
    int nm=m+dm[1];

    if(nn<=0 or nn+H-1>N or nm<=0 or nm+W-1>M or visited[nn][nm]) return;
    for(int w=0;w<W;w++)
        if(grid[nn+H-1][nm+w]==1)
            return;

    dist[nn][nm]=dist[n][m]+1;
    q.push({nn,nm});
    visited[nn][nm]=true;
}

void checkLeft(int n,int m)
{
    int nn=n+dn[2];
    int nm=m+dm[2];

    if(nn<=0 or nn+H-1>N or nm<=0 or nm>M or visited[nn][nm]) return;
    for(int h=0;h<H;h++)
        if(grid[nn+h][nm]==1)
            return;

    dist[nn][nm]=dist[n][m]+1;
    q.push({nn,nm});
    visited[nn][nm]=true;
}

void checkRight(int n,int m)
{
    int nn=n+dn[3];
    int nm=m+dm[3];

    if(nn<=0 or nn+H-1>N or nm<=0 or nm+W-1>M or visited[nn][nm]) return;
    for(int h=0;h<H;h++)
        if(grid[nn+h][nm+W-1]==1)
            return;

    dist[nn][nm]=dist[n][m]+1;
    q.push({nn,nm});
    visited[nn][nm]=true;
}

void bfs(int a,int b)
{
    dist[a][b]=0;
    q.push({a,b});
    visited[a][b]=true;
    while(!q.empty())
    {
        int n=q.front().first;
        int m=q.front().second;
        q.pop();

        checkUp(n,m);
        checkDown(n,m);
        checkLeft(n,m);
        checkRight(n,m);
    }
}

void printResult()
{
    cout<<dist[Fr][Fc]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    bfs(Sr,Sc);
    printResult();

    return 0;
}