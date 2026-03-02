#include <iostream>

using namespace std;

int N, ans;
int children[1000001];
int dp[1000001];

void init();
void solve();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printAns();
}

void init()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >>children[i];
}

void solve()
{
    int M = 0;

    for(int i = 1; i <= N; i++)
    {
        int cur = children[i];
        dp[cur] = dp[cur-1] + 1;
        M = max(M, dp[cur]);
    }

    ans = N - M;
}

void printAns()
{
    cout << ans <<"\n";
}