#include <iostream>

using namespace std;

int N;
int T[16], P[16];
int dp[16];

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
        cin >> T[i] >> P[i];
}

void solve()
{
    for(int i = 1; i <= N; i++)
    {
        dp[i] = max(dp[i], dp[i-1]);

        int end = i + T[i] - 1;
        if(end <= N)
            dp[end] = max(dp[end], dp[i - 1] + P[i]);
    }
}

void printAns()
{
    cout << dp[N] << "\n";
}