#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, maxAns;
int Time[10001], ans[10001];
vector<int> edges[10001];
int degree[10001];

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
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        cin >> Time[i];

        int numOfPreWork;
        cin >> numOfPreWork;
        while(numOfPreWork--)
        {
            int j;
            cin >> j;
            edges[j].push_back(i);
            degree[i]++;
        }
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
            ans[i] = Time[i];
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : edges[cur])
        {
            ans[next] = max(ans[next], ans[cur] + Time[next]);

            if(--degree[next] == 0)
                q.push(next);
        }
    }
}

void printAns()
{
    for(int i = 1; i <= N; i++)
        maxAns = max(maxAns, ans[i]);
    
    cout << maxAns << "\n";
}