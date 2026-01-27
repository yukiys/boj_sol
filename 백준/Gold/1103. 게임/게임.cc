#include <iostream>

using namespace std;

int N,M;
int grid[50][50];
int state[50][50],dp[50][50];
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}}; //U R D L
bool findCycle;

void init()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            char c;
            cin>>c;
            if(c!='H') grid[i][j]=c-'0';
            else grid[i][j]=-1;
        }
    }
}

int dfs(int x,int y)
{
    if(findCycle) return 0;
    if(state[x][y]==1)
    {
        findCycle=true;
        return 0;
    }
    if(state[x][y]==2) return dp[x][y];
    state[x][y]=1;
    dp[x][y]=1;

    for(int i=0;i<4;i++)
    {
        int nx=x+grid[x][y]*dir[i].first;
        int ny=y+grid[x][y]*dir[i].second;

        if(nx<0 or nx>=N or ny<0 or ny>=M or grid[nx][ny]==-1) continue;
        
        dp[x][y]=max(dp[x][y],dfs(nx,ny)+1);
    }

    state[x][y]=2;
    return dp[x][y];
}

void printRet()
{
    if(findCycle) cout<<-1<<"\n";
    else cout<<dp[0][0]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    dfs(0,0);
    printRet();
}