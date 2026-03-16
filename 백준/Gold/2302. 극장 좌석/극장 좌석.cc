#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = 1;
vector<int> fibo;
vector<int> VIP;

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

    fibo.assign(N + 1, 0);
    VIP.assign(M, 0);
    
    for(int i = 0; i < M; i++)
        cin >> VIP[i];

    fibo[0] = 1;
    fibo[1] = 1;
    for(int i = 2; i <= N; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
}

void solve()
{
    int prev = 0;
    for(int vip : VIP)
    {
        int len = vip - prev - 1;
        ans *= fibo[len];
        prev = vip;
    }

    ans *= fibo[N - prev];
}

void printAns()
{
    cout << ans << "\n";
}