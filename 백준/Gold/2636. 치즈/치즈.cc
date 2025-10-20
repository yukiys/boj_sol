#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M,ret1,ret2=1e9;
int grid[100][100];
bool visited[100][100];
int contact[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void input()
{
    cin>>N>>M;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>grid[i][j];
}

void bfs(int a,int b)
{
    if(visited[a][b]) return;
    visited[a][b]=true;

    queue<pair<int,int>> q;
    q.push({a,b});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 or nx>=N or ny<0 or ny>=M or visited[nx][ny]) continue;

            if(grid[nx][ny]==0)
            {
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
            else contact[nx][ny]++;
        }
    }
}

void update()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(contact[i][j]>0)
                grid[i][j]=0;
}

int Count()
{
    int cnt=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(grid[i][j]==1)
                cnt++;

    return cnt;
}

void solve()
{
    while(Count()!=0)
    {
        ret1++;
        ret2=min(ret2,Count());

        memset(visited,0,sizeof(visited));
        memset(contact,0,sizeof(contact));

        bfs(0,0);
        update();
    }
}

void printResult()
{
    cout<<ret1<<"\n"<<ret2<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}