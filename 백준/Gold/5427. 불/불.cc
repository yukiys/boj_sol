#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int T,w,h,ret;
char grid[1002][1002];
int fireDist[1002][1002],dist[1002][1002];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<pair<int,int>> fire;
int px,py;

void init()
{
    cin>>w>>h;
    ret=INF;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            fireDist[i][j]=INF;
            dist[i][j]=INF;
        }
    }
    fire.clear();

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='*')
                fire.push_back({i,j});
            if(grid[i][j]=='@')
            {
                px=i;
                py=j;
            }
        }
    }
}

void fireBfs()
{
    queue<pair<int,int>> q;
    for(int i=0;i<fire.size();i++)
    {
        q.push({fire[i].first,fire[i].second});
        fireDist[fire[i].first][fire[i].second]=0;
    }
    
    while(!q.empty())
    {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx<1 or nx>h or ny<1 or ny>w or grid[nx][ny]=='#') continue;

            if(fireDist[nx][ny]<=fireDist[cx][cy]+1) continue;
            
            q.push({nx,ny});
            fireDist[nx][ny]=fireDist[cx][cy]+1;
        }
    }
}

void bfs()
{
    queue<pair<int,int>> q;
    q.push({px,py});
    dist[px][py]=0;

    while(!q.empty())
    {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx<1 or nx>h or ny<1 or ny>w)
            {
                ret=min(ret,dist[cx][cy]+1);
                continue;
            }
            
            if(grid[nx][ny]=='#') continue;
            if(dist[nx][ny]<=dist[cx][cy]+1 or dist[cx][cy]+1>=fireDist[nx][ny]) continue;

            q.push({nx,ny});
            dist[nx][ny]=dist[cx][cy]+1;
        }
    }
}

void solve()
{
    fireBfs();
    bfs();
}

void printResult()
{
    if(ret!=INF) cout<<ret<<"\n";
    else cout<<"IMPOSSIBLE"<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--)
    {
        init();
        solve();
        printResult();
    }
}