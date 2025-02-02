#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,height,ans=1;
int map[101][101];
bool visited[101][101];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void flood()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            map[i][j]--;
}

bool bfs(int b,int a)
{
    if(visited[b][a] or map[b][a]<=0) return false;
    visited[b][a]=true;

    queue<pair<int,int>> q;
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
            if(ny<=0 or ny>N or nx<=0 or nx>N) continue;
            if(visited[ny][nx] or map[ny][nx]<=0) continue;

            visited[ny][nx]=true;
            q.push({ny,nx});
        }
    }
    return true;
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
            height=max(height,map[i][j]);
        }
    }

    for(int h=0;h<height;h++)
    {
        int temp=0;
        flood();
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(bfs(i,j))
                    temp++;

        ans=max(ans,temp);

        memset(visited,false,sizeof(visited));
    }

    cout<<ans<<"\n";

    return 0;
}