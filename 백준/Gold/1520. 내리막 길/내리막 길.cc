#include <iostream>

using namespace std;

int N,M;
int area[500][500],dp[500][500];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int dfs(int y,int x)
{
    if(y==M-1 and x==N-1) return 1;

    if(dp[y][x]==-1)
    {
        dp[y][x]=0;
        for(int i=0;i<4;i++)
        {
            int Y=y+dy[i];
            int X=x+dx[i];
            if(Y<0 or Y>=M or X<0 or X>=N) continue;
            if(area[y][x]>area[Y][X])
                dp[y][x]+=dfs(Y,X);
        }
    }
    return dp[y][x];
}

int main()
{
    cin>>M>>N;
    for(int m=0;m<M;m++)
    {
        for(int n=0;n<N;n++)
        {
            cin>>area[m][n];
            dp[m][n]=-1;
        }
    }

    cout<<dfs(0,0)<<"\n";
    
    return 0;
}