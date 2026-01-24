#include <iostream>

using namespace std;

int N,M;
int grid[51][51];
int state[51][51];
bool findCycle;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void init()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            char c;
            cin>>c;
            grid[i][j]=c-'A';
        }
    }
}

void dfs(int x,int y,int px,int py)
{
    state[x][y]=1;

    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1 or nx>N or ny<1 or ny>M or grid[x][y]!=grid[nx][ny]) continue;
        if(nx==px and ny==py) continue;

        if(state[nx][ny]==0) dfs(nx,ny,x,y);
        else if(state[nx][ny]==1) findCycle=true;
    }

    state[x][y]=2;
}

void solve()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(state[i][j]==0 and !findCycle)
                dfs(i,j,0,0);
}

void printRet()
{
    if(findCycle) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}