#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,K,M;
vector<int> tube[1001];
vector<int> station[100001];
bool visited[100001];
bool tubeVisited[1001];
int dist[100001];

void input()
{
    cin>>N>>K>>M;
    for(int i=1;i<=M;i++)
    {
        int s;
        for(int j=0;j<K;j++)
        {
            cin>>s;
            tube[i].push_back(s);
            station[s].push_back(i);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    dist[start]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int i=0;i<station[cur].size();i++)
        {
            int t=station[cur][i];
            if(tubeVisited[t]) continue;
            
            for(int j=0;j<tube[t].size();j++)
            {
                int next=tube[t][j];
                if(!visited[next])
                {
                    q.push(next);
                    visited[next]=true;
                    dist[next]=dist[cur]+1;
                }
            }
        }
    }
}

void printResult()
{
    if(dist[N]!=0) cout<<dist[N]<<"\n";
    else cout<<-1<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    bfs(1);
    printResult();

    return 0;
}