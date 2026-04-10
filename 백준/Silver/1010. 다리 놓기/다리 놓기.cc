#include <iostream>

using namespace std;

int T;
int N, M;
long long C[31][31];

void init();
void solve();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
}

void init()
{
    for(int i = 0; i <= 30; i++)
        C[i][0] = C[i][i] = 1;

    for(int i = 1; i <= 30; i++)
        for(int j = 1; j < i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
}

void solve()
{
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        cout << C[M][N] << "\n";
    }
}