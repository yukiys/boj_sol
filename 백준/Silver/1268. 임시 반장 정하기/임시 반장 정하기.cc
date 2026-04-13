#include <iostream>

using namespace std;

int N, M, ans = 1;
int A[1001][1001];
int score[1001];

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
    for(int i = 1; i <= N; i++)
        for(int grade = 1; grade <= 5; grade++)
            cin >> A[i][grade];
}

void solve()
{
    for(int i = 1; i <= N; i++)
    {
        for(int k = i + 1; k <= N; k++)
        {
            for(int grade = 1; grade <= 5; grade++)
            {
                if(A[i][grade] == A[k][grade])
                {
                    score[i]++;
                    score[k]++;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(M < score[i])
        {
            M = score[i];
            ans = i;
        }
    }
}

void printAns()
{
    cout << ans << "\n";
}