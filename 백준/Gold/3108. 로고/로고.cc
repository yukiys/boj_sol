#include <iostream>
#include <queue>

using namespace std;

int N,ret;
int map[2002][2002];
bool visited[2002][2002];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool bfs(int a,int b)
{
    if(visited[a][b] or map[a][b]==0) return false;
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

            if(nx<0 or nx>2000 or ny<0 or ny>2000 or visited[nx][ny]) continue;
            
            if(map[nx][ny]==0) continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N;
    for(int n=0;n<N;n++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=500; y1+=500; x2+=500; y2+=500;
        x1*=2; y1*=2; x2*=2; y2*=2;

        for(int x=x1;x<=x2;x++)
        {
            map[x][y1]=1;
            map[x][y2]=1;
        }
        for(int y=y1;y<=y2;y++)
        {
            map[x1][y]=1;
            map[x2][y]=1;
        }
    }

    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=2000;j++)
        {
            if(bfs(i,j))
            {
                ret++;
            }
        }
    }

    if(map[1000][1000]==1) ret--;

    cout<<ret<<"\n";
    
    return 0;
}