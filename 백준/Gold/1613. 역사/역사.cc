#include <iostream>

using namespace std;

int N, K, S;
bool before[401][401];

void init()
{
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;

        before[a][b] = true;
    }

    cin >> S;
}

void floyd(){
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            if(!before[i][k])
                continue;

            for(int j = 1; j <= N; j++)
                if(before[k][j])
                    before[i][j] = true;
        }
    }
}

void solve()
{
    floyd();

    for(int i = 0; i < S; i++)
    {
        int a, b;
        cin >> a >> b;

        if(before[a][b])
            cout << "-1" << "\n";
        else if(before[b][a])
            cout << "1" << "\n";
        else
            cout << "0" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}