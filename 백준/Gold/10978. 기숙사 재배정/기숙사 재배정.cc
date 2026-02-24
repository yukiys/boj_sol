#include <iostream>

using namespace std;

int T, N;
long long dp[21];

int main()
{
    cin >> T;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i<= 20; i++)
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);

    while(T--)
    {
        cin >> N;

        cout << dp[N] << "\n";
    }
}