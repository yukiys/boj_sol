#include <iostream>

using namespace std;

char map[601][601];
bool visited[601][601];
int N,M,cnt;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void dfs(int y,int x)
{
    if(visited[y][x]) return;
    visited[y][x]=true;

    if(map[y][x]=='P') cnt++;

    for(int i=0;i<4;i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny<=0 or ny>N or nx<=0 or nx>M) continue;
        if(visited[ny][nx] or map[ny][nx]=='X' or map[ny][nx]=='I') continue;
        dfs(ny,nx);
    }
}

int main()
{
    int y,x;
    cin>>N>>M;
    for(int n=1;n<=N;n++)
    {
        for(int m=1;m<=M;m++)
        {
            cin>>map[n][m];
            if(map[n][m]=='I')
            {
                y=n;
                x=m;
            }
        }
    }

    dfs(y,x);
    
    if(cnt!=0) cout<<cnt<<"\n";
    else cout<<"TT\n";

    return 0;
}