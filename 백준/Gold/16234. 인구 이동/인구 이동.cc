#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N,L,R;
int day;
int A[50][50];
bool visited[50][50];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int bfs(int x,int y,vector<pair<int,int>> &v)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    v.push_back({x,y});
    int sum=A[x][y];
    
    while(!q.empty())
    {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx<0 or nx>=N or ny<0 or ny>=N or visited[nx][ny]) continue;

            int d=abs(A[cx][cy]-A[nx][ny]);
            if(L<=d and d<=R)
            {
                visited[nx][ny]=true;
                q.push({nx,ny});
                v.push_back({nx,ny});
                sum+=A[nx][ny];
            }
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>L>>R;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];

    
    while(1)
    {
        memset(visited,0,sizeof(visited));
        bool move=false;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(visited[i][j]) continue;

                vector<pair<int,int>> v;
                int sum=bfs(i,j,v);

                if(v.size()>1)
                {
                    int temp=(int)sum/v.size();
                    for(int k=0;k<v.size();k++) A[v[k].first][v[k].second]=temp;

                    move=true;
                }
            }
        }
        
        if(!move) break;

        day++;
    }

    cout<<day<<"\n";

    return 0;
}