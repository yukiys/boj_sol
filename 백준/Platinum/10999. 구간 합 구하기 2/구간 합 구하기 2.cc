#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<long long> A;
vector<long long> Tree, Lazy;

void init();
long long MakeSegTree(int, int, int);
void solve();
void Propagate(int, int, int);
long long Sum(int, int, int, int, int);
void Update(int, int, int, int, int, long long);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
}

void init()
{
    cin >> N >> M >> K;

    A.assign(N + 1, 0);
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    Tree.assign(4 * N + 5, 0);
    Lazy.assign(4 * N + 5, 0);

    MakeSegTree(1, 1, N);
}

long long MakeSegTree(int node, int l, int r)
{
    if(l == r)
        return Tree[node] = A[l];

    int mid = (l + r) / 2;
    long long L = MakeSegTree(node * 2, l, mid);
    long long R = MakeSegTree(node * 2 + 1, mid + 1, r);
    return Tree[node] = L + R;
}

void solve()
{
    int Q = M + K;

    while(Q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int b, c;
            long long d;
            cin >> b >> c >> d;

            if(b > c)
                swap(b, c);

            Update(1, 1, N, b, c, d);
        }
        else
        {
            int b, c;
            cin >> b >> c;

            if(b > c)
                swap(b, c);

            cout << Sum(1, 1, N, b, c) << "\n";
        }
    }
}

void Propagate(int node, int l, int r)
{
    if(Lazy[node] == 0)
        return;

    if(l != r)
    {
        long long val = Lazy[node];
        int mid = (l + r) / 2;
        
        Tree[node * 2] += val * (mid - l + 1);
        Lazy[node * 2] += val;

        Tree[node * 2 + 1] += val * (r - mid);
        Lazy[node * 2 + 1] += val;
    }
    Lazy[node] = 0;
}

long long Sum(int node, int l, int r, int start, int end)
{
    if(end < l or start > r)
        return 0;
    if(start <= l and r <= end)
        return Tree[node];

    Propagate(node, l, r);

    int mid = (l + r) / 2;
    long long L = Sum(node * 2, l, mid, start, end);
    long long R = Sum(node * 2 + 1, mid + 1, r, start, end);
    return L + R;
}

void Update(int node, int l, int r, int start, int end, long long val)
{
    if(end < l or start > r)
        return;
    if(start <= l and r <= end)
    {
        Tree[node] += val * (r - l + 1);
        Lazy[node] += val;
        return;
    }
    
    Propagate(node, l, r);

    int mid = (l + r) / 2;
    Update(node * 2, l, mid, start, end, val);
    Update(node * 2 + 1, mid + 1, r, start, end, val);
    Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}