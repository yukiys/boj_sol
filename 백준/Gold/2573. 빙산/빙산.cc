#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N,M,ret;
int grid[300][300],melt[300][300];
vector<pair<int,int>> ices;
bool visited[300][300];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void init()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]!=0) ices.push_back({i,j});
        }
    }
}

bool bfs(int a,int b)
{
    if(visited[a][b] or grid[a][b]==0) return false;

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

            if(nx<0 or nx>=N or ny<0 or ny>=M or grid[nx][ny]==0 or visited[nx][ny]) continue;
            
            q.push({nx,ny});
            visited[nx][ny]=true;
        }
    }

    return true;
}

void next()
{
    memset(melt,0,sizeof(melt));
    vector<pair<int,int>> nextIces;

    for(auto[x,y]:ices)
    {
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 or nx>=N or ny<0 or ny>=M) continue;

            if(grid[nx][ny]==0) melt[x][y]++;
        }
    }

    for(auto[x,y]:ices)
    {
        grid[x][y]-=melt[x][y];
        if(grid[x][y]<=0) grid[x][y]=0;
        else nextIces.push_back({x,y});
    }

    ices.swap(nextIces);
}

void solve()
{
    while(1)
    {
        memset(visited,0,sizeof(visited));

        int cnt=0;
        for(auto[x,y]:ices)
            if(bfs(x,y))
                cnt++;

        if(cnt==0)
        {
            ret=0;
            break;
        }
        if(cnt>=2) break;
        ret++;

        next();
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}