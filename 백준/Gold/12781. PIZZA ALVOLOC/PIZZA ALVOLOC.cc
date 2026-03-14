#include <iostream>

#define Pos pair<int, int>

using namespace std;

Pos p[4];

void init();
void solve();
int ccw(Pos, Pos, Pos);
bool isCrossing(Pos, Pos, Pos, Pos);

int main()
{
    init();
    solve();
}

void init()
{
    for(int i = 0; i < 4; i++)
        cin >> p[i].first >> p[i].second;
}

void solve()
{
    if(isCrossing(p[0], p[1], p[2], p[3]))
        cout<<1<<"\n";
    else
        cout<<0<<"\n";
}

int ccw(Pos p0, Pos p1, Pos p2)
{
    long long cross = (long long)(p1.first - p0.first) * (p2.second - p0.second);
    cross -= (long long)(p2.first - p0.first) * (p1.second - p0.second);

    if(cross>0)
        return 1;
    else if(cross<0)
        return -1;
    else
        return 0;
}

bool isCrossing(Pos p0, Pos p1, Pos p2, Pos p3)
{
    int p01 = ccw(p0, p1, p2) * ccw(p0, p1, p3);
    int p23 = ccw(p2, p3, p0) * ccw(p2, p3, p1);

    if(p01 < 0 and p23 < 0)
        return true;
    return false;
}