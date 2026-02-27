#include <iostream>

using namespace std;

int N;
int sequence[5000];
int dp[5000][5000];

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
    for(int i = 0; i < N; i++)
        cin >> sequence[i];
}

void solve()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dp[i][j] = 0;

    for(int len = 2; len <=N; len++)
    {
        for(int l = 0; l + len <= N; l++)
        {
            int r = l + len - 1;

            if(sequence[l] == sequence[r])
                dp[l][r] = dp[l+1][r-1];
            else
                dp[l][r] = 1 + min(dp[l+1][r], dp[l][r-1]);
        }
    }
}

void printAns()
{
    cout << dp[0][N-1] << "\n";
}