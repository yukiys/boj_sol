#include <iostream>

using namespace std;

constexpr int MAX_N = 250;
constexpr int INF = 1e9;

int N, M, K;
int dist[MAX_N+1][MAX_N+1];

void init()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(i != j)
                dist[i][j] = INF;

    for(int i = 0; i < M; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;

        if(b == 0)
        {
            dist[u][v] = 0;
            dist[v][u] = 1;
        }
        else
        {
            dist[u][v] = 0;
            dist[v][u] = 0;
        }
    }

    cin >> K;
}

void floyd()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(dist[i][k] == INF or dist[k][j] == INF)
                    continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve()
{
    floyd();

    for(int i = 0; i < K; i++)
    {
        int s, e;
        cin >> s >> e;

        cout << dist[s][e] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}