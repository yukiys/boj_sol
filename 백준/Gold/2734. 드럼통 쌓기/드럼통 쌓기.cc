#include <iostream>
#include <cmath>

#define pos pair<double, double>

using namespace std;

int T, N;
pos ans;
pos drums[10];

void init();
void solve();
pos getCenter(pos, pos);
void printAns();

int main()
{
    cin >> T;
    while(T--)
    {
        init();
        solve();
        printAns();
    }
}

void init()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        double x;
        cin >> x;
        drums[i] = {x, 1};
    }
}

void solve()
{
    int Size = N;
    while(Size > 1)
    {
        pos temp[10];

        for(int i = 0; i+1 < Size; i++)
            temp[i] = getCenter(drums[i], drums[i+1]);

        Size--;
        for(int i = 0; i < Size; i++)
            drums[i] = temp[i];
    }

    ans = drums[0];
}
pos getCenter(pos a, pos b)
{
    double dx = b.first - a.first;
    double dy = b.second - a.second;
    double dist = hypot(dx, dy);

    double mx = (b.first + a.first) / 2;
    double my = (b.second + a.second) / 2;

    double height = sqrt(4 - pow(dist,2) / 4);

    double xDirection = -dy / dist;
    double yDirection = dx / dist;

    pos p1 = {mx + height * xDirection, my + height * yDirection};
    pos p2 = {mx - height * xDirection, my - height * yDirection};

    return p1.second > p2.second ? p1 : p2;
}

void printAns()
{
    cout << fixed;
    cout.precision(4);
    cout << ans.first << " " << ans.second << "\n";
}