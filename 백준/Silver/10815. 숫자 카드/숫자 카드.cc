#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> S;

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
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        S.insert(x);
    }
}

void solve()
{
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        cout << (S.count(x) ? 1 : 0) << " ";
    }
    cout << "\n";
}