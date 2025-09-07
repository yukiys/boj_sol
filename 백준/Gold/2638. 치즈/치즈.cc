#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M,ret;
int grid[102][102];
bool visited[102][102];
int contact[102][102];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

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

            if(nx<0 or nx>=N+2 or ny<0 or ny>=M+2 or visited[nx][ny]) continue;

            if(grid[nx][ny]==0)
            {
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
            else contact[nx][ny]++;
        }
    }
}

bool update()
{
    bool check=false;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(contact[i][j]>=2)
            {
                grid[i][j]=0;
                check=true;
            }
        }
    }

    return check;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N>>M;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>grid[i][j];

    while(1)
    {
        memset(visited,0,sizeof(visited));
        memset(contact,0,sizeof(contact));

        bfs(0,0);

        if(!update()) break;
        ret++;
    }

    cout<<ret<<"\n";

    return 0;
}