#include <iostream>
#include <vector>

using namespace std;

int N, M, K, mst;
int parent[1001];
vector<pair<int, pair<int, int>>> Graph;

void init();
void solve();
int Find(int);
void Union(int, int);
bool Kruskal(int);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}

void init()
{
    cin >> N >> M >> K;

    for(int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph.push_back({i,{x,y}});
    }
}

void solve(){
    bool isFailed = false;
    for(int k = 0; k < K; k++)
    {
        if(isFailed)
        {
            cout << 0 << " ";
            continue;
        }

        bool ok = Kruskal(k);

        if(!ok)
        {
            isFailed = true;
            cout << 0 << " ";
        }
        else
            cout << mst << " ";
    }
}

int Find(int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
        return;

    if(a < b)
            parent[b] = a;
    else
        parent[a] = b;
}

bool Kruskal(int k)
{
    int cnt = 0;
    mst = 0;

    for(int i = 1; i <= N; i++)
        parent[i]=i;

    for(int i = k; i < M; i++)
    {
        int cost = Graph[i].first;
        int now = Graph[i].second.first;
        int next = Graph[i].second.second;

        if(Find(now) == Find(next))
            continue;

        Union(now, next);
        mst += cost;
        cnt++;

        if(cnt == N-1)
            return true;
    }
    return false;
}