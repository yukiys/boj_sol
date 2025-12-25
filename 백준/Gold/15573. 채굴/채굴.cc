#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,M,K,D,ret;
int grid[1002][1002];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool visited[1002][1002];
int Max,l,r;

void input()
{
    cin>>N>>M>>K;

    for(int n=1;n<=N;n++)
    {
        for(int m=1;m<=M;m++)
        {
            cin>>grid[n][m];
            Max=max(Max,grid[n][m]);
        }
    }
}

bool bfs(int a,int b)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b]=true;
    int k=0;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 or nx>N or ny<0 or ny>M+1 or visited[nx][ny]) continue;
            if(grid[nx][ny]>D) continue;

            q.push({nx,ny});
            visited[nx][ny]=true;
            if(grid[nx][ny]!=0) k++;
        }
    }

    return k>=K;
}

void solve()
{
    r=Max;
    while(l<=r)
    {
        memset(visited,0,sizeof(visited));

        D=(l+r)/2;
        if(bfs(0,0))
        {
            ret=D;
            r=D-1;
        }
        else
            l=D+1;
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    input();
    solve();
    printResult();
}