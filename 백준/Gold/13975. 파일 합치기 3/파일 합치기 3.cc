#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, K;
long long ans;
priority_queue<long long, vector<long long>, greater<long long>> pq;

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
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int k;
        cin >> k;
        pq.push(k);
    }

    ans = 0;
}

void solve()
{
    while(pq.size() >= 2)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        ans += a + b;

        if(!pq.empty())
            pq.push(a + b);
    }
}

void printAns()
{
    cout << ans << "\n";
}