#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long ans = 1e17;
long long A[100001];

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
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);
}

void solve()
{
    int left = 0, right = 0;

    while(right < N)
    {
        long long diff = A[right] - A[left];

        if(diff >= M)
        {
            ans = min(ans, diff);
            left++;
        }
        else if(diff < M)
            right++;
    }
}

void printAns()
{
    cout << ans << "\n";
}