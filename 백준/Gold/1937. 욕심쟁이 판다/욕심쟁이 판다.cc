#include <iostream>
#include <cstring>

using namespace std;

int N,ret;
int grid[502][502];
int dp[502][502];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>grid[i][j];
}

int dfs(int x,int y)
{
    int &r=dp[x][y];
    if(r!=0) return r;

    r=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<1 or nx>N or ny<1 or ny>N) continue;

        if(grid[x][y]<grid[nx][ny])
        {
            r=max(r,dfs(nx,ny)+1);
        }
    }
    return r;
}

void solve()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            ret=max(ret,dfs(i,j));
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