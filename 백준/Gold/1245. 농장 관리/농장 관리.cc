#include <iostream>

using namespace std;

int N,M,num;
int area[101][71];
bool visited[101][71];
bool isPeak;
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};

bool dfs(int y,int x)
{
    if(visited[y][x]) return false;
    visited[y][x]=true;
    
    for(int i=0;i<8;i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<1 or ny>N or nx<1 or nx>M) continue;
        if(area[y][x]<area[ny][nx]) isPeak=false;

        if(area[y][x]==area[ny][nx] and !visited[ny][nx])
            dfs(ny,nx);
    }
    
    if(isPeak) return true;
    return false;
}

int main()
{
    cin>>N>>M;
    for(int n=1;n<=N;n++)
        for(int m=1;m<=M;m++)
            cin>>area[n][m];

    for(int n=1;n<=N;n++)
    {
        for(int m=1;m<=M;m++)
        {
            if(!visited[n][m])
            {
                isPeak=true;
                dfs(n,m);
                if(isPeak) num++;
            }
        }
    }

    cout<<num<<"\n";

    return 0;
}