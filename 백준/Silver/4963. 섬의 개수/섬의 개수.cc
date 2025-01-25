#include <iostream>
#include <cstring>

using namespace std;

int w,h,num;
int area[51][51];
bool visited[51][51];
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};

bool dfs(int y,int x)
{
    if(visited[y][x] or area[y][x]==0) return false;
    visited[y][x]=true;

    for(int i=0;i<8;i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(1<=ny and ny<=h and 1<=nx and nx<=w)
            if(area[ny][nx]==1)
                dfs(ny,nx);
    }
    
    return true;
}

int main()
{
    while(1)
    {
        cin>>w>>h;
        if(w==0 and h==0) return 0;

        num=0;
        memset(area,0,sizeof(area));
        memset(visited,false,sizeof(visited));

        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                cin>>area[i][j];

        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                if(dfs(i,j))
                    num++;

        cout<<num<<"\n";
    }
}