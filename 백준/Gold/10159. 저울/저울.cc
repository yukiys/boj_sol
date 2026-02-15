#include <iostream>

using namespace std;

constexpr int MAX_N = 100;

int N, M;
int ret[MAX_N+1];
bool heavier[MAX_N+1][MAX_N+1];

void init()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        ret[i] = N-1;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        heavier[a][b] = true;
    }
}

void floyd()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            if(!heavier[i][k])
                continue;

            for(int j = 1; j <= N; j++)
                if(heavier[k][j])
                    heavier[i][j] = true;
        }
    }
}

void solve()
{
    floyd();

    for(int i = 1; i <= N; i++)
    {
        for(int j = i+1; j <= N; j++)
        {
            if(heavier[i][j] or heavier[j][i])
            {
                ret[i]--;
                ret[j]--;
            }
        }
    }
}

void printRet()
{
    for(int i = 1; i <= N; i++)
        cout << ret[i] << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
    printRet();
}