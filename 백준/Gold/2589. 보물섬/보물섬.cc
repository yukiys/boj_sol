#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M,ret;
char grid[50][50];
bool visited[50][50];
int dist[50][50];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(int a,int b)
{
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
            if(nx<0 or nx>=N or ny<0 or ny>=M or visited[nx][ny] or grid[nx][ny]=='W') continue;

            visited[nx][ny]=true;
            q.push({nx,ny});
            dist[nx][ny]=dist[x][y]+1;
            ret=max(ret,dist[nx][ny]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>grid[i][j];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(grid[i][j]=='W') continue;

            memset(visited,0,sizeof(visited));
            memset(dist,0,sizeof(dist));
            bfs(i,j);
        }
    }

    cout<<ret<<"\n";

    return 0;
}