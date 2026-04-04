#include <iostream>

using namespace std;

int N, K, ans;
int W1[101], V1[101];
int W2[101], V2[101];
int dp[101][100001];

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
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> W1[i] >> V1[i] >> W2[i] >> V2[i];

    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= K; j++)
            dp[i][j] = -1;
}

void solve()
{
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            if(j - W1[i] >= 0 and dp[i - 1][j - W1[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W1[i]] + V1[i]);
            if(j - W2[i] >= 0 and dp[i - 1][j - W2[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W2[i]] + V2[i]);            
        }
    }

    for(int k = 1; k <= K; k++)
        ans = max(ans, dp[N][k]);
}

void printAns()
{
    cout << ans << "\n";
}