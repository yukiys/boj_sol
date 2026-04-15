#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s, e;
bool start;
long long ans;
vector<pair<int, int>> pos;

void init();
void solve();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
    }

    sort(pos.begin(), pos.end());
}

void solve()
{
    for(auto [x, y] : pos)
    {
        if(!start)
        {
            s = x;
            e = y;
            start = true;
            continue;
        }

        if(x <= e)
            e = max(e, y);
        else
        {
            ans += (e - s);
            s = x;
            e = y;
        }
    }

    ans += (e - s);
}

void printAns()
{
    cout << ans << "\n";
}