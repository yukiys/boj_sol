#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int M,N,H;
int area[100][100][100];
int dy[6]={-1,1,0,0,0,0};
int dx[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,1,-1};

bool check()
{
    for(int h=0;h<H;h++)
        for(int n=0;n<N;n++)
            for(int m=0;m<M;m++)
                    if(area[n][m][h]==0)
                        return false;
    return true;
}

int bfs()
{
    queue<tuple<int,int,int>> q;
    for(int h=0;h<H;h++)
        for(int n=0;n<N;n++)
            for(int m=0;m<M;m++)
                    if(area[n][m][h]==1)
                        q.push({n,m,h});

    int ret=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int y=get<0>(q.front());
            int x=get<1>(q.front());
            int z=get<2>(q.front());
            q.pop();

            for(int j=0;j<6;j++)
            {
                int ny=y+dy[j];
                int nx=x+dx[j];
                int nz=z+dz[j];

                if(ny<0 or ny>=N or nx<0 or nx>=M or nz<0 or nz>=H) continue;

                if(area[ny][nx][nz]==0)
                {
                    area[ny][nx][nz]=1;
                    q.push({ny,nx,nz});
                }
            }
        }
        ret++;
    }

    if(check()) return ret-1;

    return -1;
}

int main()
{
    cin>>M>>N>>H;
    for(int h=0;h<H;h++)
        for(int n=0;n<N;n++)
            for(int m=0;m<M;m++)
                    cin>>area[n][m][h];

    cout<<bfs()<<"\n";

    return 0;
}