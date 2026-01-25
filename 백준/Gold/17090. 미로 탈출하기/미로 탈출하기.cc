#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M,ret;
char grid[502][502];
queue<pair<int,int>> q;
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}}; //U R D L
bool escape[502][502];

void init()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>grid[i][j];
}

void bfs()
{
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i].first;
            int ny=y+dir[i].second;

            if(nx<1 or nx>N or ny<1 or ny>M or escape[nx][ny]) continue;
            
            char c=grid[nx][ny];
            if((i==0 and c=='D') or (i==1 and c=='L') or (i==2 and c=='U') or (i==3 and c=='R'))
            {
                q.push({nx,ny});
                escape[nx][ny]=true;
            }
        }
    }
}

void solve()
{
    for(int i=1;i<N+1;i++)
    {
        escape[i][0]=true;
        q.push({i,0});
        escape[i][M+1]=true;
        q.push({i,M+1});
    }
    for(int j=1;j<M+1;j++)
    {
        escape[0][j]=true;
        q.push({0,j});
        escape[N+1][j]=true;
        q.push({N+1,j});
    }

    bfs();

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(escape[i][j])
                ret++;
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