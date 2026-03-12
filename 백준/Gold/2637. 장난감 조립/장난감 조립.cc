#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int,int>> adj[1001];
int degree[1001];
bool isBasic[1001];
int dp[1001][1001];

void init();
void solve();
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;

        adj[y].push_back({x,k});
        degree[x]++;
    }
}

void solve()
{
    queue<int> q;

    for(int i = 1; i <= N; i++)
    {
        if(degree[i] == 0)
        {
            q.push(i);
            isBasic[i] = true;
            dp[i][i] = 1;
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto [next, k] : adj[cur])
        {
            for(int i = 1; i <= N; i++)
                if(isBasic[i])
                    dp[next][i] += dp[cur][i] * k;

            if(--degree[next] == 0)
                q.push(next);
        }
    }
}

void printAns()
{
    for(int i = 1; i <= N; i++)
        if(isBasic[i])
            cout << i << " " << dp[N][i] << "\n";
}