#include <iostream>
#include <queue>

using namespace std;

int N,M;
int grid[101];
int dist[101];
bool visited[101];
int dx[6]={1,2,3,4,5,6};

void bfs(int a)
{
    visited[grid[a]]=true;

    queue<int> q;
    q.push(grid[a]);
    
    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        if(x==100)
        {
            cout<<dist[100]<<"\n";
            return;
        }

        for(int i=0;i<6;i++)
        {
            int nx=x+dx[i];
            if(nx>100) continue;

            nx=grid[nx];
            if(visited[nx]) continue;
            dist[nx]=dist[x]+1;
            visited[nx]=true;
            q.push(nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N>>M;

    for(int i=1;i<=100;i++) grid[i]=i;
    for(int i=0;i<N+M;i++)
    {
        int x,y;
        cin>>x>>y;
        grid[x]=y;
    }
    
    bfs(1);

    return 0;
}