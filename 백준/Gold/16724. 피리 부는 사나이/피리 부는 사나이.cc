#include <iostream>

using namespace std;

int N,M,ret;
char grid[1000][1000];
int state[1000][1000];
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}}; //U R D L

void init()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>grid[i][j];
}

void dfs(int x,int y)
{
    if(state[x][y]==2) return;
    state[x][y]=1;

    int nx,ny;
    if(grid[x][y]=='U')
    {
        nx=x+dir[0].first;
        ny=y+dir[0].second;
    }
    else if(grid[x][y]=='R')
    {
        nx=x+dir[1].first;
        ny=y+dir[1].second;
    }
    else if(grid[x][y]=='D')
    {
        nx=x+dir[2].first;
        ny=y+dir[2].second;
    }
    else if(grid[x][y]=='L')
    {
        nx=x+dir[3].first;
        ny=y+dir[3].second;
    }

    if(nx<0 or nx>=N or ny<0 or ny>=M or state[nx][ny]==2)
    {
        state[x][y]=2;
        return;
    }

    if(state[nx][ny]==0) dfs(nx,ny);
    else if(state[nx][ny]==1) ret++;
    state[x][y]=2;
}

void solve()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(state[i][j]==0)
                dfs(i,j);
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}