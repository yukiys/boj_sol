#include <iostream>

using namespace std;

int map[11][11];
bool visited[11][11];
int N,M,K;
int ret=-1000001;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void backTracking(int depth,int sum)
{
    if(depth==K)
    {
        ret=max(ret,sum);
        return;
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(visited[i][j]) continue;

            bool check=true;
            for(int k=0;k<4;k++)
            {
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(ny<=0 or ny>N or nx<=0 or nx>M) continue;
                if(visited[ny][nx]) check=false;
            }

            if(check)
            {
                visited[i][j]=true;
                backTracking(depth+1,sum+map[i][j]);
                visited[i][j]=false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>map[i][j];


    backTracking(0,0);

    cout<<ret<<"\n";

    return 0;
}