#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K, ans;
int stockPrice[10000];
vector<int> LIS;

void init();
void solve();
void printAns(int);

int main()
{
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        solve();
        printAns(t);
    }
}

void init()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> stockPrice[i];

    LIS.clear();
}

void solve()
{
    for(int i = 0; i < N; i++)
    {
        int price = stockPrice[i];
        if(LIS.empty() or LIS.back() < price)
            LIS.push_back(price);
        else
            *lower_bound(LIS.begin(), LIS.end(), price) = price;
    }

    if(LIS.size() < K)
        ans = 0;
    else
        ans = 1;
}

void printAns(int t)
{
    cout << "Case #" << t << "\n";
    cout << ans << "\n";
}