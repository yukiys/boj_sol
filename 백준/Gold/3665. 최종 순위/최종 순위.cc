#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, N, M;
int lastYear[501], curYear[501];
bool adj[501][501];
vector<int> edges[501];
int degree[501];

void init();
void solve();

int main()
{
    cin >> T;
    while(T--)
    {
        init();
        solve();
    }
}

void init()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> lastYear[i];
        edges[i].clear();
    }
    memset(adj, 0, sizeof(adj));
    memset(degree, 0, sizeof(degree));
    
    for(int i = 1; i <= N; i++)
    {
        int a = lastYear[i];
        for(int j = i+1; j <= N; j++)
        {
            int b = lastYear[j];
            adj[a][b] = true;
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        
        adj[a][b] ^= 1;
        adj[b][a] ^= 1;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(adj[i][j])
            {
                edges[i].push_back(j);
                degree[j]++;
            }
        }
    }
}

void solve()
{
    int idx = 1;
    queue<int> q;
    bool isImpossible = false;
    bool isAmbiguous = false;

    for(int i = 1; i <= N; i++)
        if(degree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        if(q.size() > 1)
            isAmbiguous = true;

        int cur = q.front();
        q.pop();

        curYear[idx++] = cur;

        for(int next : edges[cur])
            if(--degree[next] == 0)
                q.push(next);
    }
    if(idx <= N)
        isImpossible = true;

    if(isImpossible)
        cout << "IMPOSSIBLE" << "\n";
    else if(isAmbiguous)
        cout << "?" << "\n";
    else
    {
        for(int i = 1; i <= N; i++)
            cout << curYear[i] << " ";
        cout << "\n";
    }
}