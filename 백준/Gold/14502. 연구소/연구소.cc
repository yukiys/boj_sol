#include <iostream>
#include <queue>

using namespace std;

int N,M,ret;
int map[8][8];
int testMap[8][8];
queue<pair<int,int>> virus;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs()
{
    queue<pair<int,int>> q=virus;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            testMap[i][j]=map[i][j];
    
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 or ny>=N or nx<0 or nx>=M) continue;
            if(testMap[ny][nx]==0)
            {
                testMap[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }
}

int check()
{
    int cnt=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(testMap[i][j]==0)
                cnt++;
    return cnt;
}

void solve(int cnt)
{
    if(cnt==3)
    {
        bfs();
        ret=max(ret,check());
        return;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[i][j]==0)
            {
                map[i][j]=1;
                solve(cnt+1);
                map[i][j]=0;
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==2)
                virus.push({i,j});
        }
    }

    solve(0);

    cout<<ret<<"\n";

    return 0;
}