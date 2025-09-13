#include <iostream>
#include <queue>

using namespace std;

int N,M,ret=-1;
int grid[1001][1001];
int dist[1001][1001];
int dist2[1001][1001];
bool visited[1001][1001];
bool visited2[1001][1001];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void input()
{
    cin>>N>>M;

    for(int n=1;n<=N;n++)
        for(int m=1;m<=M;m++)
            scanf("%1d",&grid[n][m]);
}

void bfs(int a,int b)
{
    dist[1][1]=1;
    queue<pair<pair<int,int>,bool>> q;
    visited[a][b]=true;
    q.push({{a,b},false});

    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        bool Break=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            bool nextBreak=Break;

            if(nx<1 or nx>N or ny<1 or ny>M) continue;
            if(grid[nx][ny]==1)
            {
                if(!Break) nextBreak=true;
                else continue;
            }

            if(!nextBreak)
            {
                if(visited[nx][ny]) continue;
                dist[nx][ny]=dist[x][y]+1;
                visited[nx][ny]=true;
                q.push({{nx,ny},nextBreak});
            }
            else
            {
                if(visited2[nx][ny]) continue;
                dist2[nx][ny]=Break?dist2[x][y]+1:dist[x][y]+1;
                visited2[nx][ny]=true;
                q.push({{nx,ny},nextBreak});
            }
        }
    }
}

void solve()
{
    if(visited[N][M]) ret=dist[N][M];
    if(visited2[N][M])
    {
        if(ret==-1) ret=dist2[N][M];
        else ret=min(ret,dist2[N][M]);
    }
}

int main()
{
    input();
    bfs(1,1);
    solve();

    cout<<ret<<"\n";

    return 0;
}