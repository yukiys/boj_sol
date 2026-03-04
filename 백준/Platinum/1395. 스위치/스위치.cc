#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> Tree;
vector<int> Lazy;

void init();
void solve();
void Propagate(int, int, int);
long long Sum(int, int, int, int, int);
void Update(int, int, int, int, int);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
}

void init()
{
    cin >> N >> M;

    Tree.assign(4 * N + 5, 0);
    Lazy.assign(4 * N + 5, 0);
}

void solve()
{
    while(M--)
    {
        int O, S, T;
        cin >> O >> S >> T;
        if(S > T)
            swap(S, T);

        if(O == 0)
            Update(1, 1, N, S, T);
        else
            cout << Sum(1, 1, N, S, T) << "\n";
    }
}

void Propagate(int node, int l, int r)
{
    if(Lazy[node] == 0)
        return;

    if(l != r)
    {
        int mid = (l + r) / 2;
        
        Tree[node * 2] = (mid - l + 1) - Tree[node * 2];
        Lazy[node * 2] ^= 1;

        Tree[node * 2 + 1] = (r - mid) - Tree[node * 2 + 1];
        Lazy[node * 2 + 1] ^= 1;
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

void Update(int node, int l, int r, int start, int end)
{
    if(end < l or start > r)
        return;
    if(start <= l and r <= end)
    {
        Tree[node] = (r - l + 1) - Tree[node];
        Lazy[node] ^= 1;
        return;
    }
    
    Propagate(node, l, r);

    int mid = (l + r) / 2;
    Update(node * 2, l, mid, start, end);
    Update(node * 2 + 1, mid + 1, r, start, end);
    Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}