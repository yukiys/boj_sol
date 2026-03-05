#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int N;
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
    cin >> N;
    BITree.assign(MAX + 1, 0);
}

void solve()
{
    while(N--)
    {
        int A;
        cin >> A;

        if(A == 1)
        {
            long long B;
            cin >> B;

            int taste = Kth(B);
            cout << taste << "\n";
            Update(taste, -1);
        }
        else
        {
            int B;
            long long C;
            cin >> B >> C;

            Update(B, C);
        }
    }
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