#include <iostream>

using namespace std;

int N, M, K;
int A[301][301];
int S[301][301];

void init();
void solve();

int main()
{
    init();
    solve();
}

void init()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> A[i][j];
}

void solve()
{
    for(int i = 1; i <= N; i++)
        S[i][1] = A[i][1] + S[i - 1][1];
    for(int j = 1;j <= M; j++)
        S[1][j] = A[1][j] + S[1][j - 1];

    for(int i = 2; i <= N; i++)
        for(int j = 2; j <= M; j++)
            S[i][j] = A[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];

    cin >> K;
    for(int k = 0; k < K; k++)
    {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        int ans = S[x][y];
        ans -= (S[x][j - 1] + S[i - 1][y]);
        ans += S[i - 1][j - 1];

        cout << ans << "\n";
    }
}