#include <iostream>

using namespace std;

int N, M, ret;
bool isShorter[501][501];

void init()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        isShorter[a][b] = true;
    }
}

void floyd(){
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            if(!isShorter[i][k])
                continue;

            for(int j = 1; j <= N; j++)
            {
                if(isShorter[k][j])
                    isShorter[i][j] = true;
            }
        }
    }
}

void solve()
{
    floyd();

    for(int i = 1; i <= N; i++)
    {
        int shorter = 0, taller = 0;

        for(int j = 1; j <= N; j++)
        {
            if(isShorter[j][i])
                shorter++;
            if(isShorter[i][j])
                taller++;
        }

        if(shorter + taller == N-1)
            ret++;
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}