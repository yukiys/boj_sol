#include <iostream>

const long long MOD=1000000007;

using namespace std;

int N;
long long dp[100001];

int main()
{
    cin >> N;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    for(long long i = 3; i <= N; i++)
    {
        dp[i] = (i-1) * ((dp[i-1] + dp[i-2]) % MOD);
        dp[i] %= MOD;
    }

    long long factorial = 1;
    for(int i = 2; i <= N; i++)
        factorial = (factorial * i) % MOD;

    cout << factorial * dp[N] % MOD << "\n";
}