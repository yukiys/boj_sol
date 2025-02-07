#include <iostream>
#include <algorithm>

using namespace std;

int M,N,K;
int map[100][100];
int S[10000],s;
bool visited[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int dfs(int x,int y)
{
    if(map[x][y]==1 or visited[x][y]) return 0;

    visited[x][y]=true;
    int size=1;

    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0 or nx>=M or ny<0 or ny>=N) continue;
        if(map[nx][ny]==1 or visited[nx][ny]) continue;
        size+=dfs(nx,ny);
    }

    return size;
}

int main()
{
    cin>>M>>N>>K;

    int a,b,c,d;
    for(int k=0;k<K;k++)
    {
        cin>>a>>b>>c>>d;
        for(int i=b;i<d;i++)
            for(int j=a;j<c;j++)
                map[i][j]=1;
    }

    int ans=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            int size=dfs(i,j);
            if(size>0)
            {
                ans++;
                S[s++]=size;
            }
        }
    }
    sort(S,S+s);

    cout<<ans<<"\n";
    for(int i=0;i<s;i++) cout<<S[i]<<" ";
    cout<<"\n";

    return 0;
}