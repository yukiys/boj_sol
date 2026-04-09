#include <iostream>
#include <algorithm>

using namespace std;

int x, n;
int l[1000001];
int ans1, ans2;

void init();
void solve();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while(cin >> x)
    {
        init();
        solve();
        printAns();
    }
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i];

    sort(l, l + n);

    ans1 = ans2 = -1;
}

void solve()
{
    int left = 0, right = n - 1;

    while(left < right)
    {
        int Left = l[left];
        int Right = l[right];

        if(Left + Right < x * 10000000)
            left++;
        else if(Left + Right > x * 10000000)
            right--;
        else
        {
            ans1 = Left;
            ans2 = Right;
            break;
        }
    }
}

void printAns()
{
    if(ans1 != -1)
        cout << "yes" << " " << ans1 << " " << ans2 << "\n";
    else
        cout << "danger" << "\n";
}