#include <iostream>
#include <queue>

using namespace std;

int M,N;
int area[1000][1000];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

bool check()
{
    for(int n=0;n<N;n++)
        for(int m=0;m<M;m++)
            if(area[n][m]==0)
                return false;
    return true;
}

int bfs()
{
    queue<pair<int,int>> q;
    for(int n=0;n<N;n++)
        for(int m=0;m<M;m++)
            if(area[n][m]==1)
                q.push({n,m});

    int ret=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int y=q.front().first;
            int x=q.front().second;
            q.pop();

            for(int j=0;j<4;j++)
            {
                int ny=y+dy[j];
                int nx=x+dx[j];

                if(ny<0 or ny>=N or nx<0 or nx>=M) continue;

                if(area[ny][nx]==0)
                {
                    area[ny][nx]=1;
                    q.push({ny,nx});
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
    cin>>M>>N;
    for(int n=0;n<N;n++)
        for(int m=0;m<M;m++)
            cin>>area[n][m];

    cout<<bfs()<<"\n";

    return 0;
}