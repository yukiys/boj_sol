#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S, ans;
vector<pair<int, int>> Left, Right;
int d;

void init();
void solve();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N >> K >> S;
    for(int i = 0; i < N; i++)
    {
        int pos, num;
        cin >> pos >> num;
        if(pos < S)
            Left.push_back({S - pos, num});
        else if(pos > S)
            Right.push_back({pos - S, num});
    }

    sort(Left.begin(), Left.end());
    sort(Right.begin(), Right.end());
}

void solve()
{
    int emptySeat = K;
    bool isOn = false;
    while(!Left.empty())
    {
        int dist = Left.back().first;
        int num = Left.back().second;
        Left.pop_back();

        if(!isOn)
        {
            d = dist;
            isOn = true;
        }

        if(emptySeat >= num)
        {
            emptySeat -= num;
            if(emptySeat == 0)
            {
                ans += 2 * d;
                emptySeat = K;
                isOn = false;
            }
        }
        else
        {
            num -= emptySeat;
            ans += 2 * d;
            emptySeat = K;
            isOn = false;
            Left.push_back({dist, num});
        }
    }
    if(isOn)
        ans += 2 * d;
    emptySeat = K;
    isOn = false;

    while(!Right.empty())
    {
        int dist = Right.back().first;
        int num = Right.back().second;
        Right.pop_back();

        if(!isOn)
        {
            d = dist;
            isOn = true;
        }
        if(emptySeat >= num)
        {
            emptySeat -= num;
            if(emptySeat == 0)
            {
                ans += 2 * d;
                emptySeat = K;
                isOn = false;
            }
        }
        else
        {
            num -= emptySeat;
            ans += 2 * d;
            emptySeat = K;
            isOn = false;
            Right.push_back({dist, num});
        }
    }
    if(isOn)
        ans += 2 * d;
}

void printAns()
{
    cout << ans << "\n";
}