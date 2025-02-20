#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[1001][1001];
int visited[1001][1001];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void bfs(int b,int a)
{
    queue<pair<int,int>> q;
    visited[b][a]=0;
    q.push({b,a});

    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<=0 or ny>n or nx<=0 or nx>m) continue;
            if(visited[ny][nx]!=-1 or map[ny][nx]==0) continue;

            visited[ny][nx]=visited[y][x]+1;
            q.push({ny,nx});
        }
    }
}

int main()
{
    cin>>n>>m;

    int y,x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==2)
            {
                y=i;
                x=j;
            }
            visited[i][j]=-1;
        }
    }

    bfs(y,x);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]==0) cout<<"0 ";
            else cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}