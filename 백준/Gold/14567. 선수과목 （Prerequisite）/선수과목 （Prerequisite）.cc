#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int ans[1001];
vector<int> edges[1001];
int degree[1001];

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

    for(int i = 1; i <= N; i++)
        ans[i] = 1; 

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        degree[b]++;
    }
}

void solve()
{
    queue<int> q;

    for(int i = 1; i <= N; i++)
        if(degree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : edges[cur])
        {
            ans[next] = max(ans[next], ans[cur] + 1);

            if(--degree[next] == 0)
                q.push(next);
        }
    }
}

void printAns()
{
    for(int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << "\n";
}