#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int ret[100001];
bool visited[100001];
vector<int> v[100001];

void bfs(int start)
{
    visited[start]=true;

    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int y:v[x])
        {
            if(visited[y]) continue;
            visited[y]=true;
            ret[y]=x;
            q.push(y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N;

    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(1);

    for(int i=2;i<=N;i++) cout<<ret[i]<<"\n";

    return 0;
}