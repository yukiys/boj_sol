#include <iostream>

#define MOD 10007

using namespace std;

int N, ans;
int dp[1001][10];

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
}

void solve()
{
    for(int i = 0; i <= N; i++)
        dp[i][0] = 1;
        
    for(int j = 0; j <= 9; j++)
        dp[1][j] = 1;

    for(int i = 2; i <= N; i++)
        for(int j = 1; j <= 9; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    for(int j = 0; j <= 9; j++)
        ans = (ans + dp[N][j]) % MOD;
}

void printAns()
{
    cout << ans << "\n";
}