#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> works;

void init();
void solve();

int main()
{
    init();
    solve();
}

void init()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int T, S;
        cin >> T >> S;
        works.push_back({S, T});
    }

    sort(works.rbegin(), works.rend());
}

void solve()
{
    int cur = 1e9;

    for(auto [S, T] : works)
        cur = min(cur, S) - T;

    if(cur < 0)
        cout << -1 << "\n";
    else
        cout << cur << "\n";
}