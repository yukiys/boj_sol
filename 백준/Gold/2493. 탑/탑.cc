#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> towers;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int h;
        cin >> h;

        while(!towers.empty() and towers.top().first < h)
            towers.pop();

        if(towers.empty())
            cout <<0 << " ";
        else
            cout << towers.top().second << " ";

        towers.push({h, i});
    }
}