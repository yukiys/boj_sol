#include <iostream>
#include <queue>
#include <cstring>

#define INF 1e9

using namespace std;

int N,ret;
int Size=2,eat,X,Y;
int grid[20][20];
bool visited[20][20];
int dist[20][20];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int FindMin()
{
    int d=INF;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(dist[i][j]!=0 and 0<grid[i][j] and grid[i][j]<Size)
                d=min(d,dist[i][j]);
    return d;
}

pair<int,int> FindPos(int d)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(dist[i][j]==d and 0<grid[i][j] and grid[i][j]<Size)
                return {i,j};
}

void bfs(int a,int b)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b]=true;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 or nx>=N or ny<0 or ny>=N or visited[nx][ny] or Size<grid[nx][ny]) continue;
            q.push({nx,ny});
            visited[nx][ny]=true;
            dist[nx][ny]=dist[x][y]+1;
        }
    }
}

int main()
{
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==9)
            {
                X=i;
                Y=j;
                grid[i][j]=0;
            }
        }
    }

    while(1)
    {
        memset(visited,0,sizeof(visited));
        memset(dist,0,sizeof(dist));

        bfs(X,Y);
        int d=FindMin();

        if(d==INF) break;
        else
        {
            pair<int,int> pos=FindPos(d);
            ret+=d;
            X=pos.first;
            Y=pos.second;
            grid[X][Y]=0;
            eat++;
            if(Size==eat)
            {
                Size++;
                eat=0;
            }
        }
    }

    cout<<ret<<"\n";

    return 0;
}