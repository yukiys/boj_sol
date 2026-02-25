#include <iostream>

const long long MOD = 1000000000;

using namespace std;

int N;
long long dp[1000001];

int main()
{
    cin >> N;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i<= N; i++)
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % MOD;

    cout << dp[N] << "\n";
}