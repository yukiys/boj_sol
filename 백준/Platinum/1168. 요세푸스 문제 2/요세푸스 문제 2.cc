#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

int N, K;
vector<long long> BITree;

void init();
void solve();
void Update(int, long long);
int Kth(long long);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
}

void init()
{
    cin >> N >> K;

    BITree.assign(MAX + 1, 0);
    for(int i = 1; i <= N; i++)
        Update(i, 1);
}

void solve()
{
    int pos = 0;
    cout << "<";
    for(int i = 0; i < N; i++)
    {
        int mod = N - i;

        pos = (pos + K - 1) % mod;

        int idx = Kth(pos + 1);
        Update(idx, -1);

        cout << idx;
        if(i != N - 1)
            cout << ", ";
    }
    cout << ">";
}

void Update(int idx, long long value)
{
    for(; idx <= MAX; idx += (idx & -idx))
        BITree[idx] += value;
}

int Kth(long long k)
{
    int idx = 0;

    int bit = 1;
    while((bit << 1) <= MAX)
        bit <<= 1;

    for(; bit > 0; bit >>= 1)
    {
        int next = idx + bit;
        if(next <= MAX && BITree[next] < k)
        {
            k -= BITree[next];
            idx = next;
        }
    }

    return idx + 1;
}