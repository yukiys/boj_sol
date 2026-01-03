#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9
#define Pair pair<int,pair<int,int>>

using namespace std;

int N;
int grid[1000][1000];
int dist[1000][1000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>grid[i][j];
            dist[i][j]=INF;
        }
    }
}

void dijkstra(int a,int b)
{
    priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
    dist[a][b]=0;
    pq.push({0,{a,b}});

    while(!pq.empty())
    {
        int cost=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();

        if(cost!=dist[x][y]) continue;

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 or nx>=N or ny<0 or ny>=N) continue;

            int w=abs(grid[x][y]-grid[nx][ny]);
            int d=max(cost,w);
            if(dist[nx][ny]>d)
            {
                dist[nx][ny]=d;
                pq.push({d,{nx,ny}});
            }
        }
    }
}

void printRet()
{
    cout<<dist[N-1][N-1]<<"\n";
}

int main()
{
    init();
    dijkstra(0,0);
    printRet();
}