#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, K, M, P;
vector<int> edges[1001];
int degree[1001];
int order[1001], Max[1001], cnt[1001];

void init();
void solve();
void printAns();

int main()
{
    cin >> T;
    while(T--)
    {
        init();
        solve();
        printAns();
    }
}

void init()
{
    cin >> K >> M >> P;

    for(int i = 1; i <= M; i++)
    {
        edges[i].clear();
        degree[i] = 0;
        order[i] = Max[i] = cnt[i] = 0;
    }

    for(int i = 1; i <= P; i++)
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

    for(int i = 1; i <= M; i++)
    {
        if(degree[i] == 0)
        {
            q.push(i);
            order[i] = 1;
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : edges[cur])
        {
            if(Max[next] < order[cur])
            {
                Max[next] = order[cur];
                cnt[next] = 1;
            }
            else if(Max[next] == order[cur])
                cnt[next]++;

            if(--degree[next] == 0)
            {
                q.push(next);
                order[next] = Max[next] + (cnt[next] > 1 ? 1 : 0);
            }
        }
    }
}

void printAns()
{
    cout << K << " " << order[M] << "\n";
}